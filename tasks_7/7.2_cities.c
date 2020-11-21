#include "../library/dataStructures/Graph/graph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 1000000000;

bool isNumber(char sign)
{
    return sign >= '0' && sign <= '9';
}

int scanNumber(FILE* file)
{
    char* number = (char*)malloc(sizeof(char));
    int index = 0;

    while (isNumber((number[index] = fgetc(file)))) {
        ++index;
        number = realloc(number, (index + 1) * sizeof(char));
    }
    number[index] = '\0';
    int vertexCount = atoi(number);
    free(number);
    return vertexCount;
}

void scanEdges(FILE* file, int edgesCount, Edge** edges)
{
    for (int i = 0; i < edgesCount; ++i) {
        int firstVertex = scanNumber(file);
        int secondVertex = scanNumber(file);
        int length = scanNumber(file);
        edges[i] = createEdge(firstVertex - 1, secondVertex - 1, length, 0);
    }
}

void scanStates(FILE* file, int stateCount, int** states, int* usedCities, int citiesCount)
{
    for (int i = 0; i < stateCount; ++i) {
        states[i] = (int*)malloc(citiesCount * sizeof(int));
        memset(states[i], -1, citiesCount * sizeof(int));
        states[i][0] = scanNumber(file) - 1;
        usedCities[i] = states[i][0];
    }
}

void freeStates(int** states, int stateCount)
{
    for (int i = 0; i < stateCount; ++i) {
        free(states[i]);
    }
    free(states);
}

bool isUsed(int* usedCities, int usedCitiesCount, int city)
{
    for (int i = 0; i < usedCitiesCount; ++i) {
        if (usedCities[i] == city) {
            return 1;
        }
    }
    return 0;
}

bool addCityToState(int** states, Graph* graph, int stateIndex, int citiesCount, int* usedCities, int usedCitiesCount)
{
    int minLength = MAX_LENGTH;
    int city = -1;
    for (int i = 0; i < citiesCount; ++i) {
        if (states[stateIndex][i] == -1) {
            break;
        }
        for (int j = 0; j < citiesCount; ++j) {
            int currentLength = getMatrixValue(graph, states[stateIndex][i], j);
            if (j != i && !isUsed(usedCities, usedCitiesCount, j) && currentLength != 0 && currentLength < minLength) {
                minLength = currentLength;
                city = j;
            }
        }
    }
    if (city == -1) {
        return false;
    }
    int i = 0;
    while (states[stateIndex][i] != -1) {
        ++i;
    }
    states[stateIndex][i] = city;
    usedCities[usedCitiesCount] = city;
    return true;
}

void printStates(int** states, int stateCount, int citiesCount)
{
    for (int i = 0; i < stateCount; ++i) {
        printf("State number %d\nCities: ", i + 1);
        for (int j = 0; j < citiesCount; ++j) {
            if (states[i][j] == -1) {
                break;
            }
            printf("%d ", states[i][j] + 1);
        }
        printf("\n");
    }
}

int main()
{
    FILE* file = fopen("7.2_testFile.txt", "r");

    int citiesCount = scanNumber(file);
    int edgesCount = scanNumber(file);

    Edge** edges = (Edge**)malloc(edgesCount * sizeof(Edge*));
    scanEdges(file, edgesCount, edges);

    int stateCount = scanNumber(file);
    int** states = (int**)malloc(stateCount * sizeof(int*));

    int* usedCities = (int*)malloc(citiesCount * sizeof(int));
    memset(usedCities, -1, citiesCount * sizeof(int));
    scanStates(file, stateCount, states, usedCities, citiesCount);

    fclose(file);

    Graph* graph = createGraph(edgesCount, citiesCount, edges);

    int usedCitiesCount = stateCount;
    while (usedCitiesCount != citiesCount) {
        for (int i = 0; i < stateCount; ++i) {
            if (addCityToState(states, graph, i, citiesCount, usedCities, usedCitiesCount)) {
                ++usedCitiesCount;
            }
        }
    }

    printStates(states, stateCount, citiesCount);

    free(usedCities);
    freeStates(states, stateCount);
    removeEdges(edges, edgesCount);
    removeGraph(graph);

    return 0;
}
