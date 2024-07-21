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
    
    return 0;
}