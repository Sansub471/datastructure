#include<iostream>
#include<deque>

template<typename T>
    void PrintDequeue(std::deque<T>& dq){
        for(const auto& elem: dq){
            std::cout<<elem<<"  ";
        }
    std::cout<<std::endl;
    }

int main(){
    // Syntax : std::deque<type> dq;

    // 1. initializer list
    std::deque<int> dqnumbers ={8,9,5,4,3,2,1,9,10};
    std::deque<std::string> dqwords {"queue", "meow", "few", "sew", "dew", "hue"};

    std::cout<<"The numbers are :"; 
    PrintDequeue(dqnumbers);

    std::cout<<"The words are   : "; 
    PrintDequeue(dqwords);

    // Other ways to create dequeu
    // 1. Fill Constructor Method
    
    return 0;
}