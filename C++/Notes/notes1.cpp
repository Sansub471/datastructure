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
    // Advantage : just add the elements, no need to take care of size
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

    std::cout<<"The matrix is : "<<std::endl;
    int matrix[][4] {12,89,34, 12, 89, 54, 13, 90};
    for(int (&rows)[4] : matrix){
        for(int elem : rows){
            std::cout<<elem<<"\t";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    // C++ 17 update
    int scores[]{1,2,3,4,5,6,7,8,9,10,11,12};

    // get the size of array at runtime
    std::cout<<"use of std::size() method : " << std::endl;
    /*
    int count {std::size(scores)};
    std::cout<<"The size of scores is : " << count << std::endl;
    
    for(size_t i {0}; i< count; ++i){
        std::cout<< "scores [ " << i << "] : " << scores[i] << std::endl;
    }
    */

    // old method is to divide the array size with the size of one element
    int arrCount = sizeof(scores) / sizeof(scores[0]);
    std::cout<< "The number of elements in the array is " << arrCount << std::endl;

    
    return 0;
}
