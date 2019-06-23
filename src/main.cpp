#ifndef MAIN
#define MAIN

#include <iostream>
#include "Graph.cpp"
#include "Edge.cpp"
#include "CharUtil.cpp"

#define NUMERO_DE_VERTICES 5
#define NOME_DO_ARQUIVO_DE_DADOS "data/vertex.csv"
#define MSG_ARESTA_ADICIONADA "Aresta adicionada com sucesso"
#define MSG_ARESTA_REMOVIDA "Não foi possíve remover a aresta"

using namespace std; 

/**
 * Declarações de funções de controle do script.
 */

/**
 * Função que efetua a inclusão de algumas arestas, por meio do método "Graph::insert", para que seja feito um teste das diversas
 * funcionalidades da classe "Graph". Especificamente, essa função efetua o teste da funcionalidade
 * de inclusão de arestas no grafo.
 * 
 */
void inserirEdges(Graph &graph);

void inserirEdgesCsv(Graph &graph);

/**
 * Função utilitária que efetua a remoção de algumas arestas adicionadas anteriormente
 * pela função "inserirEdges" para teste da funcionalidade de remoção, implementada na classe "Graph"
 * 
 */
void removerEdges(Graph &graph);

/**
 * Função utilitária que efetua a BFS para todos os vértices do grafo.
 * 
 */
void exibirBfs(Graph &graph);

/**
 * Função utilitária que efetua a DFS para todos os vértices do grafo.
 * 
 */
void exibirDfs(Graph &graph);

/**
 * Função que efetuará o disparo dos cálculos do algoritmo de Dijkstra de todos, para todos os vértices.
 */
void exibirDijkstra(Graph &graph);

/**
 * Funcão que efetuará o cálculo do problema do caixeiro viajante a partir de todos os vértices.
 */
void exibirTravellingSalesman(Graph &graph);

/**
 * Função que carrega o número de vértices do arquivo NOME_DO_ARQUIVO_DE_DADOS
 */
int carregarNumeroDeVertices();


/**
 * No método main, todas as funcionalidades são testadas.
 * 
 */
int main(void) {

    // O número de vértices é determinado pelo valor de NUMERO_DE_VERTICES para simplivicação do script
    int numeroDeVertices = NUMERO_DE_VERTICES;

    // Grafo com arestas criadas uma a uma.
    cout << " >> Efetuando teste de grafo com arestas diversas << " << endl << endl;
    Graph graph = Graph(numeroDeVertices);
    inserirEdges(graph);    
    removerEdges(graph);
    graph.printAdjacencyMatrix();
    exibirBfs(graph);    
    exibirDfs(graph);
    exibirDijkstra(graph);
    exibirTravellingSalesman(graph);
    graph.mst();
    
    cout << endl << "Total de conexoes: " << graph.getTotalConnections() << endl << endl << flush;
    
    // Grafo completo 
    cout << " >> Efetuando teste de grafo completo << " << endl << endl;
    Graph graphCompleto = Graph(numeroDeVertices);
    graphCompleto.complete();
    graphCompleto.printAdjacencyMatrix();
    exibirBfs(graphCompleto);    
    exibirDfs(graphCompleto);
    exibirDijkstra(graphCompleto);
    exibirTravellingSalesman(graphCompleto);
    graphCompleto.mst();
    cout << endl << "Total de conexões: " << graphCompleto.getTotalConnections() << endl << endl << flush;
    
    // Grafo com arestas carregadas de arquivo.
    cout << " >> Efetuando teste de grafo com arestas carregadas de arquivo .csv << " << endl << endl;
    numeroDeVertices = carregarNumeroDeVertices();
    Graph graphCsv = Graph(numeroDeVertices);
    inserirEdgesCsv(graphCsv);    
    graphCsv.printAdjacencyMatrix();
    exibirBfs(graphCsv);    
    exibirDfs(graphCsv);
    exibirDijkstra(graphCsv);
    exibirTravellingSalesman(graphCsv);
    graphCsv.mst();
    cout << endl << "Total de conexões: " << graphCsv.getTotalConnections() << endl << endl << flush;

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

void exibirDijkstra(Graph &graph){
    for(int i = 0 ; i < NUMERO_DE_VERTICES ; i++){
        for(int j = 0 ; j < NUMERO_DE_VERTICES ; j++){
            graph.dijkstra(CharUtil::toLetter(i), CharUtil::toLetter(j));
        }
    }
}

void exibirTravellingSalesman(Graph &graph){
    for(int i = 0 ; i < NUMERO_DE_VERTICES ; i++){
        graph.travellingSalesman(CharUtil::toLetter(i));
    }
}

void inserirEdges(Graph &graph){
    cout << " *** Criando arestas para teste do grafo *** " << endl << endl;

    int v1=0, v2=3, weight=5; 
    if(graph.insert(Edge(v1,v2,weight))){
        cout << "- " << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "- " << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=3, v2=1; 
    if(graph.insert(Edge(v1,v2))){
        cout << "- " << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "- " << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=3, v2=4; 
    if(graph.insert(Edge(v1,v2))){
        cout << "- " << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "- " << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=2, v2=2; 
    if(graph.insert(Edge(v1,v2))){
        cout << "- " << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "- " << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=1, v2=4, weight=2; 
    if(graph.insert(Edge(v1,v2, weight))){
        cout << "- " << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "- " << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=4, v2=3; 
    if(graph.insert(Edge(v1,v2))){
        cout << "- " << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "- " << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }
    
    v1=4, v2=3; 
    if(graph.insert(Edge(v1,v2))){
        cout << "- " << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "- " << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }

}

int carregarNumeroDeVertices(){
    cout << " *** Criando arestas para teste do grafo via arquivo " << NOME_DO_ARQUIVO_DE_DADOS << " *** " << endl << endl;

    fstream file; 
    file.open(NOME_DO_ARQUIVO_DE_DADOS, ios::in); 
    string line;
    getline(file, line);
    stringstream ss( line );
    string data;
    getline( ss, data, '\n' );

    return stoi(data);
    
}

void inserirEdgesCsv(Graph &graph){
    cout << "Criando arestas para teste do grafo via arquivo " << NOME_DO_ARQUIVO_DE_DADOS << " *** " << endl << endl;

    fstream file; 
    file.open(NOME_DO_ARQUIVO_DE_DADOS, ios::in); 
    string line;
    bool first = true;
	while (getline(file, line)){
        if(first){
            first = false;
            continue;
        }

        stringstream ss( line );
        vector<string> row = vector<string>();
        string data;
        while ( getline( ss, data, ',' ) ){
            row.push_back( data );
        }

        string v1 = row[0];
        string v2 = row[1];
        string weight = row[2];;

        if(graph.insert(Edge(stoi(v1),stoi(v2),stoi(weight)))){
            cout << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
        }else{
            cout << "" << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
        }

    }
    
}

void removerEdges(Graph &graph){

    int v1=3, v2=4; 
    if(graph.remove(Edge(v1,v2))){
        cout << "- " << "-" << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "-" << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }

    v1=4, v2=2; 
    if(graph.remove(Edge(v1,v2))){
        cout << "- " << "-" << MSG_ARESTA_ADICIONADA << " (" << v1 << ", " << v2 << ")." << endl;
    }else{
        cout << "-" << MSG_ARESTA_REMOVIDA << " (" << v1 << ", " << v2 << ")." << endl;
    }

}

#endif