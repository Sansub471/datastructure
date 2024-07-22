#include<iostream>
#include<vector>

// Syntax : std::vector<T> vector_name;
// The type parameter <T> specifies the type of the vector.
// The size is not required, it can grow dynamically during execution.

int main(){
    // Initialization Method I
    // 1. Initializer list
    std::vector<int> vec1 = {1,2,3,4,5};

    // 2. Uniform initilization
    std::vector<int> vec2 {13,17,77, 27, 37};

    // Initialization Method II
    std::vector<int> vec3(5,12);// 5 is size and 12 is the value
    // equivalent to : std::vector<int> vec3 = {12,12,12,12,12}

    // cosnt reference ranged loop
    std::cout<<"The vector2 elements : ";
    for(const int& num : vec2){
        std::cout<< num << "\t";
    }
    std::cout<<std::endl;

    // 'const num&' : is a constant reference to each element of the vector
    // it avoids copying element to 'num'
    // 'const' ensures elements are not modified in the loop
    // efficient for large complex values

    // normal ranged loop
    std::cout<<"The vector3 elements : ";
    for(int i : vec3){
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
    // Less efficient for large complex values.
    // copies the elements of vec3 to 'int i'

    return 0;
}
