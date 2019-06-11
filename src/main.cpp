#ifndef MAIN
#define MAIN

#include <iostream>
#include "Graph.cpp"
#include "Edge.cpp"

int main(void) {
    std::cout << "teste" << std::endl;
    int numeroDeVertices = 5;
    Graph graph = Graph(numeroDeVertices);
    int v1=0, v2=4; 
    graph.insert(Edge(v1,v2));

    return 0;
}

#endif