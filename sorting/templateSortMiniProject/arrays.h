#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <new> // For std::nothrow
#include <cstdlib> // For std::rand, std::srand
#include <ctime> // For std::time
#include <type_traits> // For std::is_integral_v
#include <cmath>

//#include <algorithm> // For std::swap
template <typename T> class Array{
    private:
        T* A;
        unsigned int N; // array size
    public:
    Array();
    Array(T* arr, unsigned int size);
    ~Array();

    unsigned int getSize();
    T* getArray();
    
    T* InputArray();
    void PrintArray();

    void swap(T* a, T* b);
    T* randomArray(unsigned int size, T minValue, T maxValue);    
};

//#include"arrays.cpp" // include implementation for template class

#endif