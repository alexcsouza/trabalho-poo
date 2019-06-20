#ifndef CHAR_UTIL_CPP
#define CHAR_UTIL_CPP

#include <iostream>
#include "CharUtil.h"

using namespace std; 

char CharUtil::toLetter(const int &i){
    return ((char)(i+65));
};

int CharUtil::toInt(const char &c){
    return int(c - 65);
};

#endif