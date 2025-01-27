// Tarea1_ProgramacionParalela.cpp - Steven Sebastian Brutscher Cortez (A01732505)

#include <iostream>
#include <omp.h>
#include <cstdlib>  // Para poder usar srand() para la generación de números aleatorios
#include <ctime>    // Para poder usar time(nullptr) como semilla para srand()

#define N 1000          // El tamaño de mis arreglos
#define chunk 100       // El tamaño de los pedazos a procesar en paralelo
#define mostrar 10      // La cantidad de datos a mostrar en la salida

void imprimeArreglo(float* d); // Prototipo de la función para imprimir arreglos

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N]; // Primero declaro los arreglos
    int pedazos = chunk;

    // Inicializando los arreglos con valores aleatorios
    srand(static_cast<unsigned int>(time(nullptr))); // Utilizo una semilla para generar números aleatorios
    for (int i = 0; i < N; i++) {
        a[i] = static_cast<float>(rand() % 100); // Valores aleatorios entre 0 y 99
        b[i] = static_cast<float>(rand() % 100); // Valores aleatorios entre 0 y 99
    }

    int i;  // Me estaba marcando un error de "Identificador no declarado", así que
            // declaro explícitamente la variable `i` antes del bloque paralelo

    // Realizo la suma de arreglos en paralelo
    #pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    for (int i = 0; i < N; i++)
    {  // Declaro `i` como privada para asegurar que cada hilo maneje su propio índice
        c[i] = a[i] + b[i];
    }

    // Imprimiendo los primeros valores de los arreglos
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo A:\n";
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo B:\n";
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo C (resultado):\n";
    imprimeArreglo(c);

    return 0;
}

// Implementando la función para imprimir los arreglos
void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++) {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
