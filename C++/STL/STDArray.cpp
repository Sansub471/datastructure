// C++ std::array
#include<iostream>
#include<array>

// // declaration of std::array 
// std::array<T, N> array_name;
// where,

// T - Type of element to be stored
// N - Number of elements in the array
// Here is how we declare a std::array of size 5 that stores a list of numbers:


// source : https://www.programiz.com/cpp-programming/std-array
int main(){
    // Two methods of initialization
    // Initializer list
    std::array<int, 5> numbers = {1,2,3,4,5};

    // Uniform initialization
    std::array<int, 5> marks {10, 20, 30, 40, 50};

    std::cout<<"The elements of array are :";
    for(const int num: marks){
        std::cout<< num << '\t';
    }
    std::cout<<std::endl;

    // Accessing elements using [] oprator and index
    std::cout<<"The first number is " << numbers[0] << std::endl;

    // It doesn't check the out of bound error.
    // The at method checks the out of bound error.
    std::cout<<"The third element is " << numbers.at(2) << std::endl;
    // numbers.at(8) throws std::out_of_range exception

    // Modify the elements
    numbers[2] = 77;
    numbers.at(0) = 17;
    std::cout<<"The first number is " << numbers[0] << std::endl;
    std::cout<<"The third element is " << numbers.at(2) << std::endl;
    return 0;
}