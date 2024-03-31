#include <iostream>

const int N = 5;

// Función para rotar una matriz
void rotateMatrix(int matrix[][N]) {
    int rotatedMatrix[N][N];

    // Realizar la rotación
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotatedMatrix[N - j - 1][i] = matrix[i][j];
        }
    }

    // Imprimir la matriz rotada
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << rotatedMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Ejemplo de uso
    int matrix[N][N] = {{1, 2, 3, 4, 5},
                       {6, 7, 8, 9, 10},
                       {11, 12, 0, 13, 14},
                       {15, 16, 17, 18 ,19},
                       {20, 21, 22, 23, 24}};
    rotateMatrix(matrix);

    return 0;
}
