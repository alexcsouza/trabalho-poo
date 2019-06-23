#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include "CharUtil.h"

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
int Graph::totalEdges = 0;

/**
 * Construtor do grafo. Recebe um inteiro que será usado para determinar o tamanho da matriz de adjacência (quadrada).
 * 
 * a) Um construtor, que receberá como parâmetro um inteiro indicando o número de
 *    vértices do grafo;
 * 
 * @param int &numeroDeVertices - O número de vértices do qual o grafo é composto.
 */
Graph::Graph(int &nv) :
    numeroDeVertices(nv){
    visited = new bool[numeroDeVertices];
    resetVisited();

    adjacencyMatrix = new int*[numeroDeVertices];
    for(int i = 0 ; i < numeroDeVertices ; i++){
        adjacencyMatrix[i] = new int[numeroDeVertices];
    }
}

/**
 * Método que possibilita a inclusão de uma aresta entre dois vértices do grafo. Preencherá a matriz de adjacëncia.
 * 
 * c) Função para inserir uma aresta no grafo: bool Graph::insert(const Edge&). A função
 *    retornará true se a inserção ocorrer com sucesso e false caso a aresta que se está
 *    tentando inserir já exista no grafo.
 * 
 * @param Edge &edge - Uma instäncia de Edge que encapsula as informações de uma aresta a ser representada no grafo.
 */
bool Graph::insert(const Edge &e){
    if(e.getV1() >= numeroDeVertices
        || e.getV1() >= numeroDeVertices
        || e.getV1() == e.getV2() 
        || edge(e)){
        return false;
    }
    adjacencyMatrix[e.getV1()][e.getV2()] = e.getWeight();
    adjacencyMatrix[e.getV2()][e.getV1()] = e.getWeight();
    
    Graph::totalEdges++;
    return true;
}
        
/**
 * Método que remove uma aresta definida anteriormente no grafo.
 * 
 * d) Função para retirar uma aresta do grafo: bool Graph::remove(const Edge&). A função
 *    retornará true se a remoção ocorrer com sucesso e false caso a aresta que se está
 *    tentando remover não exista no grafo.
 * 
 * @param Edge &edge - Uma instäncia de Edge que encapsula as informações de uma aresta a ser removida do grafo.
 */
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
int Graph::getTotalEdges(){
    return Graph::totalEdges;
};

/**
 * Método que fornece o número total de vértices do grafo.
 *
 * e) Funções para buscar o número de vértices e o número de arestas do grafo. Para que a
 * função que retorna o número de arestas seja eficiente, é interessante que a classe
 * mantenha um atributo interno que faça esta contagem. O atributo deve ser atualizado
 * em todas as inserções e remoções de aresta que ocorrerem com sucesso;
 * 
 */
int Graph::getTotalVertex(){
    return numeroDeVertices;
};

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
bool Graph::edge(const Edge &edge) const{
    int *arr = adjacencyMatrix[edge.getV1()];
    return arr[edge.getV2()] != 0;
};

/**
 * Método que indica se o grafo é completo (todos os vértices possuiem arestas entre si).
 * 
 * g) Função booleana para verificar se o grafo desenhado é completo.
 * 
 */
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
       
/**
 * Método que completa a matriz de adjacência adicionando arestas em todos os vertices para todos os outros.
 * 
 * h) Função para completar o grafo desenhado.
 * 
 */
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
void Graph::bfs(const char &vi) {
    cout << endl << " *** Caminhamentos BFS de: " << vi << " *** " << endl << endl<< flush;
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
void Graph::dfs(const char &v){
    cout << endl <<" *** Caminhamentos DFS de: " << v << " *** " << endl << endl;
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
int Graph::performDfs(const char &v, const bool printOutput) {
    int count = 1;
    int vertex = CharUtil::toInt(v);
    if(visited[vertex]){
        return count;
    }
    if(printOutput){
        cout << "->" << CharUtil::toLetter(vertex);
    }
    count++;
    visited[vertex] = true;
    int *neighbours = adjacencyMatrix[vertex];
    for(int i = 0 ; i < numeroDeVertices ; i++){
        if(neighbours[i]==1){
            count += performDfs(CharUtil::toLetter(i), printOutput) -1 ;
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
 * Método útil para impressão da matriz de adjacência em tela para visualização dos valores
 * 
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
    cout << "Numero de arestas : " << Graph::getTotalEdges() << endl;
    cout << "Numero de vertices: " << numeroDeVertices << endl;
    cout << "Matriz completa   : " << (isComplete()?"sim":"não") << endl;
    cout << endl;

}

/**
 * Método que fornece o número total de conexões presentes no grafo:
 * 
 * k) Função para retornar o número de componentes conectados do grafo. A
 *    determinação do número de componentes conectados pode ser feita usando busca
 *    em profundidade no grafo.
 * 
 */
int Graph::getTotalConnections(){
    int count = 0;
    for(int i = 0 ; i < numeroDeVertices ; i++){
        for(int j = 0 ; j < numeroDeVertices ; j++){
            visited[i] = true;
            if(edge(Edge(i, j))){
                count += performDfs(CharUtil::toLetter(j), false);
            }
        }
    }

    cout.clear();

    resetVisited();
    return count;
};

/**
 * Método auxiliar que fornece o valor mínimo para a geração da árvore geradora mínima (MST)
 */        
int Graph::minKey(int key[], bool mstSet[]){  
    int min = INT_MAX, min_index;  
    for (int i = 0; i < numeroDeVertices; i++){
        if (mstSet[i] == false && key[i] < min) {
            min = key[i];
            min_index = i;  
        }
    }
    return min_index;  
}  

/**
 * Método que produz a árvore geradora mínima do grafo.
 * 
 * n) Função para encontrar uma árvore geradora mínima de um grafo com peso nas
 *    arestas.
 * 
 */
void Graph::mst(){

    cout << endl << endl << " *** Arvore geradora minima *** " << endl << endl; 

    int parent[numeroDeVertices];
    int key[numeroDeVertices];  
    bool mstSet[numeroDeVertices];  

    for (int i = 0; i < numeroDeVertices; i++){
        key[i] = INT_MAX, mstSet[i] = false;  
    }
  
    key[0] = 0;  
    parent[0] = -1;   
  
    for (int i = 0; i < numeroDeVertices - 1; i++){  
        
        int u = minKey(key, mstSet);  
        mstSet[u] = true;  

        for (int j = 0; j < numeroDeVertices; j++){
            if (edge(Edge(u, j)) && mstSet[j] == false && adjacencyMatrix[u][j] < key[j]){
                parent[j] = u;
                key[j] = adjacencyMatrix[u][j];
            }
        }

    }  
  
    cout << "Aresta\t\tPeso\n";  
    for (int i = 1; i < numeroDeVertices; i++){  
        if(parent[i] < 0 || adjacencyMatrix[i][parent[i]] == 0){
            continue;
        }
        cout 
            << "( "
            << CharUtil::toLetter(parent[i]) 
            << ", " 
            << CharUtil::toLetter(i) 
            << " )"
            << "\t" 
            << adjacencyMatrix[i][parent[i]]
            << "\n";  
    }
    cout << endl;

}

/**
 * Método que calcula o caminho pelo algoritmo de Dijkstra.
 * 
 * l) Função para encontrar o menor caminho através do Algoritmo de Dijkstra. Essa função
 *    deverá receber o índice do vértice inicial e final e retornar os vértices contidos no
 *    menor caminho bem como o comprimento desse menor caminho.
 * 
 * @param char &initialVertex - O vértice de partida para o cálculo.
 * @param char &finalVertex - O vértice de destino.
 * 
 */
void Graph::dijkstra(const char &vi, const char &vf){

    cout << endl << endl << " *** Dijkstra de " << vi << " ate " << vf << " *** " << endl << endl;   

    if(vi == vf){
        cout << vi << endl << "Custo: 0" << endl << flush;    
        return;
    }

    int vertex = CharUtil::toInt(vi);
    int finalVertex = CharUtil::toInt(vf);
    int dist[numeroDeVertices];
    bool sptSet[numeroDeVertices];
    
    for (int i = 0; i < numeroDeVertices; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false; 
    }
   
    dist[vertex] = 0; 
   
    for (int count = 0; count < numeroDeVertices-1; count++){ 
   
        int min = INT_MAX;
        int u; 
   
        for (int v = 0; v < numeroDeVertices; v++){
            if (sptSet[v] == false && dist[v] <= min){
                min = dist[v];
                u = v;  
            }
        }

       sptSet[u] = true; 
   
        for (int v = 0; v < numeroDeVertices; v++){
            if ( ! sptSet[v] 
                && adjacencyMatrix[u][v] 
                && dist[u] != INT_MAX
                && dist[u] + adjacencyMatrix[u][v] < dist[v]){
                
                dist[v] = dist[u] + adjacencyMatrix[u][v]; 
                
            }

        }
        
    } 

    int totalDist = 0;
    bool reachEnd = false;
    cout << vi << "(0)";
    for (int i = 0; i < numeroDeVertices; i++){
        if(i == vertex || dist[i] == INT_MAX ){
            continue;
        }
        cout << "->" << CharUtil::toLetter(i)<<"("<<dist[i] <<")";
        totalDist += dist[i];
        if(i == finalVertex){
            reachEnd = true;
            break;
        } 
    }
    if( ! reachEnd){
        cout.clear();
        cout  << endl << "[INFO] Nao chega ao destino";
    }
    cout << endl << "Custo: " << totalDist << endl << flush;

} 

/**
 * Método que resolve o problema do caixeiro viajante.
 * 
 * m) Função para resolver o Problema do Caixeiro Viajante. Essa função deverá completar o
 *    grafo caso o mesmo não seja completo.
 * 
 * @param char &vertex - O vértice de partida. 
 * 
 */
void Graph::travellingSalesman(const char &vi){ 
    cout << endl << endl << " *** Caixeiro viajante de " << vi << " *** " << endl << endl;   
    if( ! isComplete() ){
        cout << "[INFO] Completando a matriz de adjacência" << endl;
        complete();
    }
    cout << vi;

    int vertex = CharUtil::toInt(vi);
    vector<int> ver = vector<int>(); 

    for (int i = 0; i < numeroDeVertices; i++){
        if (i != vertex){
            ver.push_back(i); 
        }
    }
  
    int minPath = INT_MAX; 
    do { 
  
        int currentPathweight = 0; 
          
        int k = vertex; 
        for (int i = 0; i < ver.size(); i++) { 
            currentPathweight += adjacencyMatrix[k][ver[i]]; 
            k = ver[i]; 
        } 
        currentPathweight += adjacencyMatrix[k][vertex]; 
  
        minPath = min(minPath, currentPathweight); 

        if(!visited[k]){
            visited[k] = true;
        }
         
    } while (next_permutation(ver.begin(), ver.end())); 
  
    for (int i = 0; i < numeroDeVertices; i++) { 
        if(visited[i]){
            cout << "->" << CharUtil::toLetter(i) << flush;
        }
    } 

    cout << endl << "[INFO] Custo do percurso: " << minPath << endl << flush;
    resetVisited();
    
} 

/**
 * Destrutor da classe.
 *  
 * b) Um destrutor, que se incumbirá de fazer a desalocação de memória eventualmente
 *    utilizada na representação do grafo;
 * 
 */
Graph::~Graph(){
    
};

#endif