#include "Desafio1.h"

void rotarMatriz(int** matriz, int filas, int columnas) {
    // Crear una matriz temporal para almacenar la matriz rotada
    int** matrizRotada = new int*[columnas];
    for (int i = 0; i < columnas; ++i) {
        matrizRotada[i] = new int[filas];
    }

    // Realizar la rotación
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matrizRotada[columnas - j - 1][i] = matriz[i][j];
        }
    }

    // Copiar la matriz rotada de vuelta a la matriz original
    for (int i = 0; i < columnas; ++i) {
        for (int j = 0; j < filas; ++j) {
            matriz[i][j] = matrizRotada[i][j];
        }
    }

    // Liberar la memoria asignada para la matriz rotada
    for (int i = 0; i < columnas; ++i) {
        delete[] matrizRotada[i];
    }
    delete[] matrizRotada;
}

// Función para obtener los estados de rotación de una matriz
int*** obtenerRotaciones(int** matriz, int filas, int columnas) {
    // Crear un arreglo de punteros a matrices para almacenar las rotaciones
    int*** rotaciones = new int**[4];

    // Rotar la matriz original y almacenarla en el arreglo de rotaciones
    rotaciones[0] = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        rotaciones[0][i] = new int[columnas];
        for (int j = 0; j < columnas; ++j) {
            rotaciones[0][i][j] = matriz[i][j];
        }
    }

    // Realizar las rotaciones adicionales y almacenarlas en el arreglo de rotaciones
    for (int i = 1; i <= 3; ++i) {
        rotaciones[i] = new int*[filas];
        for (int j = 0; j < filas; ++j) {
            rotaciones[i][j] = new int[columnas];
            for (int k = 0; k < columnas; ++k) {
                rotaciones[i][j][k] = rotaciones[i-1][j][k];
            }
        }
        rotarMatriz(rotaciones[i], filas, columnas);
    }

    return rotaciones;
}

int* validarReglaK(int reglaK[], int a) {

    // Solicitar las entradas de la regla K
    std::cout << "Ingrese la regla K (" << a << " elementos separados por espacios): ";
    for (int i = 0; i < a; ++i) {
        std::cin >> reglaK[i];
    }

    // Verificar que las dos primeras entradas sean enteros positivos o cero
    if (reglaK[0] < 0 || reglaK[1] < 0) {
        std::cout << "Las dos primeras entradas deben ser enteros positivos o cero." << std::endl;
        return nullptr;
    }

    // Verificar que las entradas a partir de la tercera sean -1, 0, o 1
    for (int i = 2; i < a; ++i) {
        if (reglaK[i] != -1 && reglaK[i] != 0 && reglaK[i] != 1) {
            std::cout << "Las entradas a partir de la tercera deben ser -1, 0, o 1." << std::endl;
            return nullptr;
        }
    }

    // Si pasó todas las validaciones, retornar un puntero al arreglo de reglaK
    return reglaK;
}

int** validarTamano(int arregloTamano[], int reglaK[], int TamanoArreglo, int arregloRotaciones[]) {
    int cantidadUnos = 0;

    for (int i = 2; i < 5; ++i) {
        if (reglaK[i] == 1) {
            cantidadUnos++;
        }
    }
    std::cout << cantidadUnos << std::endl;//Se saca la cantidad de unos del arreglo para el caso del -1

    int tamanoMinimo = 3;
    int minRows = reglaK[0];
    int minCols = reglaK[1];

    if (minRows > minCols) {
        if (minRows > 2) {
            for (int i = 3; i <= minRows; i += 2)
                tamanoMinimo += 2;
        }
    } else if (minRows < minCols) {
        if (minCols > 2) {
            for (int i = 3; i <= minCols; i += 2)
                tamanoMinimo += 2;
        }
    } else { //son iguales
        if (minRows > 2) {
            for (int i = 3; i <= minRows; i += 2)
                tamanoMinimo += 2;
        }
    }
    std::cout << tamanoMinimo << std::endl;//Se saca el tamano minimo que tiene la matriz segun las coordenadas dadas

    int menor;
    int extrapol = 0;

    if (minRows < minCols) {
        menor = minRows;
    } else {
        menor = minCols;
    }

    while (menor > 0) {
        extrapol++;
        menor--;
    }
    std::cout << extrapol << std::endl;//Se saca extrapol que es la variable que nos ayuda para saber la cantidad de veces
                                       //que puede mermar el tamaño de una matriz segun las coordenadas dadas
    if (reglaK[2] == -1) {//CASO DEL -1
        int tamanoMaximo = tamanoMinimo + (2 * cantidadUnos);//Se hace una operacion con los -1 para saber el tamañoMaximo de la matriz
        arregloTamano[0] = tamanoMinimo;
        arregloTamano[1] = tamanoMaximo;//Se le asigna ese tamano maximo a la 2 posicion para maniobrar con libertad los tamaños a lo largo del ciclo

        for (int i = 3; i <= TamanoArreglo; i++) {
            if (reglaK[i] == 1) {
                tamanoMaximo -= 2;
                arregloTamano[i - 1] = tamanoMaximo;
                extrapol--;
                if (extrapol <= 0) {//Se hace una prueba con el extrapol para ver si es posible seguir disminuyendo la matriz
                    std::cout << "Con las coordenadas dadas no se puede crear un sistema de apertura." << std::endl;
                    break;
                }
            } else if (reglaK[i] == -1) {
                tamanoMaximo += 2;
                arregloTamano[i - 1] = tamanoMaximo;
                extrapol++;
            } else {
                arregloTamano[i - 1] = tamanoMaximo;
            }
        }
    } else if (reglaK[2] == 1) {//CASO DEL 1
        int tamanoMaximo = tamanoMinimo + (2 * extrapol);//Se utiliza el extrapol para saber la cantidad de veces que puedo disminuir la matriz
        arregloTamano[0] = tamanoMaximo;//Se le hacen rotaciones a esta matriz y se le asigna al arreglo como indicativo en la linea de abajo
        arregloRotaciones[0] = 1;
        arregloTamano[1] = tamanoMaximo;//Cualquier matrizA si la rotaX veces va ser mayor que la B si son de igual tamaño
        int cont = 1;
        int i = 3;

        while (tamanoMaximo >= 3) {//Condicion para saber si el sistema se puede crear
            if (i <= TamanoArreglo) {
                if (reglaK[i] == 1) {
                    if (cont == 1) {
                        if (extrapol <= 0) {//Se hace una prueba con el extrapol para ver si es posible seguir disminuyendo la matriz
                            std::cout << "Con las coordenadas dadas no se puede crear un sistema de apertura." << std::endl;
                            break;
                        }
                        tamanoMaximo -= 2;
                        arregloTamano[i - 1] = tamanoMaximo;
                        arregloRotaciones[i - 1] = 1;
                        cont--;//con la ayuda del contador y de la posicion del arreglo se puede saber que matriz es posible que necesite rotaciones
                        extrapol--;
                    } else {
                        if (extrapol <= 0) {//Se hace una prueba con el extrapol para ver si es posible seguir disminuyendo la matriz
                            std::cout << "Con las coordenadas dadas no se puede crear un sistema de apertura." << std::endl;
                            break;
                        }
                        arregloTamano[i - 1] = tamanoMaximo;//Si no se necesita rotaciones es del mismo tamaño siguiendo algo dicho anteriormente
                        cont++;
                    }
                } else if (reglaK[i] == -1) {
                    tamanoMaximo += 2;
                    arregloTamano[i - 1] = tamanoMaximo;//Caso del -1 dentro del ciclo
                    extrapol++;
                } else {
                    arregloTamano[i - 1] = tamanoMaximo;
                }
            }
            i++;

            if (i > TamanoArreglo) {
                // Asignar memoria dinamica para los nuevos arreglos
                int* nuevoArregloTamano = new int[TamanoArreglo];
                int* nuevoArregloRotaciones = new int[TamanoArreglo];

                // Copiar los valores a los nuevos arreglos
                for (int j = 0; j < TamanoArreglo; j++) {
                    nuevoArregloTamano[j] = arregloTamano[j];
                    nuevoArregloRotaciones[j] = arregloRotaciones[j];
                }

                // Retornar los nuevos arreglos
                return new int*[2] {nuevoArregloTamano, nuevoArregloRotaciones};
            }
        }

        if (tamanoMaximo < 3) {//Se hace una prueba final para corrobar al 100% de que no se puede crear el sistema de apertura con las condiciones dadas
            std::cout << "Con las coordenadas dadas no se puede crear un sistema de apertura." << std::endl;
        }
    } else {//CASO DEL 0
        arregloTamano[0] = tamanoMinimo;
        arregloTamano[1] = tamanoMinimo;
        int pos = 3;
        while (reglaK[pos] == 0) {
            arregloTamano[pos - 1] = tamanoMinimo;
            pos++;
        }//El 0 como es igual siempre sera el mismo tamaño y se comprueba si hay varios 0 seguidos para seguir con el mismo tamaño siempre

        if (reglaK[pos] == -1) {
            int tamanoMaximo = tamanoMinimo + (2 * cantidadUnos);//MISMA LOGICA QUE EL CASO -1
            for (int i = pos; i <= TamanoArreglo; i++) {
                if (reglaK[i] == 1) {
                    tamanoMaximo -= 2;
                    arregloTamano[i - 1] = tamanoMaximo;
                    extrapol--;
                    if (extrapol <= 0) {//Se hace una prueba con el extrapol para ver si es posible seguir disminuyendo la matriz
                        std::cout << "Con las coordenadas dadas no se puede crear un sistema de apertura." << std::endl;
                        break;
                    }
                } else if (reglaK[i] == -1) {
                    tamanoMaximo += 2;
                    arregloTamano[i - 1] = tamanoMaximo;
                    extrapol++;
                } else {
                    arregloTamano[i - 1] = tamanoMaximo;
                }
            }
        } else {//Caso del 1 dentro del ciclo
            int tamanoMaximo = tamanoMinimo + (2 * extrapol);
            for (int i = 0; i <= pos; i++) {//Se cambian los tamaños de las posiciones donde hay 0 por el tamanomaximo
                arregloTamano[i] = tamanoMaximo;
            }
            tamanoMaximo -= 2;//Se le resta 2 al tamanomaximo y cont = 0, para poder aplicar la misma logica del caso 1
            int cont = 0;

            while (tamanoMaximo >= 3) {//Misma logica que el caso del 1
                if (pos <= TamanoArreglo) {
                    if (reglaK[pos] == 1) {
                        if (cont == 1) {
                            if (extrapol <= 0) {//Se hace una prueba con el extrapol para ver si es posible seguir disminuyendo la matriz
                                std::cout << "Con las coordenadas dadas no se puede crear un sistema de apertura." << std::endl;
                                break;
                            }
                            tamanoMaximo -= 2;
                            arregloTamano[pos - 1] = tamanoMaximo;
                            arregloRotaciones[pos - 1] = 1;
                            cont--;
                            extrapol--;
                        } else {
                            if (extrapol <= 0) {//Se hace una prueba con el extrapol para ver si es posible seguir disminuyendo la matriz
                                std::cout << "Con las coordenadas dadas no se puede crear un sistema de apertura." << std::endl;
                                break;
                            }
                            arregloTamano[pos - 1] = tamanoMaximo;
                            cont++;
                        }
                    } else if (reglaK[pos] == -1) {
                        tamanoMaximo += 2;
                        arregloTamano[pos - 1] = tamanoMaximo;
                        extrapol++;
                    } else {
                        arregloTamano[pos - 1] = tamanoMaximo;
                    }
                }
                pos++;

                if (pos > TamanoArreglo) {
                    // Asignar memoria dinamica para los nuevos arreglos
                    int* nuevoArregloTamano = new int[TamanoArreglo];
                    int* nuevoArregloRotaciones = new int[TamanoArreglo];

                    // Copiar los valores a los nuevos arreglos
                    for (int j = 0; j < TamanoArreglo; j++) {
                        nuevoArregloTamano[j] = arregloTamano[j];
                        nuevoArregloRotaciones[j] = arregloRotaciones[j];
                    }

                    // Retornar los nuevos arreglos
                    return new int*[2] {nuevoArregloTamano, nuevoArregloRotaciones};
                }
            }
        }
    }

    // Asignar memoria dinamica para los nuevos arreglos
    int* nuevoArregloTamano = new int[TamanoArreglo];
    int* nuevoArregloRotaciones = new int[TamanoArreglo];

    // Copiar los valores a los nuevos arreglos
    for (int j = 0; j < TamanoArreglo; j++) {
        nuevoArregloTamano[j] = arregloTamano[j];
        nuevoArregloRotaciones[j] = arregloRotaciones[j];
    }

    // Retornar los nuevos arreglos
    return new int*[2] {nuevoArregloTamano, nuevoArregloRotaciones};
}
