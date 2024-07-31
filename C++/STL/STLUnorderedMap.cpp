#include<iostream>
#include<unordered_map>

template<typename key, typename value>
    void PrintUnorderedMap(std::unordered_map<key, value>& unMap){
        // Three ways to print the values
        // const will prevent modification inside the loop
        for(const auto& pair : unMap){
            std::cout<<pair.first<<" ---> "<<pair.second<<std::endl;
        }
        std::cout<<std::endl;
        
        // auto itr could be defined as:
        //typename std::unordered_map<key, value>::iterator itr;
        for(auto itr=unMap.begin(); itr != unMap.end(); ++itr){
            std::cout<<itr->first<<" ---> "<< itr->second<<std::endl; // (*itr).first/second
        }
        std::cout<<std::endl;

        // Starting from C++17, you can use structure bindings to simplify this code further:

        // for(const auto& [key, value]: unMap) {
        //   cout << key << " -  " << value << endl; 
        // }
    }

int main(){

    std::unordered_map<int, std::string> students = {{1, "Subekshya"}, {3, "Rabin"}, {5, "Babin"}, {2, "Ramesh"}, {6, "Sumesh"},
                                        {4, "Joe"}, {7, "Rachel"}, {9, "Ranjana"}, {8, "Subekshya"}};
    // = operator is optional
    std::unordered_map<char, std::string> alphabet {{'Y', "Yak"},{'A', "Apple"}, {'B', "Ball"}, {'C', "Cat"}, {'D', "Dog"}, {'E', "Elephant"},
                                                {'F', "Fan"}, {'G', "Gun"}, {'A', "Aeroplane"}, {'B', "Bag"}};

    // duplicated key not allowed, once the key is initialized duplicate value
    // with the same key won't be inserted
    // same in map and set as well

    std::cout<<"Unordered map: Students-----\n";
    PrintUnorderedMap(students);

    std::cout<<"\nUnordered map: alphabets----\n";
    PrintUnorderedMap(alphabet);

    // Initialize the map by copying
    std::unordered_map<char, std::string>::iterator iter = alphabet.begin();
    // ++iter; ++iter; // index 1 // index 2

    std::unordered_map<char, std::string> cpalpha(iter, alphabet.end());
    std::cout<<"\nUnordered map, copied alphabet-----------\n";
    PrintUnorderedMap(cpalpha);

    // The difference with the map is that the keys are not ordered.
    // It's like dictionary data structure.

    // Methods of unordered map
    // 1. insert() : insert one or more key-value pairs
    // 2. count()  : returns 1 if key exists and 0 if not
    // 3. find()   : returns the iterator to the element with the specified key
    // 4. at()     : returns the element at the specified key
    // 5. size()   : returns the number of elements
    // 6. empty()  : returns true if the unordered map is empty
    // 7. erase()  : removes elements with specified key
    // 8. clear()  : removes all elements

    // Add element in the unordered map
    // 1. insert() : key-value pair/s
    // 2. unmap[key] = value; insert a key and value

    alphabet['X'] = "Xeros"; alphabet.insert({{'M', "Monkey"}, {'N', "Nest"}});
    alphabet.insert(std::make_pair('Q', "Quill"));

    // Access the values of unordered map
    // 1. at() : returns the value of the specified key
    // 2. [] : returns the value of the specified key
    std::unordered_map<std::string, std::string> capital_city {
    {"Nepal", "Kathmandu"},
    {"India", "New Delhi"},
    {"Australia", "Canberra"}
  };
  
  std::cout << "Capital of Nepal is " << capital_city["Nepal"] << std::endl;
  std::cout << "Capital of Australia is " << capital_city.at("Australia")<<std::endl;

  


    return 0;
}