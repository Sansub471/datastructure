#include<iostream>
#include<unordered_set>

template<typename T>
    void PrintUnMultiset(std::unordered_multiset<T>& unMulSet){
        // for(const auto& elem : unMulSet){
        //     std::cout<< elem << "  ";
        // }
        // std::cout<<std::endl;

        for(auto iter=unMulSet.begin(); iter!= unMulSet.end(); ++iter){
            std::cout<< *iter << "  ";
        }
        std::cout<<std::endl;
    }

int main(){

    std::unordered_multiset<int> unprime_set = {3,2,7,5,13,11,17,5,5,3,3}; // duplicates allowed
    // multiset in descending order
    std::unordered_multiset<int> unnumbers = {2,3,6,7,9,11,4,1,13,27,31,16,3,7,2,3,2,3};

    std::unordered_multiset<std::string> unmulsetwords = {"here", "there", "fear", "pear",
                                                    "shear", "gear", "mere", "here", "share"};
    std::cout<<"Multiset of prime numbers : ";
    PrintUnMultiset(unprime_set);

    std::cout<<"Multiset of numbers : ";
    PrintUnMultiset(unnumbers);

    std::cout<<"Multiser of words : ";
    PrintUnMultiset(unmulsetwords);

    // Methods of unordered multiset
    // 1. insert() : insert elements into an unordered set
    // 2. erase()  : erase all instances of an element
    // 3. clear()  : remove all the elements from a multiset
    // 4. empty()  : check if the multiset is empty
    // 5. size()   : returns the size of the multiset
    // 6. find()   : find the occurence of a value
    // 7. count()  : count the frequency of a value

    // Insert
    unnumbers.insert({1,7,4,3,5,1,7,99});
    unnumbers.insert(98);
    std::cout<<"Numbers after insertion : ";
    PrintUnMultiset(unnumbers);

    // Delete valued from an unordered multiser
    unnumbers.erase(3); // erase all instances of 3
    unnumbers.erase(2);
    unnumbers.erase(1000); // no error thrown if not found
    // clear() remove all
    std::cout<<"Numbers after deletion : ";
    PrintUnMultiset(unnumbers);

    // empty() and size() very clear
    std::cout<<"The size of unprime_set : " << unprime_set.size() << std::endl;

    // find() and count() methods
    // similar to previous lessons
    std::string word = "shear";
    std::unordered_multiset<std::string>::iterator iter = unmulsetwords.find(word);
    // returns the iterator to the element if found, otherwise the end()
    if(iter != unmulsetwords.end()){
        std::cout<< word << " found in the unordered multiset.\n";
    }
    else{
        std::cout<< word << " not found in the unordered multiset.\n";
    }

    int num = 78;
    std::cout<<"Number " << num << " occurs " << unnumbers.count(num) << " times.\n";
    
    
    return 0;
}