#include <iostream>
#include "Desafio1.h"

int main() {

    // Ejemplo de uso
    int matriz[N][N] = {{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 0, 13, 14},
                        {15, 16, 17, 18 ,19},
                        {20, 21, 22, 23, 24}};
    //Memoria dinamica asignacion
    int* rotacionMatrices[3];
    for (int i = 0; i < 3; ++i) {
        rotacionMatrices[i] = new int[N * N];
    }
    rotaMatriz(matriz, rotacionMatrices, 3);

    int valor = rotacionMatrices[1][(4*5+4)];
    std::cout << "Valor en la posicion (4, 4) de la segunda matriz rotada: " << valor << std::endl;

    // Imprimir las matrices almacenadas en el arreglo de punteros
    std::cout << "Matrices almacenadas:" << std::endl;
    for (int k = 0; k < 3; ++k) {
        std::cout << "Rotacion " << k + 1 << ":" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << rotacionMatrices[k][i * N + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Liberar la memoria asignada dinamicamente
    for (int i = 0; i < 3; ++i) {
        delete[] rotacionMatrices[i];
    }

    int a;
    // Solicitar el tamano de la regla K
    std::cout << "Ingrese el tamano de la regla K (debe ser al menos 3): ";
    std::cin >> a;

    if (a < 3) {
        std::cout << "La regla K debe tener al menos 3 elementos." << std::endl;
    }
    else {
        // Crear un arreglo dinamico para almacenar la regla K
        int *reglaK = new int[a];

        // Validar la regla K
        int* reglaKValidada = validarReglaK(reglaK, a);

        if (reglaKValidada != nullptr) {
            std::cout << "La regla K es valida." << std::endl;
        } else {
            std::cout << "La regla K no es valida." << std::endl;
        }

        //Prueba para sacar datos de la regla
        std::cout << "El tercer valor de la regla es "<< reglaKValidada[3] << std::endl;

        // Liberar la memoria del arreglo dinamico
        delete[] reglaK;
    }
    return 0;
}
