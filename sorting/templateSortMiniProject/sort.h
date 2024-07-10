#ifndef SORT_H
#define SORT_H

//#ifndef ARRAY_H
//#define ARRAY_H
#include"arrays.h"
//#endif

template <typename T> class Sort{
    private:
    Array<T> Arr;
    bool debug;

    public:
    // constructor that takes array object.
    Sort(const Array<T>& array, bool debug=false);
    ~Sort();//Deconstructor

    void PrintSort();

    void bubbleSort();
    
};

#include"sort.cpp"

#endif