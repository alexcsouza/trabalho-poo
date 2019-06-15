#ifndef MAIN
#define MAIN

#include <iostream>
#include "Graph.cpp"
#include "Edge.cpp"

#define NUMERO_DE_VERTICES 5

void inserirEdges(Graph &graph);
void removerEdges(Graph &graph);

int main(void) {
    int numeroDeVertices = NUMERO_DE_VERTICES;

    Graph graph = Graph(numeroDeVertices);
    inserirEdges(graph);    
    removerEdges(graph);
    graph.printAdjacencyMatrix();

    graph.complete();
    graph.printAdjacencyMatrix();
    


    return 0;
}

void inserirEdges(Graph &graph){

    int v1=0, v2=3; 
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

    v1=1, v2=4; 
    if(graph.insert(Edge(v1,v2))){
        std::cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

    v1=1, v2=2; 
    if(graph.insert(Edge(v1,v2))){
        std::cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

    v1=4, v2=3; 
    if(graph.insert(Edge(v1,v2))){
        std::cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

    v1=4, v2=3; 
    if(graph.insert(Edge(v1,v2))){
        std::cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

}

void removerEdges(Graph &graph){

    int v1=3, v2=4; 
    if(graph.remove(Edge(v1,v2))){
        std::cout << "Aresta removida com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível remover a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

    v1=4, v2=2; 
    if(graph.remove(Edge(v1,v2))){
        std::cout << "Aresta removida com sucesso (" << v1 << ", " << v2 << ")." << std::endl;
    }else{
        std::cout << "Não foi possível remover a aresta (" << v1 << ", " << v2 << ")." << std::endl;
    }

}

#endif