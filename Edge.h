//
// Created by Claudio Delgado on 2024-11-11.
//
#ifndef EDGE_H
#define EDGE_H

#include <string>

class Edge {
public:
    Edge(const std::string& destination, int weight)
        : destination(destination), weight(weight) {}

    std::string getDestination() const { return destination; }
    int getWeight() const { return weight; }

private:
    std::string destination;
    int weight;
};

#endif // EDGE_H