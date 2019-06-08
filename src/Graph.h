#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <Edge.h>
#include <Vertex.h>

/**
 * Classe que representa um grafo referente à tarefa:
 * "Crie uma classe para representar o conceito de
 * grafo (classe Graph), com vértices representados por números inteiros (índices dos
 * vértices). A classe Graph utilizará uma representação interna por matriz de adjacência."
 * 
 */
class Graph{
    private:
        int numeroDeVertices;
        Vertex *adjacencyMatrix[][];
        static int totalEdges;
    public:
        Graph(int numeroDeVertices);
        bool insert(const Edge&);
        bool remove(const Edge&);
        int getTotalEdges();
        bool edge(const Edge&) const;
        bool isComplete();
        void complete();
        void bfs(const Vertex&) const;
        void dfs(const Vertex&) const;
        ~Graph();

        void init();

};


#endif