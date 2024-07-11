#ifndef A_HPP
#define A_HPP

#include <iostream>

template <typename T>
class A {
private:
    T* ptr;

public:
    A(T* p) : ptr(p) {}
    ~A() {
        delete ptr;
    }

    A(const A& other) = delete;            // Disable copy constructor
    A& operator=(const A& other) = delete; // Disable copy assignment

    T getValue() const {
        return *ptr;
    }

    void setValue(T value) {
        *ptr = value;
    }
};

#endif // A_HPP
