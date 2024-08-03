#include<iostream>
#include<set>

template<typename T>
    void PrintMultiset(std::multiset<T>& mulset){
        for(auto itr=mulset.begin(); itr!=mulset.end(); ++itr){
            std::cout<< *itr <<"  ";
        }
        std::cout<<std::endl;

        // for(const auto& elem : mulset){
        //     std::cout<< elem << "  ";
        // }
        // std::cout<<std::endl;
    }


template<typename T>
    void PrintDesMultiset(std::multiset<T, std::greater<T>>& mulset){
        for(const auto& elem : mulset){
            std::cout<< elem << "  ";
        }
        std::cout<<std::endl;
    }
int main(){
    std::multiset<int> prime_set = {3,2,7,5,13,11,17,5,5,3,3}; // duplicates allowed
    // multiset in descending order
    std::multiset<int, std::greater<int>> numbers = {2,3,6,7,9,11,4,1,13,27,31,16,3,7,2,3,2,3};

    std::multiset<std::string, std::greater<std::string>> mulsetwords = {"here", "there", "fear", "pear",
                                                    "shear", "gear", "mere", "here", "share"};
    std::cout<<"Multiset of prime numbers : ";
    PrintMultiset(prime_set);

    std::cout<<"Multiset of numbers(DES) : ";
    PrintDesMultiset(numbers);

    std::cout<<"Multiser of words(DES) : ";
    PrintDesMultiset(mulsetwords);


    // Multiset methods:
    // 1. insert() : insert elements into a multiset
    // 2. eraser() : erase all instances of an element
    // 3. clear()  : remove all the elements from a multiset
    // 4. empty()  : check if the multiset is empty
    // 5. size()   : returns the size of the multiset

    numbers.insert(78); mulsetwords.insert("here"); prime_set.insert(7);

    // clear() deletes all the elements in multiset
    mulsetwords.erase("here"); // all occurences
    
    return 0;
}