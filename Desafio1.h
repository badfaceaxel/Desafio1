#ifndef DESAFIO1_H
#define DESAFIO1_H
#include <iostream>
#include <iomanip>
using namespace std;

void reemplazarMatriz(int*** arregloDeMatrices, int indice, int** nuevaMatriz, int filasNuevaMatriz, int columnasNuevaMatriz);
int** copiarMatriz(int*** matrices, int* sizes, int matrizIndex);
int*** generateMatrices(int* sizes, int numMatrices);
void imprimirMatrices(int*** arregloDeMatrices, int numMatrices, int* sizes);
void imprimirMatriz(int** matriz, int filas, int columnas);
void liberarMemoria(int*** arregloDeMatrices, int numMatrices, int* sizes);
void liberarMatriz(int** matriz, int filas);

bool cumpleRegla(int*** matrices, int* sizes, int numMatrices, int* regla, int reglaSize);


#endif // DESAFIO1_H
