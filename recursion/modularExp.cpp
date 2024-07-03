#include<iostream>


long long ModExp(int x, int n, int M){
    if(n==0){
        return 1;
    }
    else if((n % 2) == 0){
        long long y = ModExp(x, n/2, M); // prevent calculation same value twice.
        return (y * y) % M; // check recurrence function.
    }
    else{
        return ((x % M) * ModExp(x, n-1, M)) % M;
    }
}
int main(){
    std::cout<<"The ModularExponentiation(x, n, M) : x^n % M " << std::endl;
    int x, n, M;
    std::cout<<"Enter x : "; std::cin>>x; 
    std::cout<<"Enter n : "; std::cin>>n;
    std::cout<<"Enter M : "; std::cin>>M;

    if (x < 0 || n < 0 || M <= 0){
        std::cout<<"Only positive values expected!"<<std::endl;
        return -1;
    }

    std::cout<<"The Modular Exponentiation result : " << ModExp(x, n, M) << std::endl;
    return 0;
}