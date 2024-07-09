#include<iostream>

#include"arrays.h"

template <typename T> Array<T>::Array(){
    A = nullptr;
    N = 0;
}

// creating object with parameterized constructor, passing array.
// T arr[] is same as T* arr
template <typename T> Array<T>::Array(T* arr, unsigned int size){
    A = new T[size];
    N = size;
    for(int i=0; i < size; i++){
        A[i] = arr[i];
    }
}

template <typename T> unsigned int Array<T>::getSize(){
    return N;
}

template <typename T> T* Array<T>::InputArray(){
    std::cout<<"Give the size of array : "; std::cin>>N;
    // Allocate memory for array and get the input.
    try{
        A = new T[N];
    }

    catch(const std::bad_alloc& e){
        std::cout<<"Memory allocation failed for the array. "<< e.what()
        <<std::endl;
    }
    
    for(int i=0; i < N; i++){
        std::cout<<"Element ["<<i<<"]"; std::cin>>A[i];
    }
    return A;
}

template <typename T> void Array<T>::PrintArray(){
    if(A == nullptr || N <=0 ){
        std::cout<<"Can't print empty array!"<<std::endl;
        return;
    }

    for(int i=0; i < N; i++){
        std::cout<<*A<<"\t";
        A++;
    }
    std::cout<<std::endl;
}

int main(){

    int A[] = {89, 34, 1, 3, -15, 37, 12, 23, 21, 10};
    unsigned int N = sizeof(A) / sizeof(A[0]);

    Array<int> arr1(A, N);
    arr1.PrintArray();

    Array<float> arr2;
    arr2.InputArray();
    arr2.PrintArray();
    return 0;
}