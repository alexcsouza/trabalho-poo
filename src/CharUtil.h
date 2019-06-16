#ifndef CHAR_UTIL_H
#define CHAR_UTIL_H

#include <iostream>

class CharUtil{
    public:
        /**
         * Função utilitária que converte um inteiro em uma letra, maiúscula, 
         * corespondente ao número, começando de A (0 = 'A', 1 = 'B', 2 = 'C', ...)
         */
        static char toLetter(const int &i);
        
        /**
         * Função utilitária que converte um char em um inteiro considerando A como o primeiro inteiro.
         * (0 = 'A', 1 = 'B', 2 = 'C', ...)
         */
        static int toInt(const char &c);
};

#endif