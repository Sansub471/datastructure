#include<iostream>

// Functor with return type and parameters
class Summation{
    public:
        int operator()(int a, int b){
            return a+b;
        }
};

int main(){

    Summation sum;
    int add = sum(7,8);
    std::cout<<"The sum is : " << add << std::endl;
    return 0;
}