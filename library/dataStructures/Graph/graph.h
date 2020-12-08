#ifndef SPBU_2020_C_HOMEWORKS_GRAPH_H
#define SPBU_2020_C_HOMEWORKS_GRAPH_H
#include <stdbool.h>

typedef struct Edge Edge;
typedef struct Graph Graph;

Edge* createEdge(int start, int end, int weight, bool oriented);
Edge** createEdges(int countEdges);
void removeEdges(Edge** edges, int countEdges);
Graph* createGraph(int countEdges, int countVertex, Edge** edges);
void removeGraph(Graph* graph);
void simplifiedDFS(Graph* graph, int currentVertex, int startVertex);
bool depthFirstSearch(Graph* graph, int currentVertex, int* vertexState);

#endif //SPBU_2020_C_HOMEWORKS_GRAPH_H
