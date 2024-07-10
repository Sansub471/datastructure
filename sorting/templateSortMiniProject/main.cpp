#include "arrays.h"
#include "sort.h"

int main(){

    Array<int> arr;
    arr.randomArray(12, 23, 77);

    std::cout<<"The unsorted array is : ";
    arr.PrintArray();

    Sort<int> sorted(arr);
    sorted.bubbleSort();

    std::cout<<"The sorted array is : ";
    //sorted.PrintSort();

    return 0;
}