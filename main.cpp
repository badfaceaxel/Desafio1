#include <iostream>
#include <Desafio1.h>

using namespace std;


int main() {
    int sizes[] = {3, 7, 11, 9};
    int numMatrices = sizeof(sizes) / sizeof(int);

    int** matrices = generateMatrices(sizes, numMatrices);

    // Imprimir las matrices generadas
    int idx = 0;
    for (int i = 0; i < numMatrices; i++) {
        int size = sizes[i];
        std::cout << "Matriz de tamanio " << size << "x" << size << ":" << std::endl;
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                std::cout << matrices[idx][k] << "\t";
            }
            idx++;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Liberar la memoria
    idx = 0;
    for (int i = 0; i < numMatrices; i++) {
        int size = sizes[i];
        for (int j = 0; j < size; j++) {
            delete[] matrices[idx];
            idx++;
        }
    }
    delete[] matrices;

    return 0;
}
