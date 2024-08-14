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

void PrintArray(std::array<int, 5>& arr){
    std::cout<<"The elements from print function : ";
    for(auto& n : arr){
        std::cout<<n<<"\t";
    }
    std::cout<<std::endl;

}

// The above approach has a limitation, what if we want to print array of size 10, 20, 30 etc.
// use template
template<std::size_t SIZE>
    void ArrayPrinting(std::array<int, SIZE>& arr) {
        std::cout<<"The elements from ArrayPrinting are : ";
        for(auto& e : arr) {
            std::cout<<e<<"\t";
        }
    std::cout<<std::endl;
    }
// SIZE will be replaced with compile-time constant(the size of array)

template<typename T, std::size_t SIZE>
    void PrintingFunction(std::array<T, SIZE>& arr){
    std::cout<<"The elements from Printing Function are : ";
        for(auto& e : arr) {
            std::cout<<e<<"\t";
        }
    std::cout<<std::endl;
    }

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

    // Methods:
    // 1. n.empty() let n be std::array returns true if empty otherwise false
    // 2. n.size() get the number of elements
    // 3. n.fill(value) fill the entire array with 'value'
    // 4. It can be used with STL algorithms.


    // Difference between std::array and C-style array
    // 1. C-style array T[n] can automatically cast to T* while std::array can't.
    // 2. C-style-array doesn't support assignment while std::array<T, N> does.

    // Recommended to use STL array over C-Style array in C++

    PrintArray(numbers);

    ArrayPrinting(numbers);

    PrintingFunction(marks);
    std::array<float, 5> decimals = {22.3, 45.34, 56.34, 9, 78.89};
    PrintingFunction(decimals);

    return 0;
}

// learning electromagnetics and book hunt for the day