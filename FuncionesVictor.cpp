#include "Desafio1.h"

void rotaMatriz(int matriz[][N], int* rotacionMatrices[], int rotations) {

    // Realizar las rotaciones "3"
    for (int k = 0; k < rotations; ++k) {
        int rotacionMatriz[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) { //i la fila de la orginal y se convierte en columna de la rotada
                rotacionMatriz[N - j - 1][i] = matriz[i][j];//j es la columna de la orginal y se convierte en fila de la rotada
            }//Se toman asi los valores por la rotacion (N - j- 1, i), j es 0 (primera fila), N - j - 1 será N - 1 (última columna)
        }
        // Almacenar la matriz rotada en el arreglo de punteros
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                rotacionMatrices[k][i * N + j] = rotacionMatriz[i][j]; //Indice lineal i*N + j que seria como encontrar el valor
                                                                       //de la posicion de esa matriz como se hace abajo (4,3) --> 4*5+3
            }
        }
        // Imprimir la matriz rotada
        std::cout << "Rotacion " << k + 1 << ":" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << rotacionMatriz[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        // Actualizar la matriz original para la siguiente rotacion (matriz)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matriz[i][j] = rotacionMatriz[i][j];
            }
        }
    }
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

    // Si paso todas las validaciones, retornar un puntero al arreglo de reglaK
    return reglaK;
}

int* validarTamano(int arregloTamano[], int reglaK[], int TamanoArreglo) {

    int cantidadUnos = 0;


    for (int i = 2; i < 5; ++i) {
        if (reglaK[i] == 1) {
            cantidadUnos++;
        }
    }
    std::cout << "CantUnos: " <<cantidadUnos << std::endl;

    int tamanoMinimo = 3;
    int minRows = reglaK[0];
    int minCols = reglaK[1];

    if (minRows > minCols) {
        if (minRows > 2){
            for(int i = 3; i<=minRows; i += 2)
                tamanoMinimo += 2;
        }


    } else if (minRows < minCols) {
        if (minCols > 2){
            for(int i = 3; i<=minCols; i += 2)
                tamanoMinimo += 2;
        }

    } else { //son iguales
        if (minRows > 2){
            for(int i = 3; i<=minRows; i += 2)
                tamanoMinimo += 2;
        }

    }
    std::cout << "Tamano min: " << tamanoMinimo << std::endl;



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
    std::cout<< "Cant extrapol:  " <<extrapol <<std::endl;

    if (reglaK[2] == -1) {

        int tamanoMaximo = tamanoMinimo+(2*cantidadUnos);
        arregloTamano[0] = tamanoMinimo;
        arregloTamano[1] = tamanoMaximo;

        for(int i = 3; i <= TamanoArreglo; i++){

            if(reglaK[i] == 1) {
                tamanoMaximo -= 2;
                arregloTamano[i-1] = tamanoMaximo;

            }else if(reglaK[i] == -1) {
                tamanoMaximo += 2;
                arregloTamano[i-1] = tamanoMaximo;

            } else {
                arregloTamano[i-1] = tamanoMaximo;

            }
        }


    } else if (reglaK[2] == 1) {

        int tamanoMaximo = tamanoMinimo+(2*extrapol);
        arregloTamano[0] = tamanoMaximo;
        arregloTamano[1] = tamanoMaximo;//rotaciones
        int cont = 1;

        while(tamanoMaximo >= 3){

            for(int i = 3; i <= TamanoArreglo; i++){

                if(reglaK[i] == 1) {

                    if(cont == 1){
                        tamanoMaximo -= 2;
                        arregloTamano[i-1] = tamanoMaximo;
                        cont--;

                    } else {
                        arregloTamano[i-1] = tamanoMaximo;
                        cont++;
                    }
                }else if(reglaK[i] == -1) {
                    tamanoMaximo += 2;
                    arregloTamano[i-1] = tamanoMaximo;

                } else {
                    arregloTamano[i-1] = tamanoMaximo;

                }
            }
            return arregloTamano;
        }
        std::cout<<"Con las coordenadas dadas no se puede crear un sistema de apertura."<<std::endl;


    } else {

        arregloTamano[0] = tamanoMinimo;
        arregloTamano[1] = tamanoMinimo;
        int pos = 3;
        while(reglaK[pos] == 0){
            arregloTamano[pos-1] = tamanoMinimo;
            pos++;
        }
        if(reglaK[pos] == -1){
            int tamanoMaximo = tamanoMinimo+(2*cantidadUnos);
            for(int i = pos; i <= TamanoArreglo; i++){

                if(reglaK[i] == 1) {
                    tamanoMaximo -= 2;
                    arregloTamano[i-1] = tamanoMaximo;

                }else if(reglaK[i] == -1) {
                    tamanoMaximo += 2;
                    arregloTamano[i-1] = tamanoMaximo;

                } else {
                    arregloTamano[i-1] = tamanoMaximo;

                }
            }
        } else {


        }
    }

    return arregloTamano; // Retornar el puntero al arreglo

}
