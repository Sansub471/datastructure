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
    void PrintSetDes(std::set<T>& myset){
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

    std::set<std::string, std::greater<std::string>> setwords = {"here", "there", "fear", "pear",
                                                    "shear", "gear", "mere"};
    std::cout<<"Set of words in descending order is : ";
    PrintSetDes(setwords);

    // Set methods
    // 1. insert() : insert elements into a set
    // 2. erase() : delete elements from a set
    // 3. clear()  : remove all the elements from a set
    // 4. empty()  : check if the set is empty
    // 5. size()   : returns the size of the set

    // Add values to the set
    words.insert("name"); words.insert("game");
    words.insert("fame"); words.insert("shame");
    words.insert("tame"); words.insert("lame");
    words.insert("pame");
    words.insert("name");
    words.insert("name");

    std::cout<<"The words are : ";
    PrintSet(words);

    // check if an element exists in the set
    int num = 7;
    if(numbers.count(num)){
        std::cout<<"The numbers set has "<< num<< std::endl;
    }
    else{
        std::cout<<"The numbers set doesn't have " << num << std::endl;
    }

    // count() returns 1 if the element exists

    // Delete an element from the set
    // clear() deletes all the elements

    words.erase("pame");
    std::cout<<"The words after erasing : ";
    PrintSet(words);

    // empty() and size() methods are called capacity methods.
    // function is self explanatory
    return 0;
}