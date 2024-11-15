//
// Created by Claudio Delgado on 2024-11-11.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <string>
#include <list>
#include <set>
#include "Edge.h"

template <typename T>
class Graph {
public:
    void addVertex(const T& vertex) {
        adjacencyList[vertex] = std::vector<Edge>();
    }

    void addEdge(const T& source, const T& destination, int weight) {
        adjacencyList[source].emplace_back(destination, weight);
    }

    std::list<T> shortestPath(const T& source, const T& destination);

private:
    std::map<T, std::vector<Edge>> adjacencyList;
};

#endif // GRAPH_H
