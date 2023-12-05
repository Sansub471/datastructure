#include<iostream>

int summation(int a, int b){
    return a + b;
}

int main(int argc, char** argv){
    std::cout<<"Give me two numbers : "<<std::endl;
    int first, second;
    std::cin>>first>>second;

    int c = summation(first, second);
    std::cout<<"The sum of "<<first<<" and "<<second<<" is : "<<c<<std::endl;
    return 0;
}
