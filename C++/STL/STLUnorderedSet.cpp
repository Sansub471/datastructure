#include<iostream>
#include<unordered_set>

template<typename T>
    void PrintUnorderedSet(std::unordered_set<T>& unorderSet){
        // for(const auto& elem: unorderSet){
        //     std::cout<< elem << "  ";
        // }
        // std::cout<<std::endl;

        for(auto itr=unorderSet.begin(); itr!=unorderSet.end(); ++itr){
            std::cout<< *itr << "  ";
        }
        std::cout<<std::endl;
        }

int main(){

    // Creating unorderedset
    std::unordered_set<int> prime_set = {3,2,7,5,13,11,17,5,5,3,3}; // duplicates will be removed
    std::unordered_set<std::string> words; // empty set

    std::cout<<"Set of prime numbers : ";
    PrintUnorderedSet(prime_set); // check the output
    // We can't use [] operator to add new element


    std::unordered_set<std::string> usetwords = {"here", "there", "fear", "pear",
                                                    "shear", "gear", "mere"};
    PrintUnorderedSet(usetwords);

}