#include <iostream>
#include <algorithm>
#include <chrono>
#include <unordered_set>
#include <random>

using namespace std;

void checkAndChange(int elemtcount, int Numero[]) {
    for (int i = 0; i < elemtcount; ++i) {
        for (int j = i + 1; j < elemtcount; ++j) {
        }
    }
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

void bubbleSort(int elemtcount, int Numero[]) {
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

}

void mergeSort(int elemtcount, int Numero[]){

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
    int i,j,aux;
    size_t size = sizeof(Numero);
    size_t elemtcount = size / sizeof(Numero[0]);


    cout << "Tamanio de arreglo: " << elemtcount << endl;
    // Generate and print random values for the array
    cout << "Asignando valores al arreglo";
    for (int i = 0; i < elemtcount; ++i) {
        Numero[i] = rand() % 5000000 + 1;
    }
    cout << endl;
    checkAndChange(elemtcount, Numero);
    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    insertionSort(elemtcount,Numero);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);


    
    cout << "Tiempo transcurrido por Bubble Sort es " << duration.count() << " microseconds." << endl;    
}