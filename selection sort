#include <bits/stdc++.h>
using namespace std;
#include <chrono>
// This is code is contributed by rathbhupendra
// Funcion para ordenar un arreglo usando Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
// Funcion para imprimir los elementos de un arreglo
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int nn = 5;
    int n=1;
    for (int i=0;i<nn;i++){
        n=n*10;
    }
    int numeros[n];
    std::ifstream archivo("semi_5.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < n; ++i) {
            if (!(archivo >> numeros[i])) {
                std::cerr << "Error al leer el archivo en la línea " << i + 1 << std::endl;
                return 1;
            }
        }
        archivo.close();
    }
    // Medir el tiempo de ejecucion del algoritmo de ordenamiento
    auto start = chrono::high_resolution_clock::now();
    selectionSort(numeros, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Imprimir el arreglo ordenado y el tiempo de ejecucion
    cout << "Sorted array: \n";
    printArray(numeros, n);
    cout << duration.count() << endl;

    return 0;
}
