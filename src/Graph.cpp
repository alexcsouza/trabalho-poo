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
    return arr[edge.getV2()] != 0;
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

void Graph::bfs(const char &vi) {
    cout << endl << "Caminhamentos BFS de: " << vi << endl << endl<< flush;
    bool first = true;
    int vertex = CharUtil::toInt(vi);

    bool *visited = new bool[numeroDeVertices]; 
    for(int i = 0; i < numeroDeVertices; i++){
        visited[i] = false; 
    }
  
    queue<int> queue; 
  
    visited[vertex] = true; 
    queue.push(vertex); 
  
    while(!queue.empty()) 
    { 
        vertex = queue.front();
        if(first){
            first = false;
        }else{
            cout << "->" ;
        }
        
        cout << CharUtil::toLetter(vertex); 
        queue.pop(); 
  
        for(int i = 0 ; i < numeroDeVertices ; i++) 
        { 
            if (!visited[i] && edge(Edge(i, vertex))) 
            { 
                visited[i] = true; 
                queue.push(i); 
                vertex = i;
            } 
        } 
    }
    cout << endl << endl;
 
};
  
void Graph::dfs(const char &v){
    cout << endl <<"Caminhamentos DFS de: " << v << endl << endl;
    int count = 0;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        int vertex = CharUtil::toInt(v);
        visited[vertex] = true;
        if(edge(Edge(vertex, i))){
            cout << (++count) << ". ";
            cout << v;
            int count = performDfs(CharUtil::toLetter(i));
            resetVisited();
            cout << " (" << count << " passos)" << endl; 
        }
    }
    cout << endl;
    resetVisited();
};

int Graph::performDfs(const char &v) {
    int count = 1;
    int vertex = CharUtil::toInt(v);
    if(visited[vertex]){
        return count;
    }
    cout << "->" << CharUtil::toLetter(vertex);
    count++;
    visited[vertex] = true;
    int *neighbours = adjacencyMatrix[vertex];
    for(int i = 0 ; i < numeroDeVertices ; i++){
        if(neighbours[i]==1){
            count += performDfs(CharUtil::toLetter(i)) -1 ;
        }
    }
    return count;
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

int Graph::getTotalConnections(){
    int count = 0;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        for(int j = 0 ; j < numeroDeVertices ; j++){
            //int vertex = i;
            visited[i] = true;
            if(edge(Edge(i, j))){
                count += performDfs(CharUtil::toLetter(j));
                //resetVisited();
            }
        }
    }

    cout.clear();

    resetVisited();
    return count;
};

/**
 * @see Graph::~Graph()
 */
Graph::~Graph(){
    //delete &edgeQueue;
};

#endif