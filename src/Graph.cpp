#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

/**
 * Classe que representa um grafo referente à tarefa:
 * "Crie uma classe para representar o conceito de
 * grafo (classe Graph), com vértices representados por números inteiros (índices dos
 * vértices). A classe Graph utilizará uma representação interna por matriz de adjacência."
 * 
 */

int Graph::totalEdges = 0;

Graph::Graph(int &nv) :
    numeroDeVertices(nv){
    adjacencyMatrix = new int*[numeroDeVertices];
    for(int i = 0 ; i < numeroDeVertices ; i++){
        adjacencyMatrix[i] = new int[numeroDeVertices];
    }
}

bool Graph::insert(const Edge &edge){
    if( edge.getV1() >= numeroDeVertices
        || edge.getV1() >= numeroDeVertices
        || edge.getV1() == edge.getV2()  
        || adjacencyMatrix[edge.getV1()][edge.getV2()] == 1){
        return false;
    }
    adjacencyMatrix[edge.getV1()][edge.getV2()] = 1;
    Graph::totalEdges++;
    return true;
}
        
bool Graph::remove(const Edge &edge){
    if( edge.getV1() >= numeroDeVertices
        || edge.getV1() >= numeroDeVertices
        || edge.getV1() == edge.getV2()  
        || adjacencyMatrix[edge.getV1(), edge.getV2()] == 0){
        return false;
    }
    adjacencyMatrix[edge.getV1()][edge.getV2()] = 0;
    Graph::totalEdges--;
    return true;
}

int Graph::getTotalEdges(){
    return Graph::totalEdges;
};

bool Graph::edge(const Edge &edge) const{
    return false;
};

bool Graph::isComplete(){
    return false;
};
        
void Graph::complete(){

};

void Graph::bfs(const Vertex &edge) const{

};
  
void Graph::dfs(const Vertex &edge) const{

};

/**
 * Método útil para impressão da matriz de adjacência em tela.
 */
void Graph::printAdjacencyMatrix() const{
    
    std::cout << std::endl << std::endl;
    std::cout << "   ";
    for(int j = 0 ; j < numeroDeVertices ; j++){
        std::cout << j << " ";
    }
    
    std::cout << std::endl;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        std::cout << std::endl;
        std::cout << i << "  ";
        for(int j = 0 ; j < numeroDeVertices ; j++){
            std::cout << adjacencyMatrix[i][j] << " ";
        }
    }

    std::cout << std::endl << std::endl;
    std::cout << "Número de arestas: " << Graph::getTotalEdges << std::endl;
    std::cout << std::endl << std::endl;

}
    
Graph::~Graph(){

};


#endif