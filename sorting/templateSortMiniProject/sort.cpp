#include"sort.h"

template <typename T> Sort<T>::Sort(const Array<T>& array):  Arr(array){}

// // Destructor
// template <typename T> Sort<T>::~Sort() {
//     // Destructor body can be empty as there are no additional resources to manage
//     std::cout<<"This is Sort deconstructor."<<std::endl;
//     std::cout<<"Trying to free : "<< Arr.getArray()<< std::endl;

// }

template <typename T> void Sort<T>:: PrintSort(){
    Arr.PrintArray();
}

template <typename T> void Sort<T>:: bubbleSort(){
    unsigned int N = Arr.getSize();
    T* arrPtr = Arr.getArray();

    for(int i=0; i< N - 1; i++){
        bool swapped = false;
        for(int j=0; j< N - i - 1; j++){
            if(arrPtr[j] > arrPtr[j+1]){
                Arr.swap(&arrPtr[j], &arrPtr[j+1]);
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