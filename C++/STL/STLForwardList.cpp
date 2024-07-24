#include<iostream>
#include<forward_list>

template <typename T>
    void PrintForwardList(std::forward_list<T>& fwdList){
        std::cout<<"The elements of the forward list are : ";
        for(const T& elem : fwdList){
            std::cout<<elem<<"\t";
        }
    std::cout<<std::endl;
    }

int main(){
    // create an integer forward list
    std::forward_list<int> int_fwd_list {1,2,3,4,5,6,7,8,9};

    std::forward_list<std::string> forward_words = {"mine", "shine", 
                                                    "fine", "dine", "nine"};

    std::cout<<"The words are \n";
    PrintForwardList(forward_words);


    return 0;

}