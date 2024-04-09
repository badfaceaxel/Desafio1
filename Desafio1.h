#ifndef FUNCIONESPRUEBAS_H
#define FUNCIONESPRUEBAS_H
#include <iostream>
#include <iomanip>
using namespace std;




const int NumRotaciones = 4;
int*** generateMatrices(int* sizes, int numMatrices); //

void imprimirMatrices(int*** arregloDeMatrices, int numMatrices, int* sizes); //
void imprimirMatriz(int** matriz, int filas, int columnas); //
void liberarMemoria(int*** arregloDeMatrices, int numMatrices, int* sizes); //
void rotarMatriz(int** matriz, int filas, int columnas); //
int*** obtenerRotaciones(int** matriz, int filas, int columnas); //
int** copiarMatriz(int*** matrices, int* sizes, int matrizIndex); //
void liberarRotaciones(int*** rotaciones, int filas);
bool cumpleRegla(int*** matrices, int* sizes, int numMatrices, int* regla, int reglaSize);

void liberarMatriz(int** matriz, int filas);
void reemplazarMatriz(int*** arregloDeMatrices, int indice, int** nuevaMatriz, int filasNuevaMatriz, int columnasNuevaMatriz);
int*** generarCerradura(int* sizes, int* regla);
void imprimirArreglo(int* arreglo, int longitud);

int* validarReglaK(int reglaK[], int n);
int** validarTamano(int arregloTamano[], int reglaK[], int TamanoArreglo, int arregloRotaciones[]);



#endif // FUNCIONESPRUEBAS_H
