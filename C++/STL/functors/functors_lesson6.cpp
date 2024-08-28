// Create a generic functor using class templates
#include<iostream>
#include<algorithm>
#include<vector>


//similar to C++ predefined function greater<T>

template <typename T>
    class GreaterThan{
        public:
            bool operator()(const T& left, const T& right){
                return left > right;
            }
    };


template<typename T>
    void PrintVector(std::vector<T>& myVec){
        std::cout<<"the elements are : ";
        for(const T& elem : myVec){
            std::cout<<elem<<"  ";
        }
        std::cout<<std::endl;
    }
int main(){
    std::vector<int> integers{12,45,1,2,4,90,23,03, 20, 21,24};
    std::vector<float> decimals{12.45, 1.2, 4.9, 2.30, 20.21, 24.21, 89.23, 1.34};
    std::vector<char> characters{'D', 'F', 'A', 'I', 'O', 'E', 'U', 'S', 'T'};
    std::vector<std::string> words {"name", "fame", "shame", "game", "tame", "lame", "pame", "hame"};

    std::cout<<"Before sorting, "; PrintVector(integers);
    std::sort(integers.begin(), integers.end(), GreaterThan<int>());
    std::cout<<"After sorting, "; PrintVector(integers);

    std::cout<<"\nBefore sorting, "; PrintVector(decimals);
    std::sort(decimals.begin(), decimals.end(), GreaterThan<float>());
    std::cout<<"After sorting, "; PrintVector(decimals);

    std::cout<<"\nBefore sorting, "; PrintVector(characters);
    std::sort(characters.begin(), characters.end(), GreaterThan<char>());
    std::cout<<"After sorting, "; PrintVector(characters);

    std::cout<<"\nBefore sorting, "; PrintVector(words);
    std::sort(words.begin(), words.end(), GreaterThan<std::string>());
    std::cout<<"After sorting, "; PrintVector(words);



    

    return 0;
}