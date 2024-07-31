#include<iostream>
#include<map>

template <typename key, typename value>
    void PrintMap(std::map<key, value>& mapData){
        std::cout<<"The values are : ";
        for(const auto& pair: mapData){
            std::cout<< pair.second << " ";
        }
        std::cout<<std::endl;

        std::cout<<"\nThe key-value pairs are :\n";
        typename std::map<key, value>::iterator iter;
        for(iter = mapData.begin(); iter != mapData.end(); ++iter){
            std::cout<< iter->first << " ---> " << iter->second << std::endl; // iter-> is same as (*iter).first
        }
        std::cout<<std::endl;

        // Another method
        std::cout<<"\nThe key value pairs are : \n";
        for(auto itr = mapData.begin(); itr != mapData.end(); ++itr){
            std::cout<<itr->first << " ---> " << (*itr).second << std::endl;
        }
        std::cout<<std::endl;

    }
int main(){
    // Syntax : std::map<key_type, value_type> map_name = {{key1, val1},{key2, val2}...}
    std::map<int, std::string> students = {{1, "Subekshya"}, {3, "Rabin"}, {5, "Babin"}, {2, "Ramesh"}, {6, "Sumesh"},
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

    students[10] = "Aayusha";
    students[10] = "Aayesha"; // Adding duplicate keys


    alphabet.insert(std::make_pair('H', "Horse"));
    alphabet.insert(std::make_pair('H', "Honey")); // duplicate key
    alphabet.insert({{'M', "Monkey"}, {'N', "Nest"}});

    std::cout<<"The students in Students map are : ";
    for(int i = 1; i<= students.size(); ++i){
            std::cout<<students[i]<<" "; // i is in the keys of map students
        }
    std::cout<<std::endl;


    std::cout<<"-------------Student & Roll Number-----------: \n";
    PrintMap(students);

    std::cout<<"-------------Alphabet--------------------:\n";
    PrintMap(alphabet);

    // Access the values of map
    // 1. at() : returns the value of the specified key
    // 2. [] : returns the value of the specified key
    std::map<std::string, std::string> capital_city {
        {"Nepal", "Kathmandu"},
        {"India", "New Delhi"},
        {"Australia", "Canberra"}
    };
  
    std::cout << "Capital of Nepal is " << capital_city["Nepal"] << std::endl;
    std::cout << "Capital of Australia is " << capital_city.at("Australia")<<std::endl;
    std::cout<<std::endl;
    
    // find() function for maps
    // map_name.find(key)

    std::map<int, std::string>::iterator iter;
    int roll = 9; // change th roll number
    iter = students.find(roll); // find the key 9 in students map
    // returns an iterator pointing to the element if the element exists
    // otherwise iterator to the students.end()
    if(iter != students.end()){
        std::cout<<"The student, Roll : "<< iter->first << " Name : " << iter->second << std::endl;
        // you could access iterator by : (*iter).first and (*iter).second as well
    }
    else{
        std::cout<<"Student will roll number " << roll << " not found in records."<<std::endl;
    }

    // Delete elements from C++ maps
    // erase() and clear() functions

    // map_name.clear(); // deletes all elements of the map


    // erase()
    // Delete individual elements either with iterator or key
    alphabet.erase('G'); // using key
    std::map<char, std::string>::iterator itr_alpha = alphabet.begin();
    // itr_alpha+= 2; 
    ++itr_alpha; ++itr_alpha;
    alphabet.erase(itr_alpha);

    std::cout<<"The alphabet after erase() : \n";
    PrintMap(alphabet);

    // Delete a range of elements
    // map_name.erase(itr_start, itr_end);
    // iter_end is not inclusive

    // The elements in the map are internally sorted by their key
    std::map<char, std::string>::iterator iter_start, iter_end;
    iter_start = alphabet.begin(); // index 0
    iter_end = alphabet.end();

    ++iter_start;// index 1 
    ++iter_start;// index 2

    --iter_end; // last element

    alphabet.erase(iter_start, iter_end);
    std::cout<<"The map after range erase: \n";
    PrintMap(alphabet);
    return 0;
}