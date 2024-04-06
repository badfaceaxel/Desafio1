#ifndef DESAFIO1_H
#define DESAFIO1_H
#include <iostream>
#include <iomanip>
using namespace std;

int*** generateMatrices(int* sizes, int numMatrices);
void imprimirMatrices(int*** arregloDeMatrices, int numMatrices, int* sizes);
void liberarMemoria(int*** arregloDeMatrices, int numMatrices, int* sizes);
bool cumpleRegla(int*** matrices, int* sizes, int numMatrices, int* regla, int reglaSize);


#endif // DESAFIO1_H
