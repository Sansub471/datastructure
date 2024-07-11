#ifndef SORT_H
#define SORT_H

#include"arrays.h"

template <typename T> class Sort{
    private:
    Array<T> Arr;
    //bool debug = false;

    public:
    // constructor that takes array object.
    Sort(const Array<T>& array);
    //~Sort();//Deconstructor

    void PrintSort();

    void bubbleSort();
    
};

//#include"sort.cpp"

#endif