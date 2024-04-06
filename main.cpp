#include <iostream>
#include <Desafio1.h>

using namespace std;


int main() {
    int sizes[] = {3, 5, 7, 3, 9};
    int numMatrices = sizeof(sizes) / sizeof(int);
    int*** ArregloDeMatrices = generateMatrices(sizes, numMatrices);
    int regla[] = {1, 1, 0, 0, 0, 0};
    int reglaSize = sizeof(regla) / sizeof(int);

    // Imprimir las matrices
    imprimirMatrices(ArregloDeMatrices, numMatrices, sizes);

    cout<<endl;
    cout<<endl;
    cout<<endl;

    bool cumple = cumpleRegla(ArregloDeMatrices, sizes, numMatrices, regla, reglaSize);
    cout<<cumple<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    // Liberar la memoria asignada para las matrices
    liberarMemoria(ArregloDeMatrices, numMatrices, sizes);

    cout<<"Numero de matrices: "<<numMatrices<<endl;



    cout<<endl;
    cout<<endl;
    cout<<endl;



    return 0;
}
