#include "B.hpp"

int main() {
    int* intPtr = new int(42);
    A<int> a(intPtr);
    B<int> b(a);

    b.printValue(); // Should print: Value: 42

    b.setValue(100);
    b.printValue(); // Should print: Value: 100

    return 0;
}
