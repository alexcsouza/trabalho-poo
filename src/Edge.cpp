#ifndef EDGE_CPP
#define EDGE_CPP

#include <iostream>
#include "Edge.h"

/**
 * Classe que representa uma aresta no grafo.
 * 
 * @author 2017089014 - Alex Souza <alexdcesouza@gmail.com>
 * @author 2017001320 - Rafael Ribeiro <raphaelribeiro@ufmg.br>
 * 
 * @see Edge.h
 * 
 * Obs: Os atributos estão documentados no arquivo .h, já os métodos,
 * no arquivo .cpp
 *
 */

/**
 * Construtor para ser usado em casos em que o peso da aresta é importante.
 * 
 * @param int &v1 - o vértice 1 da ligação
 * @param int &v2 - o vértice 2 da ligação
 * @param int &weight - o peso da ligação, quando relevante. Por padrão 1;
 * 
 */
Edge::Edge(const int &v1, const int &v2, const int &weight) : v1(v1), v2(v2), weight(weight){};

/**
 * Construtor para ser usado em casos em que o peso da aresta não é importante.
 * 
 * @param int &v1 - o vértice 1 da ligação
 * @param int &v2 - o vértice 2 da ligação
 * 
 */
Edge::Edge(const int &v1, const int &v2) : v1(v1), v2(v2){};

int Edge::getV1() const{
    return v1;
}

int Edge::getV2() const{
    return v2;
}

int Edge::getWeight() const{
    return weight;
}

Edge::~Edge(){
}

#endif