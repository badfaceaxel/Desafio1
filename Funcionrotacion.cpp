#include <iostream>

const int N = 5;

//i = filas, j =columnas
// Función para rotar una matriz
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

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < 3; ++i) {
        delete[] rotacionMatrices[i];
    }

    return 0;
}
