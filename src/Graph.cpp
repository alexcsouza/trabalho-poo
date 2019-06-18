#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "CharUtil.h"

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
    std::cout << std::endl <<"Caminhamentos de: " << v << std::endl << std::endl;
    int count = 0;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        int vertex = CharUtil::toInt(v);
        visited[vertex] = true;
        if(edge(Edge(vertex, i))){
            std::cout << (++count) << ". ";
            std::cout << v;
            performDfs(CharUtil::toLetter(i));
            resetVisited();
            std::cout << std::endl; 
        }
    }
    resetVisited();
};

void Graph::performDfs(const char &v) {
    
    int vertex = CharUtil::toInt(v);
    if(visited[vertex]){
        return;
    }
    std::cout << "->" << intToLetter(vertex);
    visited[vertex] = true;
    int *neighbours = adjacencyMatrix[vertex];
    for(int i = 0 ; i < numeroDeVertices ; i++){
        if(neighbours[i]==1){
            performDfs(CharUtil::toLetter(i));
        }
    }
    
};

void Graph::resetVisited(){
    lenghtOfPath = 0;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        visited[i] = false;
    }
}

/**
 * @see Graph::printAdjacencyMatrix
 */
void Graph::printAdjacencyMatrix() const{
    
    std::cout << std::endl << std::endl;
    std::cout << "   ";
    for(int j = 0 ; j < numeroDeVertices ; j++){
        std::cout << CharUtil::toLetter(j) << " ";
    }
    
    std::cout << std::endl;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        std::cout << std::endl;
        std::cout << CharUtil::toLetter(i) << "  ";
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

/**
 * @see Graph::~Graph()
 */
Graph::~Graph(){

};


#endif