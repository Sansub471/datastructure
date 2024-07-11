#include "arrays.h"
#include "sort.h"

#include "arrays.cpp"
#include "sort.cpp"

int main(){

    Array<int> arr;
    arr.randomArray(12, 23, 77);

    std::cout<<"The unsorted array is : ";
    arr.PrintArray();

    std::cout<<"The unsorted from Sort class is : ";
    Sort<int> sorted(arr);
    sorted.PrintSort();

    std::cout<<"The sorted array is : \n";
    //sorted.PrintSort();

    return 0;
}