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



void imprimirMatrices(int*** arregloDeMatrices, int numMatrices,int* sizes) {
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



int** copiarMatriz(int*** matrices,int* sizes, int matrizIndex) {
    int filas = sizes[matrizIndex];
    int columnas = sizes[matrizIndex];

    // Asignar memoria para la nueva matriz
    int** nuevaMatriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        nuevaMatriz[i] = new int[columnas];
    }

    // Copiar los valores de la matriz original a la nueva matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            nuevaMatriz[i][j] = matrices[matrizIndex][i][j];
        }
    }

    return nuevaMatriz;
}


// Función para liberar la memoria asignada para el arreglo de rotaciones


// Función para liberar la memoria asignada para el arreglo de rotaciones
void liberarRotaciones(int*** rotaciones, int filas) {
    for (int i = 1; i <= 2; ++i) {
        for (int j = 0; j < filas; ++j) {
            delete[] rotaciones[i][j];
        }
        delete[] rotaciones[i];
    }
    delete[] rotaciones;
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
        int valor, dif, sum;

        switch (operacion) {
        case -1:
            if (sizes[0] == sizes[i]) {
                valor = matrices[0][fila][columna];
            }
            else
            {
                dif = sizes[j] - sizes[i];
                sum = abs(dif)/2;
                valor = matrices[i][fila+sum][columna+sum];
            }


            if (valorInicial >= valor) {
                cout << "No se cumple la regla: " << valorInicial << " >= " << valor << endl;
                return false;
            }

            cout << valorInicial <<"<"<< valor <<endl;
            valorInicial = valor;
            cout<<endl;
            break;
        case 1:

            if (sizes[0] == sizes[i]) {
                valor = matrices[0][fila][columna];
            }
            else
            {
                dif = sizes[j] - sizes[i];
                sum = abs(dif)/2;
                valor = matrices[i][fila-sum][columna-sum];
            }

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
            //valorInicial = valor;
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


// Función para liberar la memoria de una matriz
void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}


// Función para reemplazar una matriz en el arreglo de matrices
void reemplazarMatriz(int*** arregloDeMatrices, int indice, int** nuevaMatriz, int filasNuevaMatriz, int columnasNuevaMatriz) {
    // Liberar la memoria de la matriz existente en el índice dado
    liberarMatriz(arregloDeMatrices[indice], filasNuevaMatriz);

    // Asignar la dirección de la nueva matriz al índice correspondiente en el arreglo de matrices
    arregloDeMatrices[indice] = nuevaMatriz;
}

void imprimirMatriz(int** matriz, int filas, int columnas) {
    // Calcular la longitud máxima de los elementos de la matriz
    int maximo = matriz[0][0];
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
        }
    }
    int longitudMaxima = 0;
    while (maximo > 0) {
        maximo /= 10;
        ++longitudMaxima;
    }

    // Imprimir la matriz con setw para alinear los elementos
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << std::setw(longitudMaxima) << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int*** generarCerradura(int* sizes, int* regla) {
    int numMatrices = sizeof(sizes) / sizeof(int);
    int*** ArregloDeMatrices = generateMatrices(sizes, numMatrices);
    int indiceRegla = 2;
    int columna = regla[1] - 1;
    int fila = regla[0] - 1;

    for (int i = 0; i < numMatrices; i++) {     //Se valida que la posicion sea valida (valga la rebundancia) en todos los tamaños de las matrices
        int size = sizes[i];
        if (fila >= size || columna >= size) {
            cout << "Las Coordenadas ingresadas: "<<"["<<regla[0]<<"]["<<regla[1]<<"]"<<" estan fuera de rango para la Matriz:  "<< sizes[i]<<"x"<<sizes[i]<<endl;
            break;
        }
    }


    int valorInicial = ArregloDeMatrices[0][fila][columna];

    for (int i = 1, j = 0; i < numMatrices; i++, j++) {
        int operacion = regla[indiceRegla+j];
        int dif, sum, valor;

        switch (operacion) {
        case -1:
            if (sizes[0] == sizes[i]) {
                valor = ArregloDeMatrices[0][fila][columna];
            }
            else
            {
                dif = sizes[j] - sizes[i];
                sum = abs(dif)/2;
                valor = ArregloDeMatrices[i][fila+sum][columna+sum];
            }

            cout << valorInicial <<"<"<< valor <<endl;
            valorInicial = valor;
            cout<<endl;
            break;
        case 1:
            if (sizes[0] == sizes[i]) {
                valor = ArregloDeMatrices[0][fila][columna];
            }
            else
            {
                dif = sizes[j] - sizes[i];
                sum = abs(dif)/2;
                valor = ArregloDeMatrices[i][fila-sum][columna-sum];
            }

            if (valorInicial <= valor) {
                int  matrixCopy = sizes[j];
                int tamaño = sizes[matrixCopy];
                int** matrizCopiada = copiarMatriz(ArregloDeMatrices, sizes, matrixCopy);
                int*** matricesRotadas = obtenerRotaciones(matrizCopiada, tamaño, tamaño);
                int sizeRotadas[4] = {tamaño, tamaño, tamaño, tamaño};
                int valorRotada;

                for(int idx = 0; idx < 4; idx++) {
                    if (sizes[0] == sizes[i]) {
                        int valorRotada = matricesRotadas[idx][fila][columna];
                    }
                    else
                    {
                        dif = sizes[j] - sizes[i];
                        sum = abs(dif)/2;
                        int valorRotada = matricesRotadas[idx][fila-sum][columna-sum];
                    }

                    if (valorRotada > valorInicial) {
                        int** newMatrix = copiarMatriz(matricesRotadas, sizeRotadas, idx);
                        reemplazarMatriz(ArregloDeMatrices, j, newMatrix, tamaño , tamaño);   //Actualizamos el Arreglo de matrices con la nueva matriz rotada
                    }
                    break;
                }
                liberarRotaciones(matricesRotadas, tamaño);
                liberarMatriz(matrizCopiada, tamaño);
            }
            //cout << valorInicial <<">"<< valor <<endl;
            valorInicial = valor;
            cout<<endl;
            break;
        case 0:
            //cout << valorInicial <<"="<< valor <<endl;
            cout<<endl;
            break;
        default:
            cout << "Operacion invalida en la regla." << endl;
            cout<<endl;
            break;
        }
    }
    cout << "Se cumple la regla" << endl;
    return ArregloDeMatrices;
}

void imprimirArreglo(int* arreglo, int longitud) {
    for (int i = 0; i < longitud; ++i) {
        std::cout << arreglo[i];
        // Imprimir un espacio después de cada elemento, excepto el último
        if (i < longitud - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;  // Nueva línea al final
}
