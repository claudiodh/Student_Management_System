//
// Created by Claudio Delgado on 2024-11-11.
//
#include "Graph.h"
#include <queue>
#include <unordered_map>

template <typename T>
std::list<T> Graph<T>::shortestPath(const T& source, const T& destination) {
    std::unordered_map<T, int> distances;
    std::unordered_map<T, T> previous;
    std::set<std::pair<int, T>> nodes;

    for (const auto& pair : adjacencyList) {
        distances[pair.first] = (pair.first == source) ? 0 : INT_MAX;
        nodes.insert({distances[pair.first], pair.first});
    }

    while (!nodes.empty()) {
        T smallest = nodes.begin()->second;
        nodes.erase(nodes.begin());

        if (smallest == destination) {
            std::list<T> path;
            while (previous.find(smallest) != previous.end()) {
                path.push_front(smallest);
                smallest = previous[smallest];
            }
            path.push_front(source);
            return path;
        }

        if (distances[smallest] == INT_MAX) break;

        for (const auto& edge : adjacencyList[smallest]) {
            int alt = distances[smallest] + edge.getWeight();
            if (alt < distances[edge.getDestination()]) {
                nodes.erase({distances[edge.getDestination()], edge.getDestination()});
                distances[edge.getDestination()] = alt;
                previous[edge.getDestination()] = smallest;
                nodes.insert({alt, edge.getDestination()});
            }
        }
    }

    return std::list<T>();
}

// Explicit template instantiation
template class Graph<std::string>;