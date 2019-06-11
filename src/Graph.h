#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "Edge.h"
#include "Vertex.h"

/**
 * Classe que representa um grafo referente à tarefa:
 * "Crie uma classe para representar o conceito de
 * grafo (classe Graph), com vértices representados por números inteiros (índices dos
 * vértices). A classe Graph utilizará uma representação interna por matriz de adjacência."
 * 
 */
class Graph{
    private:
        const int numeroDeVertices;
        int **adjacencyMatrix;
        
    public:
        static int totalEdges;
        Graph(int &numeroDeVertices);
        bool insert(const Edge &edge);
        bool remove(const Edge &edge);
        int getTotalEdges();
        bool edge(const Edge &edge) const;
        bool isComplete();
        void complete();
        void bfs(const Vertex &vertex) const;
        void dfs(const Vertex &vertex) const;
        ~Graph();

        void init();

};


#endif