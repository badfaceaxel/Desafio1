#include <Desafio1.h>
#include <iostream>>

using namespace std;


int** generateMatrices(int* sizes, int numMatrices) {
    int totalSize = 0;
    for (int i = 0; i < numMatrices; i++) {
        totalSize += sizes[i] * sizes[i];
    }

    int** matrices = new int*[totalSize];
    int idx = 0;

    for (int i = 0; i < numMatrices; i++) {
        int size = sizes[i];
        int mid = size / 2;
        int currentValue = 1;
        for (int j = 0; j < size; j++) {
            matrices[idx] = new int[size];
            for (int k = 0; k < size; k++) {
                if (j == mid && k == mid) {
                    matrices[idx][k] = 0;
                } else {
                    matrices[idx][k] = currentValue++;
                }
            }
            idx++;
        }
    }

    return matrices;
}

bool cumpleRegla(int** matrices, int* sizes, int numMatrices, int* regla, int reglaSize) {
    if (reglaSize < 3 || (reglaSize - 1) > numMatrices) {
        cout << "Tamaño de regla invalido" << endl;
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

    int indiceRegla = 2;
    int valorInicial = matrices[0][regla[0] - 1][regla[1] - 1];

    for (int i = 1; i < numMatrices; i++) {
        int operacion = regla[indiceRegla++];
        int fila = regla[indiceRegla++] - 1;
        int columna = regla[indiceRegla++] - 1;

        int size = sizes[i];
        if (fila >= size || columna >= size) {
            cout << "Coordenadas fuera de rango para la matriz " << i << endl;
            return false;
        }

        int valor = matrices[i][fila][columna];

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
