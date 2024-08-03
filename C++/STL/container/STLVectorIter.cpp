// Vector iterators
// are used to point to the memory address of a vector element.
// In some ways, the act like pointers.
#include<iostream>
#include<vector>

// Syntax : std::vector<T>::iterator iterName;

int main(){
    std::vector<int> num = {1,2,3,4,5};
    std::vector<int>::iterator iter1;

    iter1 = num.begin(); // returns an iterator the points to the first element of the vector
    std::cout<<"Element pointed by iterator : " << *iter1 << std::endl;
    //std::cout<<"Iter1 : "<< iter1 << std::endl;

    iter1 = num.end();
    std::cout<<"The theoretical last element : " << *iter1 << std::endl;
    // end() func points to the theoretical element that comes after the final 
    // element of the vector.

    iter1 = num.end() - 1; // the last element
    std::cout<<"The last element is : " << *iter1 << std::endl;

    iter1 = num.begin();
    iter1 += 2;
    std::cout<<"The element at index 1, num[2] : " << *iter1 << std::endl;
    

    // Iterate through vector using iterators
    std::vector<int>::iterator iter;
    
    // use iterator with for loop
    std::cout<<"The elements of vector are : ";
    for(iter = num.begin(); iter != num.end(); ++iter){
        std::cout<< *iter << "\t";
    }
    std::cout<<std::endl;
    return 0;
}