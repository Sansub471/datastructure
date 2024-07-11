#ifndef SORT_HPP
#define SORT_HPP

#include "arrays.hpp"

template <typename T>
class Sort {
private:
    Array<T> A;

public:
    Sort(const Array<T>& array) : A(array) {}
    void bubbleSort();
};

template <typename T>
void Sort<T>::bubbleSort() {
    std::vector<T> array = A.getArray();
    unsigned int size = A.getSize();

    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                A.swap(array[j], array[j + 1]);
            }
        }
    }

    for (const auto& elem : array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

#endif // SORT_HPP
