#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
#include "Edge.h"
#include "Vertex.h"

using namespace std; 

/**
 * Classe que representa um grafo referente à tarefa:
 * "Crie uma classe para representar o conceito de
 * grafo (classe Graph), com vértices representados por números inteiros (índices dos
 * vértices). A classe Graph utilizará uma representação interna por matriz de adjacência."
 * 
 * @author 2017089014 - Alex Souza <alexdcesouza@gmail.com>
 * @author 2017001320 - Rafael Ribeiro <raphaelribeiro@ufmg.br>
 * 
 * @see Graph.h
 * 
 * Obs: Os atributos estão documentados no arquivo .h, já os métodos,
 * no arquivo .cpp
 *  
 */
class Graph{
    private:

        /**
         * Número de vértices indicados na construção do objeto. Indica as dimensões da matriz de ajacência.
         */
        const int numeroDeVertices;

        /**
         * A matriz de adjacência que representa as arestas entre os vértices.
         */
        int **adjacencyMatrix;

        /**
         * Array útil para o cálculo de alguns métodos. Indica os vértices visitados na busca por caminhos entre eles.
         */
        bool *visited;

        /**
         * Atributo que efetua a contagem do caminho percorrido ao calcular as ligações entre os vértices. Usado em alguns cálculos.
         */
        int lenghtOfPath;

        /**
         * Fila para controle de cálculo de diversos algoritmos
         */
        queue<int> edgeQueue;

        /**
         * Método auxiliar para limpar indicações de vertices visitados no cálculo de buscas (Depth First Search – DFS).
         * 
         */
        void resetVisited();

        int minKey(int key[], bool mstSet[]);
        
        int performDfs(const char &vertex, const bool printOutput = true);
        

    public:

        /**
         * Atributo estático que indica o número de arestas criadas pela classe. Como mais de um grafo 
         * pode ser criado, dentro do universo estudado, é interessante que se saiba quantas arestas foram criadas
         * mesmo que não façam parte do mesmo grafo.
         * 
         */
        static int totalEdges;
        static int getTotalEdges();
        Graph(int &numeroDeVertices);
        bool insert(const Edge &edge);
        bool remove(const Edge &edge);
        int getTotalVertex();
        bool edge(const Edge &edge) const;
        bool isComplete() const;
        void complete();
        void bfs(const char &vertex);
        void dfs(const char &vertex);
        void printAdjacencyMatrix() const;
        int getTotalConnections();
        void mst();
        void dijkstra(const char &initialVertex, const char &finalVertex);
        void travellingSalesman(const char &vertex);

        ~Graph();

};


#endif