// STL container vector 
#include<iostream>
#include<vector>

int main(){
    // create a vector of int type
    std::vector<int> numbers {1,2,3,4,5,6};

    // print vector element using ranged loop
    for(int number : numbers){
        std::cout<< number <<"\t";
    }
    return 0;
}