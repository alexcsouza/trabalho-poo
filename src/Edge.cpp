#ifndef EDGE_CPP
#define EDGE_CPP

#include <iostream>
#include "Edge.h"

Edge::Edge(const int &v1, const int &v2, const int &weight) : v1(v1), v2(v2), weight(weight){};
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