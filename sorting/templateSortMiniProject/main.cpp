#include <iostream>
#include "arrays.h"
#include "sort.h"

int main(){

    Array<int> arr;
    arr.randomArray(12, 23, 77);

    std::cout<<"The unsorted array is : ";
    arr.PrintArray();

    Sort<int> sorted(arr);

    sorted.bubbleSort();
    std::cout<<"The sorted array is   : ";
    sorted.PrintSort();

    std::cout<<std::endl;

    int A[] = {89, 34, 1, 3, -15, 37, 12, 23, 21, 10};
    unsigned int N  = sizeof(A) / sizeof(A[0]);

    Array<int> arr1(A, N);
    std::cout<<"The unsorted array is : ";
    arr1.PrintArray();

    Sort<int> sorted1(arr1);
    std::cout<<"The sorted array is   : ";
    sorted1.bubbleSort();
    sorted1.PrintSort();

    std::cout<<std::endl;

    Array<float> arr2;
    float* ptr = arr2.InputArray();
    if(ptr == nullptr){
        std::cerr<<"Null pointer returned."<<std::endl;
    }
    std::cout<<"The unsorted array is : ";
    arr2.PrintArray();

    Sort<float> sorted2(arr2);
    sorted2.bubbleSort();
    std::cout<<"The sorted array is   : ";
    sorted2.PrintSort();
    std::cout<<std::endl;

    Array<float> arr3;
    float* randfloatArr = arr3.randomArray(15, 10.45f, 97.77f);
    if(randfloatArr == nullptr){
        std::cerr<<"Null pointer returned."<<std::endl;
    }
    std::cout<<"The unsorted array is : ";
    arr3.PrintArray();

    Sort<float> sorted3(arr3);
    sorted3.bubbleSort();
    std::cout<<"The sorted array is   : ";
    sorted3.PrintSort();

    return 0;
}

// Start the day