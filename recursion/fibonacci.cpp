#include<iostream>

// Interative solution
int FiboIter(int n){
    if(n <=1 ) return n;

    int F1 = 0;
    int F2 = 1;
    int i, F;
    for(i=2; i <= n; i++){
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    return F;
}

int main(){
    int n;
    std::cout<<"Give the position of Fibonacci number : ";
    std::cin>>n;
    std::cout<<"The " << n << " Fibonacci number is : " << FiboIter(n) << std::endl;
}