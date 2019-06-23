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

        queue<int> edgeQueue;

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
        int performDfs(const char &vertex, const bool printOutput = true);
        
        /**
         * Método auxiliar para limpar indicações de vertices visitados no cálculo de buscas (Depth First Search – DFS).
         * 
         */
        void resetVisited();

        int minKey(int key[], bool mstSet[]);

    public:

        /**
         * Atributo estático que indica o número de arestas criadas pela classe. Como mais de um grafo 
         * pode ser criado, dentro do universo estudado, é interessante que se saiba quantas arestas foram criadas
         * mesmo que não façam parte do mesmo grafo.
         * 
         */
        static int totalEdges;

        /**
         * Método estático que retornará o número total de arestas criadas em todos os grafos repersentados por esta classe (Graph).
         * 
         * e) Funções para buscar o número de vértices e o número de arestas do grafo. Para que a
         *    função que retorna o número de arestas seja eficiente, é interessante que a classe
         *    mantenha um atributo interno que faça esta contagem. O atributo deve ser atualizado
         *    em todas as inserções e remoções de aresta que ocorrerem com sucesso;
         * 
         * @TODO: Revisar o método e o atributo não deveriam ser membros privados e não estáticos.
         * 
         */
        static int getTotalArestas();

        /**
         * Construtor do grafo. Recebe um inteiro que será usado para determinar o tamanho da matriz de adjacência (quadrada).
         * 
         * a) Um construtor, que receberá como parâmetro um inteiro indicando o número de
         *    vértices do grafo;
         * 
         * @param int &numeroDeVertices - O número de vértices do qual o grafo é composto.
         */
        Graph(int &numeroDeVertices);
        
        /**
         * Método que possibilita a inclusão de uma aresta entre dois vértices do grafo. Preencherá a matriz de adjacëncia.
         * 
         * c) Função para inserir uma aresta no grafo: bool Graph::insert(const Edge&). A função
         *    retornará true se a inserção ocorrer com sucesso e false caso a aresta que se está
         *    tentando inserir já exista no grafo.
         * 
         * @param Edge &edge - Uma instäncia de Edge que encapsula as informações de uma aresta a ser representada no grafo.
         */
        bool insert(const Edge &edge);
        
        /**
         * Método que remove uma aresta definida anteriormente no grafo.
         * 
         * d) Função para retirar uma aresta do grafo: bool Graph::remove(const Edge&). A função
         *    retornará true se a remoção ocorrer com sucesso e false caso a aresta que se está
         *    tentando remover não exista no grafo.
         * 
         * @param Edge &edge - Uma instäncia de Edge que encapsula as informações de uma aresta a ser removida do grafo.
         */
        bool remove(const Edge &edge);


        int getTotalVertices();

        /**
         * Método que indica se uma aresta existe no grafo.
         *  
         * f) Função para verificar a existência de uma aresta do grafo: bool Graph::edge(const
         *    Edge&) const . A função retornará true se a aresta estiver presente no grafo e false em
         *    caso contrário.
         * 
         * @param Edge &edge - Uma instäncia de Edge que encapsula as informações de uma aresta a ser removida do grafo.
         * 
         */
        bool edge(const Edge &edge) const;

        /**
         * Método que indica se o grafo é completo (todos os vértices possuiem arestas entre si).
         * 
         * g) Função booleana para verificar se o grafo desenhado é completo.
         * 
         */
        bool isComplete() const;

        /**
         * Método que completa a matriz de adjacência adicionando arestas em todos os vertices para todos os outros.
         * 
         * h) Função para completar o grafo desenhado.
         * 
         */
        void complete();

        /**
         * Efetua o cálculo da (Breath First Search – BFS) a partir de um vértice para todos os outros. Imprime 
         * todas as ligações do vértice fornecido como argumento.
         * 
         * i) Função para realizar a busca em largura (Breadth First Search - BFS). Essa função deve
         *    receber o índice de um vértice e apresentar os índices dos vértices na ordem do
         *    caminhamento em largura a partir do vértice recebido como parâmetro. Este
         *    caminhamento deve ser feito apenas no componente do vértice inicial.
         * 
         * @param char &vertex - o vértice a partir do qual se deseja efetuar a busca
         * 
         */
        void bfs(const char &v);
        
        /**
         * Efetua o cálculo da (Depth First Search – DFS) a partir de um vértice para todos os outros.
         * 
         * j) Função para realizar a busca em profundidade (Depth First Search – DFS). Essa função
         *    deve receber o índice de um vértice e apresentar os índices dos vértices na ordem do
         *    caminhamento em profundidade a partir do vértice recebido como parâmetro. Este
         *    caminhamento deve ser feito em todos os componentes do grafo.
         * 
         * @param char &vertex - o vértice a partir do qual se deseja efetuar a busca
         * 
         */        
        void dfs(const char &vertex);
        
        /**
         * Método útil para impressão da matriz de adjacência em tela.
         */
        void printAdjacencyMatrix() const;

        int getTotalConnections();

        void mst();

        void dijkstra(const char &v);

        void travellingSalesman(const char &vi);

        /**
         * Destrutor da classe.
         *  
         * b) Um destrutor, que se incumbirá de fazer a desalocação de memória eventualmente
         *    utilizada na representação do grafo;
         * 
         */
        ~Graph();

};


#endif