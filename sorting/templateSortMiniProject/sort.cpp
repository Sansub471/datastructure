#include"sort.h"

template <typename T> Sort<T>::Sort(const Array<T>& array, bool debug) : Arr(array), debug(debug){}

// Destructor
template <typename T> Sort<T>::~Sort() {
    // Destructor body can be empty as there are no additional resources to manage
}

template <typename T> void Sort<T>:: PrintSort(){
    Arr.PrintArray();
}

template <typename T> void Sort<T>:: bubbleSort(){
    unsigned int N = Arr.getSize();
    T* A = Arr.getArray();

    for(int i=0; i< N - 1; i++){
        bool swapped = false;
        for(int j=0; j< N - i - 1; j++){
            if(A[j] > A[j+1]){
                Arr.swap(&A[j], &A[j+1]);
                swapped = true;
            }
        }

        //printf("Pass : %d\n", i);
        //PrintArray(A, N);

        // if no two elements swapped by inner loop, break
        if(swapped == false) break;
    }

    Arr.PrintArray();
}