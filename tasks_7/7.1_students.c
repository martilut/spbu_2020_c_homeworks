#include "../library/dataStructures/Graph/graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int countVertex = 0;
    int countPairs = 0;

    printf("Enter the amount of students and the amount of pairs:\n");
    scanf("%d %d", &countVertex, &countPairs);

    Edge** edges = createEdges(countPairs);

    int lazyStudentsCount = 0;
    int* lazyStudents = (int*)malloc(countVertex * sizeof(int));
    memset(lazyStudents, 0, countVertex * sizeof(int));

    printf("Enter the pairs:\n");
    for (int i = 0; i < countPairs; ++i) {
        int start = 0;
        int end = 0;
        scanf("%d %d", &start, &end);
        if (end != -1) {
            edges[i] = createEdge(start - 1, end - 1, 1, 1);
        } else {
            lazyStudents[lazyStudentsCount] = start;
            ++lazyStudentsCount;
        }
    }

    Graph* graph = createGraph(countPairs, countVertex, edges);

    for (int i = 0; i < 3; ++i) {
        printf("%d passed his own variant\n", i + 1);
        simplifiedDFS(graph, i, i);
    }
    for (int i = 0; i < lazyStudentsCount; ++i) {
        printf("%d didn't pass anything\n", lazyStudents[i]);
    }

    free(lazyStudents);
    removeEdges(edges, countPairs);
    removeGraph(graph);

    return 0;
}