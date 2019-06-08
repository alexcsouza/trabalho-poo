#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <Graph.h>
#include <Edge.h>
#include <Vertex.h>

/**
 * Classe que representa um grafo referente à tarefa:
 * "Crie uma classe para representar o conceito de
 * grafo (classe Graph), com vértices representados por números inteiros (índices dos
 * vértices). A classe Graph utilizará uma representação interna por matriz de adjacência."
 * 
 */
Graph::Graph(int numeroDeVertices):numeroDeVertices(numeroDeVertices){};

bool Graph::insert(const Edge&){
    return false;
}
        
bool Graph::remove(const Edge&){
    return false;
}

int Graph::getTotalEdges(){
    return 0;
};

bool Graph::edge(const Edge&) const{
    return false;
};

bool Graph::isComplete(){
    return false;
};
        
void Graph::complete(){

};

void Graph::bfs(const Vertex&) const{

};
  
void Graph::dfs(const Vertex&) const{

};
    
Graph::~Graph(){

};


#endif