#include<iostream>
#include<list>

// list is implemented using doubly linked list
// can be accessed from both ends front and back
// Random access not allowed

template <typename T>
    void PrintList(std::list<T>& myList){
        std::cout<<"The elements are : ";
        for(const T& elem : myList){
            std::cout<<elem<<"\t";
        }
    std::cout<<std::endl;
    }
int main(){

    std::list<int> numbers = {1,2,3,4,5,6,7,8};
    std::list<float> marks {12.5, 23.5, 89.05, 34.12, 90.22, 89.2};

    std::cout<<"The lists created are : "<<std::endl;
    PrintList(numbers);
    PrintList(marks);

    return 0;
}