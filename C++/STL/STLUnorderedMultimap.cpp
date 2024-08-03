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

    return 0;
}