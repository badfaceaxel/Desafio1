#ifndef DESAFIO1_H
#define DESAFIO1_H
#include <iostream>
using namespace std;
const int N = 5;

void rotaMatriz(int matriz[][N], int* rotacionMatrices[], int rotations);
int* validarReglaK(int reglaK[], int n);
int* validarTamano(int arregloTamano[], int reglaK[], int TamanoArreglo);

#endif // DESAFIO1_H
