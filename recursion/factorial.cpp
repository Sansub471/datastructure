#include<iostream>

long int factorial(long int n){
    std::cout<<"Calculating F("<<n<<")"<<std::endl;
    if(n == 0) return 1;

    long int F = n * factorial(n-1);
    std::cout<<"Done, F("<<n<<")"<<std::endl;
    return F;
}

int main(){
    long int n = 7;
    std::cout<<"The factorial of " << n << " is " << factorial(n) << std::endl;
    return 0;
}