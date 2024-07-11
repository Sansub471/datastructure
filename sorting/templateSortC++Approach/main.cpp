#include "sort.hpp"

int main() {
    Array<int> arr;
    arr.randomArray(10, 1, 100);

    std::cout << "Unsorted array: ";
    arr.PrintArray();

    Sort<int> sorter(arr);
    std::cout << "Sorted array: ";
    sorter.bubbleSort();

    return 0;
}
