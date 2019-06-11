#ifndef EDGE_CPP
#define EDGE_CPP

#include <iostream>
#include "Edge.h"

Edge::Edge(int &v1, int &v2) : v1(v1), v2(v2){};

int Edge::getV1() const{
    return v1;
}

int Edge::getV2() const{
    return v2;
}

Edge::~Edge(){
    delete &v1;
    delete &v2;
}

#endif