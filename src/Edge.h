#ifndef EDGE_H
#define EDGE_H

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
class Edge{
    private:
        /**
         * Vérice 1 da ligação
         */
        const int v1;

        /**
         * Vértice 2 da ligação
         */
        const int v2;

        /**
         * Peso da ligação, por padrão, igual a 1.
         */
        const int weight = 1;
        
    public: 
        Edge(const int &v1, const int &v2, const int &weight);
        Edge(const int &v1, const int &v2);
        int getV1() const;
        int getV2() const;
        int getWeight() const;
        ~Edge();
};

#endif