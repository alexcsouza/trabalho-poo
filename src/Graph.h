#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "Edge.h"
#include "Vertex.h"

#define intToLetter(i) (char)(i+65);

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
        bool *visited;
        int lenghtOfPath;

        /**
         * Efetua o cálculo da (Depth First Search – DFS)
         * 
         * j) Função para realizar a busca em profundidade (Depth First Search – DFS). Essa função
         *    deve receber o índice de um vértice e apresentar os índices dos vértices na ordem do
         *    caminhamento em profundidade a partir do vértice recebido como parâmetro. Este
         *    caminhamento deve ser feito em todos os componentes do grafo.
         *    Função para retornar o número de componentes conectad
         * 
         */        
        void performDfs(const char &vertex);
        
        /**
         * Método auxiliar para limpar indicações de vertices visitados no cálculo de buscas (Depth First Search – DFS).
         * 
         */
        void resetVisited();

    public:
        static int totalEdges;
        Graph(int &numeroDeVertices);
        bool insert(const Edge &edge);
        bool remove(const Edge &edge);
        static int getTotalArestas();
        int getTotalVertices();
        bool edge(const Edge &edge) const;
        bool isComplete() const;
        void complete();
        void bfs(const char &vertex);
        
        /**
         * Efetua o cálculo da (Depth First Search – DFS) a partir de um vértice para todos os outros.
         * 
         * j) Função para realizar a busca em profundidade (Depth First Search – DFS). Essa função
         *    deve receber o índice de um vértice e apresentar os índices dos vértices na ordem do
         *    caminhamento em profundidade a partir do vértice recebido como parâmetro. Este
         *    caminhamento deve ser feito em todos os componentes do grafo.
         *    Função para retornar o número de componentes conectad
         * 
         */        

        void dfs(const char &vertex);
        
        /**
         * Método útil para impressão da matriz de adjacência em tela.
         */
        void printAdjacencyMatrix() const;

        ~Graph();

        void init();

};


#endif