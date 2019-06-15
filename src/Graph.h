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
        static int getTotalArestas();
        static int getTotalVertices();
        bool edge(const Edge &edge) const;
        bool isComplete() const;
        void complete();
        void bfs(const Vertex &vertex) const;
        void dfs(const Vertex &vertex) const;

        void printAdjacencyMatrix() const;

        ~Graph();

        void init();

};


#endif