#ifndef DESAFIO1_H
#define DESAFIO1_H
#include <iostream>
using namespace std;
const int N = 5;

void rotarMatriz(int** matriz, int filas, int columnas);
int*** obtenerRotaciones(int** matriz, int filas, int columnas);
int* validarReglaK(int reglaK[], int n);
int** validarTamano(int arregloTamano[], int reglaK[], int TamanoArreglo, int arregloRotaciones[]);

#endif // DESAFIO1_H
