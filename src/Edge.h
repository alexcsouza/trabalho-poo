#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Edge.h"

class Edge{
    private:
        const int v1;
        const int v2;
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