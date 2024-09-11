#include <bits/stdc++.h>
using namespace std;
#include <chrono>

// Función para combinar dos subarrays ordenados en un solo array ordenado
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Función recursiva para ordenar
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Función para imprimir los elementos de un vector
void printVector(vector<int>& arr, int n)
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
    vector<int> arr(n);
    std::ifstream archivo("parc_5.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < n; ++i) {
            if (!(archivo >> arr[i])) {
                std::cerr << "Error al leer el archivo en la línea " << i + 1 << std::endl;
                return 1;
            }
        }
        archivo.close();
    }
    // Medir el tiempo de ejecución del algoritmo de ordenamiento
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Imprimir el vector ordenado y el tiempo de ejecucion
    cout << "Given vector is \n";
    printVector(arr,n);
    cout << duration.count() << endl;
    return 0;
}
