#include<iostream>

int main(int argc, char** argv){
    std::cout<<"Hello World, this is C++"<<std::endl;

    // Runtime error
    int div = 7 / 0;
    std::cout<< "The value is : " << div << std::endl;
    return 0;
}