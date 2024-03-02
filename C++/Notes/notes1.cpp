// A note of interesting looking code for me
// Test new codes that are interesting to me

#include<iostream>
int main(){
    // for loop
    // use size_t : a representation of some unsigned int for positive numbers [sizes]
    const size_t COUNT = 10;
    for(size_t i{0};i < COUNT; i++){
        std::cout<<"I have a life to live, find a way to discipline yourself."<<std::endl;
    }
    std::cout<<"End of life lesson."<<std::endl;
    std::cout<<"The size of size_t is : " << sizeof(size_t) << std::endl;

    // Array declaratio: omit size
    int class_sizes[] {10, 12, 15, 11, 18, 17};
    std::cout<<"Let's look at the values of the array : " << std::endl;
    for(auto value : class_sizes){
        std::cout<< "value : " << value << std::endl;
    }

    // This is range based for loop added since C++11 and later
    // Read more : https://www.geeksforgeeks.org/range-based-loop-c/
    std::cout<<"Multi dimensional array using range-based for loop : " <<std::endl;
    int numbers[][2] {17, 77, 37, 15};
    for(int (&rows)[2] : numbers){
        for(int elem: rows){
            std::cout<< elem << "\t";
        }
        std::cout<<std::endl;
    }
    return 0;
}
