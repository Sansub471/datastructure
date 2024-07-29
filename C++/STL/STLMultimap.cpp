#include<iostream>
#include<map>

// Revision note : 
    // iter is pointer hence arrow operator
    // iter-> is same as (*iter).first
    // . is used to directly access members from object
    // while arrow function is for accessing elements using pointer to an object


// syntax : std::multimap<key_type, value_type> multimap_name = {
//     {key1, value1},
//     {key2, value2},
//     ...
// };

template <typename key, typename value>
    void PrintMultiMap(std::multimap<key, value>& my_multimap){
        //typename std::multimap<key, value>::iterator itr; //Or,
        // iterator based loop
        for(auto itr = my_multimap.begin(); itr != my_multimap.end(); ++itr){
            std::cout<<itr->first << " --- > " << (*itr).second << std::endl;
        }
        std::cout<<std::endl;

        // range based loop 'pair' is not an iterator or pointer
        // it has direct reference to the members of multiset
        // hence can't use -> operator

        // range based loop also works
        // for(const auto& pair : my_multimap){
        //     std::cout<< pair.first << " ---> " << pair.second << std::endl;

        // }
        // std::cout<<std::endl;
    }
int main(){
    // some students might score equl marks hence same rank
    std::multimap<int, std::string> students = {
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
    std::multimap<char, std::string> alphabet {
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
    PrintMultiMap(students);

    std::cout<<"The alphabets are : \n";
    PrintMultiMap(alphabet);
    
    // MultiMap methods

    return 0;
}