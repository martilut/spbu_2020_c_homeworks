#include "graph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge {
    int start;
    int end;
    int weight;
    bool oriented;
};

struct Graph {
    int** matrix;
    int countVertex;
    int countEdges;
};

Edge* createEdge(int start, int end, int weight, bool oriented)
{
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->start = start;
    edge->end = end;
    edge->weight = weight;
    edge->oriented = oriented;
    return edge;
}

Edge** createEdges(int countEdges)
{
    Edge** edges = (Edge**)malloc(countEdges * sizeof(Edge*));
    memset(edges, NULL, countEdges * sizeof(Edge*));
    return edges;
}

void removeEdges(Edge** edges, int countEdges)
{
    for (int i = 0; i < countEdges; ++i) {
        if (edges[i] != NULL) {
            free(edges[i]);
        }
    }
    free(edges);
}

Graph* createGraph(int countEdges, int countVertex, Edge** edges)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->countEdges = countEdges;
    graph->countVertex = countVertex;
    graph->matrix = (int**)malloc(countVertex * sizeof(int*));
    for (int i = 0; i < countVertex; ++i) {
        graph->matrix[i] = (int*)malloc(countVertex * sizeof(int));
        memset(graph->matrix[i], 0, countVertex * sizeof(int));
    }
    for (int i = 0; i < countEdges; ++i) {
        if (edges[i] == NULL) {
            continue;
        }
        Edge* currentEdge = edges[i];
        graph->matrix[currentEdge->start][currentEdge->end] = currentEdge->weight;
        if (!currentEdge->oriented) {
            graph->matrix[currentEdge->end][currentEdge->start] = currentEdge->weight;
        }
    }
    return graph;
}

void simplifiedDFS(Graph* graph, int currentVertex, int startVertex) // works only for graphs with no cycles
{
    int emptyCellCount = 0;
    for (int i = 0; i < graph->countVertex; ++i) {
        if (graph->matrix[i][currentVertex] != 0) {
            printf("%d passed variant number %d\n", i + 1, startVertex + 1);
            simplifiedDFS(graph, i, startVertex);
        } else {
            ++emptyCellCount;
        }
    }
    if (emptyCellCount == graph->countVertex - 1) {
        return;
    }
}

int getMatrixValue(Graph* graph, int i, int j)
{
    return graph->matrix[i][j];
}

void removeGraph(Graph* graph)
{
    for (int i = 0; i < graph->countVertex; ++i) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}