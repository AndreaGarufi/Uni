// header file per la gestione di una pila mediante array nativi

#ifndef PILA_H
#define PILA_H

const int MAX_PILA = 5;

template <typename T>
class Pila
{
public:
    Pila();   
    void Push(T elem);
    //~pila();
    T Pop();
private:
    T *array;
    int top;
    int dim;
};

#include "pila.cpp"

#endif