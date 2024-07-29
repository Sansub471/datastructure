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
    // 1. insert() : inserts one or more key-value pairs
    // 2. count()  : returns total number of occurence of the specified key
    // 3. find()   : returns the iterator to the element with the specified key
    // 4. size()   : returns the number of elements
    // 5. empty()  : returns true if the multimap is empty
    // 6. erase()  : removes elements with specified key
    // 7. clear()  : removes all elements

    // insert elements
    alphabet.insert({{'D', "Dense"}, {'E', "Egg"}});
    students.insert({{2, "Siddhanta"}, {7, "Sandhya"}});

    // remove elements from a multimap
    // clear() removes all elements

    // erase()
    students.erase(3);
    std::cout<<"Students are erase and insert : \n";
    PrintMultiMap(students);

    std::cout<<"The size of alphabets multimap : "<< alphabet.size() << std::endl;

    // find() a key in the multimap
    // returns iterator to the element if the key is found, only the first instance of the key
    // otherwise end of the container end()
    
    int rank = 7;
    auto find_iter = students.find(rank);
    if (find_iter != students.end()){
        std::cout<<"\nThe Student's rank : " << find_iter->first << " ---> Name: "<<find_iter->second<<std::endl;
    }
    else{
        std::cout<<"\nCan't find rank " << rank << std::endl;
    }

    // find() only gives the first occurence of the key

    // count(): returns the total number of occurence of specified key
    int countRank = students.count(rank);
    if(countRank){
        std::cout<<"\nThere are " << countRank << " students with rank " << rank << std::endl;
    }
    else{
        std::cout<<"\nCan't find the student with rank " << rank << std::endl;
    }

    return 0;
}