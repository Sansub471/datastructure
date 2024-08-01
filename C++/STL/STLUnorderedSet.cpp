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
    

    std::cout<<"Set of prime numbers : ";
    PrintUnorderedSet(prime_set); // check the output
    // We can't use [] operator to add new element

    
    std::unordered_set<std::string> usetwords = {"here", "there", "fear", "pear",
                                                    "shear", "gear", "mere"};
    std::cout<<"The random words are : ";
    PrintUnorderedSet(usetwords);

    // Range initialization method
    std::unordered_set<std::string>::iterator itr = usetwords.begin();
    //++itr; ++itr; // index 2
    std::unordered_set<std::string> words(usetwords.begin(), usetwords.end());
    std::cout<<"Ranged intialized words : ";
    PrintUnorderedSet(words);

    // Methods 
    // 1. insert() : inserts an element 
    // 2. count()  : returns 1 if the specified value exists otherwise 0
    // 3. find()   : returns the iterator to the element with the specified value
    //               else returns end() iterator
    // 4. size()   : returns the number of unique elements
    // 5. empty()  : returns true if the unordered set is empty
    // 6. erase()  : removes element with the specified value
    // 7. clear()  : removes all elements


    // Inser()
    std::unordered_set<std::string> countries;
    countries.insert("Nepal");
    countries.insert({"China", "India", "USA", "England"});

    std::cout<<"The countries are : ";
    PrintUnorderedSet(countries);

    // erase()
    countries.erase("India");
    countries.erase("Pakistan"); // no error if key not found

    PrintUnorderedSet(countries);

    // clear() : removes all

    // Check if value exists
    std::string countryName = "Pakistan";
    // find() and count() similar to before.

    // size() and empty() self explanatory
}