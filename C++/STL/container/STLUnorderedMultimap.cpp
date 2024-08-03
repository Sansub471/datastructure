#include<iostream>
#include<unordered_map>

template<typename key, typename value>
    void PrintUnorderedMultimap(std::unordered_multimap<key, value>& un_mulMap){
        for(const auto& pair: un_mulMap){
            std::cout<<pair.first << " --> " << pair.second << std::endl;
        }
        std::cout<<std::endl;

        for(auto itr=un_mulMap.begin(); itr != un_mulMap.end(); ++itr){
            std::cout<<itr->first << " --> " << itr->second << std::endl; // (*itr).first/second
        }
        std::cout<<std::endl;
        // declare the iterator
        //typename std::unordered_multimap<key,value>::iterator itr;
    }

int main(){
        // some students might score equl marks hence same rank
    std::unordered_multimap<int, std::string> students = {
        {1, "Subekshya"}, 
        {3, "Rabin"}, 
        {5, "Babin"}, 
        {2, "Ramesh"}, 
        {6, "Sumesh"},
        {4, "Joe"}, 
        {7, "Rachel"}, 
        {9, "Ranjana"}, 
        {8, "Subekshya"},
        {2, "Rabina"},
        {1, "Subina"},
        {3, "Sabina"},
        {7, "Aayesha"},
        {3, "Dipendra"}
    };
    
    // There can be more than one words from a given alphabet
    std::unordered_multimap<char, std::string> alphabet {
        {'A', "Apple"}, 
        {'B', "Ball"}, 
        {'C', "Cat"}, 
        {'D', "Dog"}, 
        {'E', "Elephant"},
        {'F', "Fan"}, 
        {'G', "Gun"},
        {'A', "Aeroplane"},
        {'B', "Bag"},
        {'C', "Cow"},
        {'D', "Donkey"}
        };

    std::cout<<"The student's rank and their names are : \n";
    PrintUnorderedMultimap(students);

    std::cout<<"The alphabets are : \n";
    PrintUnorderedMultimap(alphabet);

    // The methods
    // 1. insert() : inserts elements into the multimap
    // 2. find()   : finds the value of the given key
    // 3. count()  : counts the number of elements with a specific key
    // 4. empty()  : checks the size of the multimap
    // 5. erase()  : deletes an element from the multimap
    // 6. clear()  : deletes all values from the multimap

    // insert elements
    students.insert({{1, "Subash"}, {3, "Sandhya"}});
    students.insert({7, "Susham"});

    //find a key
    // iterator to the element if the key is found 
    // iterator to the end of the container if the key is not found
    char key = 'A';
    auto itr = alphabet.find(key); // first occurence
    if(itr != alphabet.end()){
        std::cout<<"The key-value pair is : " << itr->first << " -- > " << itr->second << std::endl;
    }
    else{
        std::cout<<"The key " << key << " is not found."<< std::endl;
    }

    // count the occurence 
    std::cout<<"The key: " << key << " occurs " << alphabet.count(key) << " times."<< std::endl;
    
    // empty() and size() same as before


    // Delete an element
    key = 'C'; 
    alphabet.erase(key); // delete all instances of key

    // clear() deletes every element from the multimap
    

    return 0;
}