#include<iostream>
#include<vector>

// Syntax : std::vector<T> vector_name;
// The type parameter <T> specifies the type of the vector.
// The size is not required, it can grow dynamically during execution.

void PrintVector(std::vector<int>& vec){
    std::cout<<"The elements are : ";
    for(const int& i : vec){
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
}


template<typename T>
    void PrintingVector(std::vector<T>& vec){
        std::cout<<"The elements from printing functions : ";
        for(const int& elem : vec){
            std::cout<<elem<<"\t";
        }
    std::cout<<std::endl;
    }
int main(){
    // Initialization Method I
    // 1. Initializer list
    std::vector<int> vec1 = {1,2,3,4,5};

    // 2. Uniform initilization
    std::vector<int> vec2 {13,17,77, 27, 37};

    // Initialization Method II
    std::vector<int> vec3(5,12);// 5 is size and 12 is the value
    // equivalent to : std::vector<int> vec3 = {12,12,12,12,12}

    std::vector<double> vec4 {12.34, 56.34, 76.23, 89.23, 99.23, 34.12};

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


    // Basic operations
    // 1. Add elements : insert an element into the end of the vector
    vec2.push_back(99);
    vec2.push_back(37);

    PrintVector(vec2);
    PrintingVector(vec4);
    return 0;
}
