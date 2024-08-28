#include<iostream>
// Let's learn to create a simple functor

// Create a class and overload the () operator
class Greet{
    public:
        void operator() (){
            std::cout<<"Hello world! You'll learn about functors."<<std::endl;
        }
};

int main(){

    Greet greet;
    greet(); // calling the object as function
    greet.operator()(); // it also calls the function
    return 0;
}