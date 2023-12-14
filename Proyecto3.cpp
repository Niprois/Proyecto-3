#include <iostream>
#include <algorithm>
#include <chrono>
#include <windows.h>
#include <unordered_set>
#include <random>

using namespace std;

void checkAndChange(int elemCount, int Numero[]) {
    // Seed for random number generation
    std::srand(std::time(0));

    for (int i = 0; i < elemCount; ++i) {
        for (int j = i + 1; j < elemCount; ++j) {
            if (Numero[i] == Numero[j]) {

            }
        }
    }
}
void crearnewArr(int Numero[]){
    
}


void insertionSort(int elemtcount, int Numero[]){
    int i,pos,aux;

    for(i=0;i<elemtcount;i++){
        pos = i;
        aux = Numero[i];

        while((pos>0) && (Numero[pos-1] > aux)){
            Numero[pos] = Numero[pos-1];
            pos--;
        }
        Numero[pos] = aux;
    }
}

void selectionSort(int elemtcount, int Numero[])
{
    int i, j, aux, min;

    for (i = 0; i < elemtcount; i++){
        min = i;
        for(j=i+1; j < elemtcount; j++){
            if(Numero[j] < Numero[min]){
                min = j;
            }
        }
        aux = Numero[i];
        Numero[i] = Numero[min];
        Numero[min] = aux;
    }
}

void bubbleSort(int elemtcount, int Numero[]    ) {
    int i, j, aux;
    for (i = 0; i < elemtcount; i++) {
        for (j = 0; j < elemtcount; j++) {
            if(Numero[j] > Numero[j+1]){
                aux = Numero[j];
                Numero[j] = Numero[j+1];
                Numero[j+1] = aux;
            }
        }
    }
}

void shellSort(int elemtcount, int Numero[]){
    int n = elemtcount;
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        
        // Perform an insertion sort for elements at intervals of gap
        for (int i = gap; i < n; ++i) {
            int temp = Numero[i];
            int j;

            // Move elements of arr[0..i-gap] that are greater than temp
            // to positions ahead of their current position
            for (j = i; j >= gap && Numero[j - gap] > temp; j -= gap) {
                Numero[j] = Numero[j - gap];
            }

            // Place temp (the original arr[i]) in its correct position
            Numero[j] = temp;
        }
    }

}

void mergeSort(int Numero[], int inicio, int fin){
    if (inicio < fin)
    {

    }
}

void quickSort(int elemtcount, int Numero[]){

}

void heapSort(int elemtcount, int Numero[]){

}
int main()
{ 
    srand((time(NULL)));
    int limiteIntervalo = rand()%(110000 - 100000 + 1) + 100000;
    int menu = 1;
    int select;
    int Numero[limiteIntervalo];
    int ArrBubble[limiteIntervalo];
    int i,j,aux;
    size_t size = sizeof(Numero);
    size_t elemtcount = size / sizeof(Numero[0]);


    cout << "Tamanio de arreglo: " << elemtcount << endl;
    // Generate and print random values for the array
    cout << "Asignando valores al arreglo";
    for (int i = 0; i < elemtcount; ++i) {
        Numero[i] = rand() % 1000000000 + 1;
    }

    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    shellSort(elemtcount,Numero);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nTiempo transcurrido por Shell Sort es " << duration.count() << " microseconds." << endl;

    start = chrono::high_resolution_clock::now();
    insertionSort(elemtcount,Numero);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "\nTiempo transcurrido por Shell Sort es " << duration.count() << " microseconds." << endl;     

    start = chrono::high_resolution_clock::now();
    bubbleSort(elemtcount,Numero);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "\nTiempo transcurrido por Bubble Sort es " << duration.count() << " microseconds." << endl;     

    /*cout<<"Ascendente: ";
    for(i=0;i<elemtcount;i++)
    {
        cout << Numero[i] << " ";
    }*/
    
   
}