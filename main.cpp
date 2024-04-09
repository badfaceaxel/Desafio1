#include <iostream>
#include "Desafio1.h"

int main() {
    //Funcion Regla
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
        std::cout << "El segundo valor de la regla es "<< reglaKValidada[3] << std::endl;

        // Liberar la memoria del arreglo dinamico
        delete[] reglaK;
        delete[] reglaKValidada;

    }
    std::cout<<" "<<std::endl;
    //Funcion Tamaño
    int TamanoArreglo = 7;
    // Declarar los arreglos de forma dinamica
    int* arregloTamano = new int[TamanoArreglo];
    int reglaK[] = {4, 3, 1, 1, 1, -1, -1, 0};
    int* arregloRotaciones = new int[TamanoArreglo];

    // Llamar a la funcion validarTamano() y recibir los resultados en variables separadas
    int** resultado = validarTamano(arregloTamano, reglaK, TamanoArreglo, arregloRotaciones);
    int* nuevoArregloTamano = resultado[0];
    int* nuevoArregloRotaciones = resultado[1];

    // Imprimir los resultados
    std::cout << "Arreglo de tamanos: ";
    for (int i = 0; i < TamanoArreglo; ++i) {
        std::cout << nuevoArregloTamano[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Arreglo de rotaciones: ";
    for (int i = 0; i < TamanoArreglo; ++i) {
        std::cout << nuevoArregloRotaciones[i] << " ";
    }
    std::cout << std::endl;

    // Liberar la memoria dinámica
    delete[] arregloTamano;
    delete[] arregloRotaciones;
    delete[] nuevoArregloTamano;
    delete[] nuevoArregloRotaciones;
    delete[] resultado;

    return 0;
}
