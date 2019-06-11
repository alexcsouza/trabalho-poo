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

Graph::Graph(int &numeroDeVertices) :
    numeroDeVertices(numeroDeVertices){ 
    //adjacencyMatrix(new int[numeroDeVertices * numeroDeVertices]){
        adjacencyMatrix[numeroDeVertices][numeroDeVertices];
        for(int i = 0 ; i < numeroDeVertices ; i++){
            for(int j = 0 ; j < numeroDeVertices ; j++){
                adjacencyMatrix[i] = {0};
            }
        }
};

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
    
Graph::~Graph(){

};


#endif