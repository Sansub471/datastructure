#include<iostream>
#include<map>


template <typename key, typename value>
    void PrintMap(std::map<key, value>& mapData){

    }
int main(){
    // Syntax : std::map<key_type, value_type> map_name = {{key1, val1},{key2, val2}...}
    std::map<int, std::string> marks = {{1, "Subin"}, {3, "Rabin"}, {5, "Babin"}, {2, "Ramesh"}, {6, "Sumesh"},
                                        {4, "Joe"}, {7, "Rachel"}, {9, "Ranjana"}, {8, "Subekshya"}};
    // = operator is optional
    std::map<std::string, std::string> alphabet {{"A", "Apple"}, {"B", "Ball"}, {"C", "Cat"}, {"D", "Dog"}, {"E", "Elephant"},
                                                {"F", "Fan"}, {"G", "Gun"}};
    // Map methods
    // 1. 

    return 0;
}