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
    numeroDeVerticesX(nv), numeroDeVerticesY(nv){
    adjacencyMatrix = new int*[numeroDeVerticesX];
    for(int i = 0 ; i < numeroDeVerticesX ; i++){
        adjacencyMatrix[i] = new int[numeroDeVerticesX];
    }
}

bool Graph::insert(const Edge &edge){
    if(edge.getV1() == edge.getV2() 
        || adjacencyMatrix[edge.getV1()][edge.getV2()] == 1){
        return false;
    }
    adjacencyMatrix[edge.getV1()][edge.getV2()] = 1;
    Graph::totalEdges++;
    return true;
}
        
bool Graph::remove(const Edge &edge){
    return false;
}

int Graph::getTotalEdges(){
    return 0;
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
    for(int i = 0 ; i < numeroDeVerticesX ; i++){
        std::cout << std::endl;
        for(int j = 0 ; j < numeroDeVerticesX ; j++){
            std::cout << adjacencyMatrix[i][j] << " ";
        }
    }
    std::cout << std::endl;
}
    
Graph::~Graph(){

};


#endif