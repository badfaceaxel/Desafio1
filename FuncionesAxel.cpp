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

    int columna = regla[1] - 1;
    int fila = regla[0] - 1;

    for (int i = 0; i < numMatrices; i++) {     //Se valida que la posicion sea valida (valga la rebundancia) en todos los tamaños de las matrices
        int size = sizes[i];
        if (fila >= size || columna >= size) {
            cout << "Las Coordenadas ingresadas: "<<"["<<regla[0]<<"]["<<regla[1]<<"]"<<" estan fuera de rango para la Matriz:  "<< sizes[i]<<"x"<<sizes[i]<<endl;
            return false;
        }
    }

    int indiceRegla = 2;
    int valorInicial = matrices[0][fila][columna];

    for (int i = 1, j = 0; i < numMatrices; i++, j++) {
        int operacion = regla[indiceRegla+j];
        int dif = sizes[j] - sizes[i];
        int sum = abs(dif)/2;
        int valor = matrices[i][fila+sum][columna+sum];

        switch (operacion) {
        case -1:
            if (valorInicial >= valor) {
                cout << "No se cumple la regla: " << valorInicial << " >= " << valor << endl;
                return false;
            }
            cout << valorInicial <<"<"<< valor <<endl;
            valorInicial = valor;
            cout<<endl;
            break;
        case 1:
            if (valorInicial <= valor) {
                cout << "No se cumple la regla: " << valorInicial << " <= " << valor << endl;
                return false;
            }
            cout << valorInicial <<">"<< valor <<endl;
            valorInicial = valor;
            cout<<endl;
            break;
        case 0:
            if (valorInicial != valor) {
                cout << "No se cumple la regla: " << valorInicial << " != " << valor << endl;
                return false;
            }
            cout << valorInicial <<"="<< valor <<endl;
            cout<<endl;
            break;
        default:
            cout << "Operacion invalida en la regla." << endl;
            cout<<endl;
            return false;
        }
    }
    cout << "Se cumple la regla" << endl;
    return true;
}
