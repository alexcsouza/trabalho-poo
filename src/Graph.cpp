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
    visited = new bool[numeroDeVertices];
    resetVisited();
    adjacencyMatrix = new int*[numeroDeVertices];
    for(int i = 0 ; i < numeroDeVertices ; i++){
        adjacencyMatrix[i] = new int[numeroDeVertices];
    }
}

bool Graph::insert(const Edge &e){
    if(e.getV1() >= numeroDeVertices
        || e.getV1() >= numeroDeVertices
        || e.getV1() == e.getV2() 
        || edge(e)){
        return false;
    }
    adjacencyMatrix[e.getV1()][e.getV2()] = 1;
    adjacencyMatrix[e.getV2()][e.getV1()] = 1;
    
    Graph::totalEdges++;
    return true;
}
        
bool Graph::remove(const Edge &e){
    if(e.getV1() >= numeroDeVertices
        || e.getV1() >= numeroDeVertices
        || e.getV1() == e.getV2() 
        || ! edge(e)){
        return false;
    }
    adjacencyMatrix[e.getV1()][e.getV2()] = 0;
    adjacencyMatrix[e.getV2()][e.getV1()] = 0;

    Graph::totalEdges--;
    return true;
}

int Graph::getTotalArestas(){
    return Graph::totalEdges;
};

int Graph::getTotalVertices(){
    return numeroDeVertices;
};

bool Graph::edge(const Edge &edge) const{
    int *arr = adjacencyMatrix[edge.getV1()];
    return arr[edge.getV2()] == 1;
};

bool Graph::isComplete() const{
    for(int i = 0 ; i < numeroDeVertices ; i++){
        for(int j = 0 ; j < numeroDeVertices ; j++){
            if(i==j){
                continue;
            }
            if(!edge(Edge(i,j))){
                return false;
            }
        }
    }
    return true;
};
        
void Graph::complete(){
    for(int i = 0 ; i < numeroDeVertices ; i++){
        for(int j = 0 ; j < numeroDeVertices ; j++){
            if(i==j){
                continue;
            }
            if(!edge(Edge(i,j))){
                insert(Edge(i, j));
            }
        }
    }
};

void Graph::bfs(const char &v) {
    
};
  
void Graph::dfs(const char &v){
    for(int i = 0 ; i < numeroDeVertices ; i++){
        int vertex = int(v - 65);
        if(edge(Edge(vertex, i))){
            std::cout << v;
            performDfs((char)(i+65));
            resetVisited();
            std::cout << std::endl; 
        }
        
    }
};

void Graph::performDfs(const char &v) {
    
    int vertex = int(v - 65);
    if(visited[vertex]){
        return;
    }
    std::cout << "->" << (char)(vertex+65);
    visited[vertex] = true;
    int *neighbours = adjacencyMatrix[vertex];
    for(int i = 0 ; i < numeroDeVertices ; i++){
         
        if(neighbours[i]==1){
            //std::cout << "->" << (char)(i+65);
            performDfs((char)(i+65));
        }
        //std::cout << std::endl; 
        
    }
    
};

void Graph::resetVisited(){
    lenghtOfPath = 0;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        visited[i] = false;
    }
}

/**
 * Método útil para dos vertices visitados nas buscas.
 
void Graph::printVisited() const{
    std::cout << std::endl;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        if(visited[i]){
            std::cout << " -> " << ((char)(i+65)) ;
        }
    }
    std::cout << std::endl;
}
*/

/**
 * Método útil para impressão da matriz de adjacência em tela.
 */
void Graph::printAdjacencyMatrix() const{
    
    std::cout << std::endl << std::endl;
    std::cout << "   ";
    for(int j = 0 ; j < numeroDeVertices ; j++){
        std::cout << ((char)(j+65)) << " ";
    }
    
    std::cout << std::endl;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        std::cout << std::endl;
        std::cout << ((char)(i+65)) << "  ";
        for(int j = 0 ; j < numeroDeVertices ; j++){
            std::cout << adjacencyMatrix[i][j] << " ";
        }
    }

    std::cout << std::endl << std::endl;
    std::cout << "Número de arestas : " << Graph::getTotalArestas() << std::endl;
    std::cout << "Número de vértices: " << numeroDeVertices << std::endl;
    std::cout << "Matriz completa   : " << (isComplete()?"sim":"não") << std::endl;
    std::cout << std::endl;

}
    
Graph::~Graph(){

};


#endif