#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#ifndef ARRAY_H
#define ARRAY_H
#include"arrays.h"
#endif

template <typename T> class Sort{
    private:
    Array<T> Arr;

    public:
    // constructor that takes array object.
    Sort(const Array<T>& array) : Arr(array){};


};

#endif