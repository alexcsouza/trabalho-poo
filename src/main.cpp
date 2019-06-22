#ifndef MAIN
#define MAIN

#include <iostream>
#include "Graph.cpp"
#include "Edge.cpp"
#include "CharUtil.cpp"

#define NUMERO_DE_VERTICES 5

using namespace std; 

/**
 * Declarações de funções de controle do script.
 */
void inserirEdges(Graph &graph);
void removerEdges(Graph &graph);
void exibirBfs(Graph &graph);
void exibirDfs(Graph &graph);

int main(void) {
    int numeroDeVertices = NUMERO_DE_VERTICES;

    Graph graph = Graph(numeroDeVertices);
    inserirEdges(graph);    
    removerEdges(graph);
    graph.printAdjacencyMatrix();
    exibirBfs(graph);    
    exibirDfs(graph);
    int totalConnections = graph.getTotalConnections();
    cout  << endl << endl << endl << "Total de conexões: " << totalConnections << endl << flush;
    
    cout << endl;

    Graph graphCompleto = Graph(numeroDeVertices);
    graphCompleto.complete();
    graphCompleto.printAdjacencyMatrix();
    exibirBfs(graphCompleto);    
    exibirDfs(graphCompleto);    
    totalConnections = graph.getTotalConnections();
    cout  << endl << "Total de conexões: " << totalConnections << endl << flush;
    
    cout << endl;
    return 0;
}

void exibirBfs(Graph &graph){
    for(int i = 0 ; i < NUMERO_DE_VERTICES ; i++){
        graph.bfs(CharUtil::toLetter(i));
    }
}

void exibirDfs(Graph &graph){
    for(int i = 0 ; i < NUMERO_DE_VERTICES ; i++){
        graph.dfs(CharUtil::toLetter(i));
    }
}

void inserirEdges(Graph &graph){

    int v1=0, v2=3; 
    if(graph.insert(Edge(v1,v2))){
        cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=3, v2=1; 
    if(graph.insert(Edge(v1,v2))){
        cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=3, v2=4; 
    if(graph.insert(Edge(v1,v2))){
        cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=2, v2=2; 
    if(graph.insert(Edge(v1,v2))){
        cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=1, v2=4; 
    if(graph.insert(Edge(v1,v2))){
        cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << endl;
    }
/* 
    v1=3, v2=2; 
    if(graph.insert(Edge(v1,v2))){
        cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << endl;
    }
*/

    v1=4, v2=3; 
    if(graph.insert(Edge(v1,v2))){
        cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=4, v2=3; 
    if(graph.insert(Edge(v1,v2))){
        cout << "Aresta adicionada com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível adicionar a aresta (" << v1 << ", " << v2 << ")." << endl;
    }

}

void removerEdges(Graph &graph){

    int v1=3, v2=4; 
    if(graph.remove(Edge(v1,v2))){
        cout << "Aresta removida com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível remover a aresta (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=4, v2=2; 
    if(graph.remove(Edge(v1,v2))){
        cout << "Aresta removida com sucesso (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "Não foi possível remover a aresta (" << v1 << ", " << v2 << ")." << endl;
    }

}

#endif