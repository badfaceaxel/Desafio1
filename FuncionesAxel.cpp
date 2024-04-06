#include <Desafio1.h>

int*** generateMatrices(int* sizes, int numMatrices) {
    // Crear el arreglo de punteros a arreglos de matrices bidimensionales
    int*** arregloDeMatrices = new int**[numMatrices];

    // Generar cada matriz y almacenarla en el arreglo
    for (int i = 0; i < numMatrices; ++i) {
        int size = sizes[i];
        int mid = size / 2;
        int currentValue = 1;

        // Asignar memoria para la matriz bidimensional
        arregloDeMatrices[i] = new int*[size];
        for (int j = 0; j < size; ++j) {
            arregloDeMatrices[i][j] = new int[size];
        }

        // Inicializar valores de la matriz
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                if (j == mid && k == mid) {
                    arregloDeMatrices[i][j][k] = 0;
                } else {
                    arregloDeMatrices[i][j][k] = currentValue++;
                }
            }
        }
    }

    return arregloDeMatrices;
}


void imprimirMatrices(int*** arregloDeMatrices, int numMatrices, int* sizes) {
    for (int i = 0; i < numMatrices; ++i) {
        std::cout << "Matriz " << i+1 << ":" << std::endl;
        int size = sizes[i];
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                // Imprimir cada elemento con un ancho fijo
                std::cout << std::setw(4) << arregloDeMatrices[i][j][k];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}


void liberarMemoria(int*** arregloDeMatrices, int numMatrices, int* sizes) {
    // Liberar la memoria asignada para cada matriz
    for (int i = 0; i < numMatrices; ++i) {
        int size = sizes[i];
        for (int j = 0; j < size; ++j) {
            delete[] arregloDeMatrices[i][j];
        }
        delete[] arregloDeMatrices[i];
    }

    // Liberar la memoria asignada para el arreglo de punteros a matrices
    delete[] arregloDeMatrices;
}



bool cumpleRegla(int*** matrices, int* sizes, int numMatrices, int* regla, int reglaSize) {
    if (reglaSize < 3 || (reglaSize - 1) > numMatrices) {
        cout << "Tamaño de regla inválido" << endl;
        return false;
    }

    for (int i = 0; i < numMatrices; i++) {
        int size = sizes[i];
        int filaInicial = regla[0] - 1;
        int columnaInicial = regla[1] - 1;

        if (filaInicial >= size || columnaInicial >= size) {
            cout << "Coordenadas iniciales fuera de rango para la matriz " << i << endl;
            return false;
        }
    }
    int columnaInicial = regla[1] - 1;
    int filaInicial = regla[0] - 1;
    int indiceRegla = 2;
    int valorInicial = matrices[0][filaInicial][columnaInicial];

    for (int i = 1; i < numMatrices; i++) {
        int operacion = regla[indiceRegla++];
        int fila = regla[0] - 1;
        int columna = regla[1] - 1;

        int size = sizes[i-1];
        if (fila >= size || columna >= size) {
            cout << "Coordenadas fuera de rango para la matriz " << i << endl;
            return false;
        }

        int valor = matrices[i][filaInicial][columnaInicial];

        switch (operacion) {
        case -1:
            if (valorInicial >= valor) {
                cout << "No se cumple la regla: " << valorInicial << " >= " << valor << endl;
                return false;
            }
            valorInicial = valor;
            break;
        case 1:
            if (valorInicial <= valor) {
                cout << "No se cumple la regla: " << valorInicial << " <= " << valor << endl;
                return false;
            }
            valorInicial = valor;
            break;
        case 0:
            if (valorInicial != valor) {
                cout << "No se cumple la regla: " << valorInicial << " != " << valor << endl;
                return false;
            }
            valorInicial = valor;
            break;
        default:
            cout << "Operacion invalida en la regla" << endl;
            return false;
        }
    }

    cout << "Se cumple la regla" << endl;
    return true;
}
