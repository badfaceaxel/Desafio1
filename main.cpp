#include <iostream>
#include <Desafio1.h>

using namespace std;


int main() {
    int sizes[] = {3, 5, 7, 9};
    int numMatrices = sizeof(sizes) / sizeof(int);
    int*** ArregloDeMatrices = generateMatrices(sizes, numMatrices);
    int regla[] = {4, 4, -1, -1, -1,};
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
