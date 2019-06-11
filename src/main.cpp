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
    if(graph.insert(Edge(v1,v2))){
        std::cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

    v1=3, v2=4; 
    if(graph.insert(Edge(v1,v2))){
        std::cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

    v1=2, v2=2; 
    if(graph.insert(Edge(v1,v2))){
        std::cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

    graph.printAdjacencyMatrix();
    

    return 0;
}

#endif