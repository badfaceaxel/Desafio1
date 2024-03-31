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
