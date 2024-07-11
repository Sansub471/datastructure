#ifndef B_HPP
#define B_HPP

#include "A.hpp"

template <typename T>
class B {
private:
    A<T>& a;

public:
    B(A<T>& aObj) : a(aObj) {}

    void printValue() const {
        std::cout << "Value: " << a.getValue() << std::endl;
    }

    void setValue(T value) {
        a.setValue(value);
    }
};

#endif // B_HPP
