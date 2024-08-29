// Catching all types of exception
// If we don't know which exception occurs, we can catch all exception using 

// try {
//     // code
// }
// catch (...) {
//     // code
// } 

// (...) is called ellipsis symbol

// Knowing the right type of exception is important

// Multiple types of exception can occur from same block of code, it can be handled like : 

// try {
//     // code
// } 
// catch (exception1) {
//     // code
// } 
// catch (exception2) {
//     // code
// } 
// catch (...) {
//     // code
// }

// The last catch() block is called the default block which is optional, but if used it must be the last catch() block
// cath (...){
    // code 
//}

#include <iostream>
int main() {
    
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index;
    
    std::cout << "Enter array index: ";
    std::cin >> index;
    
    try {
        
        // throw exception if array out of bounds
        if (index >= 4)
            throw "Error: Array out of bounds!";
            
        // not executed if array is out of bounds
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
    
        std::cout << "Enter denominator: ";
        std::cin >> denominator;

        // throw exception if denominator is 0
        if (denominator == 0)
            throw 0;

        // not executed if denominator is 0
        arr[index] = numerator / denominator;
        std::cout << "The quotient is : " <<arr[index] << std::endl;
    }

    // catch "Array out of bounds" exception
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    // catch "Divide by 0" exception
    catch (int num) {
        std::cout << "Error: Cannot divide by " << num << std::endl;
    }

    // catch any other exception
    catch (...) {
        std::cout << "Unexpected exception!" << std::endl;
    }
    
    return 0;    
}

// Exception	Description
// std::exception	The parent class of all C++ exceptions.
// std::bad_alloc	Thrown when a dynamic memory allocation fails.
// std::bad_cast	Thrown by C++ when an attempt is made to perform a dynamic_cast to an invalid type.
// std::bad_exception	Typically thrown when an exception is thrown and it cannot be rethrown.

// There are many more other exception, know it later on.