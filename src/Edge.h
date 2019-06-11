#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Edge.h"

class Edge{
    private:
        int v1;
        int v2;
    public: 
        Edge(int &v1, int &v2);
        int getV1() const;
        int getV2() const;
        ~Edge();
};

#endif