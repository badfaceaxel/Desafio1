#include <iostream>
#include <Desafio1.h>

using namespace std;


int main() {

    //Funcion Regla
    int a;
    // Solicitar el tamano de la regla K
    std::cout << "Ingrese el tamano de la regla K (debe ser al menos 3): ";
    std::cin >> a;

    if (a < 3) {
        std::cout << "La regla K debe tener al menos 3 elementos." << std::endl;
    }
    else {
        // Crear un arreglo dinamico para almacenar la regla K
        int *reglaK = new int[a];

        // Validar la regla K
        int* regla = validarReglaK(reglaK, a);

        if (regla != nullptr) {
            std::cout << "La regla K es valida." << std::endl;
        } else {
            std::cout << "La regla K no es valida." << std::endl;
        }

        std::cout<<" "<<std::endl;

        //Funcion Tamaño
        int TamanoArreglo = a-1;
        // Declarar los arreglos de forma dinamica
        int* arregloTamano = new int[TamanoArreglo];
        int* arregloRotaciones = new int[TamanoArreglo];

        // Llamar a la funcion validarTamano() y recibir los resultados en variables separadas
        int** resultado = validarTamano(arregloTamano, regla, TamanoArreglo, arregloRotaciones);
        int* sizes = resultado[0];
        int* nuevoArregloRotaciones = resultado[1];

        // Imprimir los resultados
        std::cout << "Arreglo de tamanos: ";
        for (int i = 0; i < TamanoArreglo; ++i) {
            std::cout << sizes[i] << " ";
        }
        std::cout << std::endl;

        //AXELLLLLLLLLLLLLLLLLL
        int numMatrices = sizeof(sizes)/sizeof(int);

        //int reglaSize = sizeof(regla)/sizeof(int);
        //int*** ArregloDeMatrices = generateMatrices(sizes, numMatrices);


        //int valorx = ArregloDeMatrices[3][2][2];
        //cout<<"Valor de la matriz 4 en la posicion [2][2]: "<<valorx<<endl;

        int*** Cerradura = generarCerradura(sizes, regla);
        imprimirMatrices(Cerradura, numMatrices, sizes);

        cout<<endl;
        cout<<endl;
        cout<<endl;

        //cumpleRegla(ArregloDeMatrices, sizes, numMatrices, regla, reglaSize);

        // Liberar la memoria asignada para el arreglo de rotaciones



        cout<<endl;
        cout<<endl;
        cout<<endl;

        //int valor = matricesRotadas[1]2][2];
        //cout << "Valor en la posicion (3, 3) de la segunda matriz rotada: " << valor << std::endl;


        liberarMemoria(Cerradura, numMatrices, sizes);

        cout<<endl;
        cout<<endl;
        cout<<endl;




        cout<<"Numero de matrices: "<<numMatrices<<endl;

        // Liberar la memoria del arreglo dinamico
        delete[] reglaK;
        delete[] regla;

        delete[] arregloTamano;
        delete[] arregloRotaciones;
        delete[] sizes;
        delete[] nuevoArregloRotaciones;
        delete[] resultado;

    }



    return 0;
}

