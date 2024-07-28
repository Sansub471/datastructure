#include<iostream>
#include<map>


template <typename key, typename value>
    void PrintMap(std::map<key, value>& mapData){
        std::cout<<"The values are : ";
        for(int i = 1; i<= mapData.size(); ++i){
            std::cout<<mapData[i]<<" ";
        }
        std::cout<<std::endl;

    }
int main(){
    // Syntax : std::map<key_type, value_type> map_name = {{key1, val1},{key2, val2}...}
    std::map<int, std::string> marks = {{1, "Subekshya"}, {3, "Rabin"}, {5, "Babin"}, {2, "Ramesh"}, {6, "Sumesh"},
                                        {4, "Joe"}, {7, "Rachel"}, {9, "Ranjana"}, {8, "Subekshya"}};
    // = operator is optional
    std::map<char, std::string> alphabet {{'A', "Apple"}, {'B', "Ball"}, {'C', "Cat"}, {'D', "Dog"}, {'E', "Elephant"},
                                                {'F', "Fan"}, {'G', "Gun"}};
    // Map methods
    // 1. insert() : adds an element (key-value) to the map
    // 2. erase() : removes an element or range of elements from the map
    // 3. clear() : removes all the elements from the map
    // 4. find()  : searches the map for the given key
    // 5. size() : returns the number of elements in the map
    // 6. empty() : returns true if the map is empty

    // Ad an element in the map
    // using the [] operator
    // map_name[key] = value;

    // using the insert() and make_pair() functions
    // map_name.insert(std::make_pair(key, value));

    marks[10] = "Aayusha";
    marks[10] = "Aayesha"; // Adding duplicate keys
    // it overwrites previous value

    alphabet.insert(std::make_pair('H', "Horse"));
    alphabet.insert(std::make_pair('H', "Honey")); // duplicate key

    std::cout<<"-------------Student and Marks-----------: \n";
    PrintMap(marks);





    return 0;
}