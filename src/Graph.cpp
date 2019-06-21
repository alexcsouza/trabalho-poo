#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <queue>
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "CharUtil.h"

using namespace std; 

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


void Graph::bfs(const char &vi, const char &vf) {
    cout << endl <<"Caminhamentos BFS de: " << vi << " até " << vf << endl << endl;
    
    //int count = 0;
    //for(int i = 0 ; i < numeroDeVertices ; i++){
    //    int vertex = CharUtil::toInt(v);
        int *prev = performBfs(vi, vf);
        /*
        int count = 0;
        for(int i = 0; i < numeroDeVertices ; i++){
            if(prev[i] != NULL){
                //cout << "->" << CharUtil::toLetter(prev[i]);
                count++;
            }
        }
        if( prev[count] != CharUtil::toInt(vf) ){
            cout << endl <<"Não há caminhos de " << vi << " até " << vf << endl << endl;
            delete prev;
            return;
        }
         */
        cout << vi << flush;
        for(int i = 0; i < numeroDeVertices ; i++){
            if(prev[i] != NULL){
                cout << "->" << CharUtil::toLetter(i);
            }
        }

        resetVisited();
        cout << endl << endl; 
        
    //}
};

int * Graph::performBfs(const char &vi, const char &vf){
    
    int vertex = CharUtil::toInt(vi);
    int finalVertex = CharUtil::toInt(vf);
    edgeQueue = queue<int>();
    edgeQueue.push(vertex);

    visited[vertex] = true;
    int *path = new int[numeroDeVertices];
    for(int i = 0; i < numeroDeVertices ; i++){
        path[i] = NULL;
    }
    
    //int count = 0;
    while( ! edgeQueue.empty()){
        int node = edgeQueue.front();
        edgeQueue.pop();
        int *neighbours = adjacencyMatrix[node];
        for(int i = 0 ; i < numeroDeVertices ; i++){
            if( ! visited[i] && edge(Edge(i, node))){

                edgeQueue.push(i);
                visited[i] = true;
                path[i] = node;

                cout << endl << endl << "prev[" << i << "] = " << CharUtil::toLetter(node) << endl << endl<<flush;
                    
                    //count++;

             
                    //if(node == finalVertex){
                    //    return path;
                    //}
                
            }
        }
    }
    
    return path;
}
  
void Graph::dfs(const char &v){
    cout << endl <<"Caminhamentos DFS de: " << v << endl << endl;
    int count = 0;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        int vertex = CharUtil::toInt(v);
        visited[vertex] = true;
        if(edge(Edge(vertex, i))){
            cout << (++count) << ". ";
            cout << v;
            performDfs(CharUtil::toLetter(i));
            resetVisited();
            cout << endl; 
        }
    }
    resetVisited();
};

void Graph::performDfs(const char &v) {
    
    int vertex = CharUtil::toInt(v);
    if(visited[vertex]){
        return;
    }
    cout << "->" << CharUtil::toLetter(vertex);
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
    
    cout << endl << endl;
    cout << "   ";
    for(int j = 0 ; j < numeroDeVertices ; j++){
        cout << CharUtil::toLetter(j) << " ";
    }
    
    cout << endl;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        cout << endl;
        cout << CharUtil::toLetter(i) << "  ";
        for(int j = 0 ; j < numeroDeVertices ; j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
    }

    cout << endl << endl;
    cout << "Número de arestas : " << Graph::getTotalArestas() << endl;
    cout << "Número de vértices: " << numeroDeVertices << endl;
    cout << "Matriz completa   : " << (isComplete()?"sim":"não") << endl;
    cout << endl;

}

/**
 * @see Graph::~Graph()
 */
Graph::~Graph(){
    //delete &edgeQueue;
};

#endif