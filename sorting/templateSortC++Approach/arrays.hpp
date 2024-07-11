#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <type_traits>

template <typename T>
class Array {
private:
    std::vector<T> A;

public:
    Array() = default;
    Array(const std::vector<T>& arr) : A(arr) {}

    unsigned int getSize() const { return A.size(); }
    void InputArray();
    void PrintArray() const;
    void swap(T& a, T& b) { std::swap(a, b); }
    std::vector<T> randomArray(unsigned int size, T minValue, T maxValue);

    const std::vector<T>& getArray() const { return A; }
};

template <typename T>
void Array<T>::InputArray() {
    unsigned int size;
    std::cout << "Enter array size: ";
    std::cin >> size;
    A.resize(size);
    std::cout << "Enter array elements: ";
    for (auto& elem : A) {
        std::cin >> elem;
    }
}

template <typename T>
void Array<T>::PrintArray() const {
    for (const auto& elem : A) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> Array<T>::randomArray(unsigned int size, T minValue, T maxValue) {
    if (minValue > maxValue) {
        std::swap(minValue, maxValue);
    }

    A.resize(size);
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (auto& elem : A) {
        if constexpr (std::is_integral_v<T>) {
            elem = static_cast<T>((std::rand() % (maxValue - minValue + 1)) + minValue);
        } else {
            double randomValue = (static_cast<double>(std::rand()) / RAND_MAX) * (maxValue - minValue) + minValue;
            randomValue = std::round(randomValue * 1000.0) / 1000.0;
            elem = static_cast<T>(randomValue);
        }
    }

    return A;
}

#endif // ARRAY_HPP