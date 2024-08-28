#include<iostream>
// Let's learn to create a simple functor

// Create a class and overload the () operator
class Greet{
    public:
        void operator() (){
            std::cout<<"Hello world! You'll learn about functors."<<std::endl;
        }
};


// Functor can be created with structure as well
struct Namaskar{
    void operator()(){
        std::cout<<"Namaskar from structor functor! Happy coding!!"<<std::endl;
    }

};
int main(){

    Greet greet;
    greet(); // calling the object as function
    greet.operator()(); // it also calls the function

    // For structure functor
    struct Namaskar namaskar;
    namaskar();
    return 0;
}