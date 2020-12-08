#include "../library/dataStructures/Graph/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** scanMatrix(int vertexCount, int edgesCount)
{
    int** matrix = (int**)malloc(vertexCount * sizeof(int*));
    for (int i = 0; i < vertexCount; ++i) {
        matrix[i] = (int*)malloc(edgesCount * sizeof(int));
        memset(matrix[i], 0, edgesCount * sizeof(int));
        for (int j = 0; j < edgesCount; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

Graph* fillGraph(int** matrix, Edge** edges, int vertexCount, int edgesCount)
{
    for (int j = 0; j < edgesCount; ++j) {
        int startVertex = -1;
        int endVertex = -1;
        for (int i = 0; i < vertexCount; ++i) {
            if (matrix[i][j] == 1) {
                startVertex = i;
            }
            if (matrix[i][j] == -1) {
                endVertex = i;
            }
            if (matrix[i][j] == 2) {
                startVertex = endVertex = i;
            }
        }
        if (startVertex != -1 && endVertex != -1) {
            edges[j] = createEdge(startVertex, endVertex, 1, true);
        }
    }
    Graph* graph = createGraph(edgesCount, vertexCount, edges);
    return graph;
}

void printUnvisitedVertices(int* vertexState, int vertexCount)
{
    int vertices = 0;
    for (int i = 0; i < vertexCount; ++i) {
        if (vertexState[vertexCount] == 0) {
            printf("%d ", i + 1);
            ++vertices;
        }
    }
    if (vertices == 0) {
        printf("All vertices can be visited");
    }
}

void removeMatrix(int** matrix, int vertexCount)
{
    for (int i = 0; i < vertexCount; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int vertexCount = 0;
    int edgesCount = 0;
    int startVertex = 0;
    Edge** edges = createEdges(edgesCount);

    printf("Enter the amount of vertices and edges:\n");
    scanf("%d %d", &vertexCount, &edgesCount);

    printf("Enter the start vertex:\n");
    scanf("%d", &startVertex);
    --startVertex;

    printf("Enter your matrix:\n");
    int** matrix = scanMatrix(vertexCount, edgesCount);
    Graph* graph = fillGraph(matrix, edges, vertexCount, edgesCount);

    int* vertexState = (int*)malloc(vertexCount * sizeof(int));
    memset(vertexState, 0, vertexCount * sizeof(int));

    depthFirstSearch(graph, startVertex, vertexState);
    printUnvisitedVertices(vertexState, vertexCount);

    removeEdges(edges, edgesCount);
    removeGraph(graph);
    removeMatrix(matrix, vertexCount);
    free(vertexState);

    return 0;
}
