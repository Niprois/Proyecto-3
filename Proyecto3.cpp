#include <iostream>
#include <algorithm>
#include <chrono>
#include <windows.h>
#include <unordered_set>
#include <random>
#include <stack>
#include <vector>

using namespace std;

void checkAndChange(int elemCount, int Numero[]) {
    
    srand(time(0));

    for (int i = 0; i < elemCount; ++i) {
        for (int j = i + 1; j < elemCount; ++j) {
            if (Numero[i] == Numero[j]) {

            }
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

void merge(int Numero[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = Numero[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = Numero[mid + 1 + j];


    int i = 0;     
    int j = 0;     
    int k = left;  

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            Numero[k] = L[i];
            i++;
        } else {
            Numero[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        Numero[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        Numero[k] = R[j];
        j++;
        k++;
    }
}

//
//
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partition(int inArray[], int low, int high) {
    int i = low - 1;
    int pivot = inArray[high];

    for (int j = low; j < high; j++) {
        if (inArray[j] <= pivot) {
            i++;
            int temp = inArray[i];
            inArray[i] = inArray[j];
            inArray[j] = temp;
        }
    }

    int temp = inArray[i + 1];
    inArray[i + 1] = inArray[high];
    inArray[high] = temp;

    return i + 1;
}

void quickSortIterative(int arr[], int low, int high) {
    stack<int> s;
    s.push(low);
    s.push(high);

    while (!s.empty()) {
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            s.push(low);
            s.push(pivotIndex - 1);
        }

        if (pivotIndex + 1 < high) {
            s.push(pivotIndex + 1);
            s.push(high);
        }
    }
}

void heapify(int inArray[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && inArray[left] > inArray[largest]){
        largest = left;
    }

    if (right < n && inArray[right] > inArray[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = inArray[i];
        inArray[i] = inArray[largest];
        inArray[largest] = temp;

        heapify(inArray, n, largest);
    }
}

void heapSort(int inArray[], int size){
    int s = size;
    
    for (int i=(s/2)-1; i>=0; i--){
        heapify(inArray, s, i);
    }

    for (int i=s-1; i>=0; i--) {
        int temp = inArray[0];
        inArray[0] = inArray[i];
        inArray[i] = temp;

        heapify(inArray, i, 0);
    }
}
void copyArray(const int source[], int destination[], int size) {
    for (int i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}

int main()
{ 
    srand((time(NULL)));
    int loopead = 1;
    int select, Change, loop;
    int limiteIntervalo = 0;
    int i,j,aux;
    do{

    cout << "Seleccione tipo de carrera: \n1) Cola de espera (100.000 a 120.000)\n2) Trazabilidad de objetos (15.000 a 22.500)\n3) Eventos de cada escenario (60.000 a 80.000)\n4) Salir.";
    cin >> Change;
    if (Change == 1)
    {
        cout << "Selecciono Cola de espera." << endl;
        limiteIntervalo = rand()%(110000 - 100000 + 1) + 100000;
    }
    else if(Change == 2){
        cout << "Selecciono Trazabilidad de objetos." << endl;        
        limiteIntervalo = rand()%(22501 - 15000) + 15000;
    }
    else if (Change == 3){
        cout << "Selecciono Eventos de cada escenario." << endl;        
        limiteIntervalo = rand()%(80001 - 60000) + 60000;
    }else if(Change == 4)
    {
        cout << "Adios!";
        return 0;
    }else {
        limiteIntervalo = rand()%(22501 - 15000) + 15000;        
    }
    int Numero[limiteIntervalo];
    int PhNumero[limiteIntervalo];    
        size_t size = sizeof(Numero);
        size_t elemtcount = size / sizeof(Numero[0]);       
    cout << "Seleccione el tipo de arreglo:\n1) Ordenado\n2) ordenado inverso\n3) Aleatorio\n4) Aleatorio con duplicados " << endl;
    cin >> Change;
    if(Change == 1){     
        cout << "Asignando valores al arreglo en modo ordenado..." << endl;
        for (int i = 0; i < elemtcount; ++i) {
            Numero[i] = i;
        }            
    }
    else if(Change == 2){     
        cout << "Asignando valores al arreglo en modo ordenado inverso..." << endl;
        for (int i = 0; i < elemtcount; ++i) {
            Numero[i] = elemtcount - i;
        } 
    }    
    else if(Change == 3){     
        cout << "Asignando valores al arreglo en modo aleatorio..." << endl;
        for (int i = 0; i < elemtcount; ++i) {
            Numero[i] = i;
        }            
        for (int i=0; i<(elemtcount/2); i++){
        int x = rand()%elemtcount;
        int y = rand()%elemtcount;
        int temp = Numero[x];
        Numero[x] = Numero[y];
        Numero[y] = temp;  
    }
    }
    else if(Change == 4){
        size_t size = sizeof(Numero);
        size_t elemtcount = size / sizeof(Numero[0]);        
        cout << "Asignando valores al arreglo en modo aleatorio con duplicados..." << endl;
        for (int i = 0; i < elemtcount; ++i) {
            Numero[i] = rand() % 1000000000 + 1;
        }            
    }            
    
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);    
    copyArray(Numero,PhNumero,elemtcount);

    cout << "Empezar carrera." << endl;
    start = chrono::high_resolution_clock::now();
    insertionSort(elemtcount,PhNumero);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    cout << "\nTiempo transcurrido por insertion Sort es " << duration.count() << " microseconds." << endl;
    copyArray(Numero,PhNumero,elemtcount);

    start = chrono::high_resolution_clock::now();
    selectionSort(elemtcount,PhNumero);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nTiempo transcurrido por selection Sort es " << duration.count() << " microseconds." << endl;
    copyArray(Numero,PhNumero,elemtcount);

    start = chrono::high_resolution_clock::now();
    shellSort(elemtcount,PhNumero);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nTiempo transcurrido por shell Sort es " << duration.count() << " microseconds." << endl;
    copyArray(Numero,PhNumero,elemtcount);          

    start = chrono::high_resolution_clock::now();
    mergeSort(PhNumero,0, elemtcount-1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nTiempo transcurrido por merge Sort es " << duration.count() << " microseconds." << endl;
    copyArray(Numero,PhNumero,elemtcount);                                  

    start = chrono::high_resolution_clock::now();
    quickSortIterative(PhNumero, 0 , elemtcount-1);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nTiempo transcurrido por quick Sort es " << duration.count() << " microseconds." << endl;
    copyArray(Numero,PhNumero,elemtcount);          

    start = chrono::high_resolution_clock::now();
    heapSort(PhNumero, elemtcount);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nTiempo transcurrido por heap Sort es " << duration.count() << " microseconds." << endl;      
        
    } while (loop);
    

   
}