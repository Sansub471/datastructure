#include<iostream>
#include<set>

template<typename T>
    void PrintSet(std::set<T>& myset){
        for(const T& elem : myset){
            std::cout<<elem<<" ";
        }
        std::cout<<std::endl;
    }

template<typename T>
    void PrintSetDes(std::set<T, std::greater<T>>& myset){
        for(const T& elem : myset){
            std::cout<<elem<<" ";
        }
        std::cout<<std::endl;
    }

int main(){
    // Creating set
    std::set<int> prime_set = {3,2,7,5,13,11,17,5,5,3,3}; // duplicates will be removed
    std::set<std::string> words; // empty set

    std::cout<<"Set of prime numbers : ";
    PrintSet(prime_set); // check the output
    // no duplicates and in ascending order
    // We can't use [] operator to add new element

    // set in descending order
    std::set<int, std::greater<int>> numbers = {2,3,6,7,9,11,4,1,13,27,31,16};
    std::cout<<"Set of numbers in descending order : ";
    PrintSetDes(numbers);






    return 0;
}