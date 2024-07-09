#include<iostream>
#include <new> // For std::nothrow
#include <cstdlib> // For std::rand, std::srand
#include <ctime> // For std::time
#include <type_traits> // For std::is_integral_v

//#include <algorithm> // For std::swap

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
        std::cerr<<"Memory allocation failed for the array. "<< e.what()
        <<std::endl;
        A = nullptr; N = 0;
        return nullptr;
    }

    for(int i=0; i < N; i++){
        std::cout<<"Element ["<<i<<"]"; std::cin>>A[i];
    }
    return A;
}

template <typename T> void Array<T>::PrintArray(){
    if(A == nullptr || N <=0 ){
        std::cerr<<"Can't print empty array!"<<std::endl;
        return;
    }

    for(int i=0; i < N; i++){
        std::cout<<*A<<"\t";
        A++;
    }
    std::cout<<std::endl;
}

// try std::swap() instead
template <typename T> void Array<T>::swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

// get an array with random values
template <typename T> T* Array<T>::randomArray(unsigned int size, T minValue, T maxValue){
    N = size;
    if(minValue > maxValue){
        swap(&minValue, &maxValue);
    }

    A = new(std::nothrow) T[N];
    if(A == nullptr){
        std::cerr<<"Memory allocation failed!"<<std::endl;
        return nullptr;
    }

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Fill the array with random values within the specified range
    for (std::size_t i = 0; i < N; ++i) {
        if constexpr (std::is_integral_v<T>) {
            A[i] = static_cast<T>((std::rand() % (maxValue - minValue + 1)) + minValue);
        } else {
            A[i] = static_cast<T>((static_cast<double>(std::rand()) / RAND_MAX) * (maxValue - minValue) + minValue);
        }
    }
    return A;
}

int main(){

    int A[] = {89, 34, 1, 3, -15, 37, 12, 23, 21, 10};
    unsigned int N = sizeof(A) / sizeof(A[0]);

    Array<int> arr1(A, N);
    arr1.PrintArray();

    // Array<float> arr2;
    // float* ptr = arr2.InputArray();
    // if(ptr == nullptr){
    //     std::cerr<<"Null pointer returned."<<std::endl;
    // }
    // arr2.PrintArray();

    Array<int> arr3;
    int* randintArr = arr3.randomArray(12, 23, 77);

    //std::cout<< randintArr << std::endl;
    if(randintArr == nullptr){
        std::cerr<<"Null pointer returned."<<std::endl;
    }

    arr3.PrintArray();

    Array<float> arr4;
    float* randfloatArr = arr4.randomArray(15, 10.45f, 97.77f);

    //std::cout<< randintArr << std::endl;
    if(randintArr == nullptr){
        std::cerr<<"Null pointer returned."<<std::endl;
    }

    arr4.PrintArray();
    return 0;
}