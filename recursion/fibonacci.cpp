#include<iostream>
#include<chrono>

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

// Recursive solution
int FiboRecur(int n){
    if(n <= 1){
        return n;
    }
    else{
        return FiboRecur(n - 1 ) + FiboRecur(n - 2);
    }
}

// Recursion with memorization
// Avoid recalculation of same function states

const int SIZE = 51;
int F[SIZE]; // limits the number of terms
int FiboRM(int n){
    if(n <= 1){
        return n;}
    if(F[n] != -1){
        return F[n];}
    F[n] = FiboRM(n-1) + FiboRM(n-2);
    return F[n];
}

// Task: Make sure it works for any number of terms, not limited by the size of the array.

void calculate(int (*fibonacci)(int), int n, const std::string& method){
    auto start = std::chrono::high_resolution_clock::now();
    int FiboN = fibonacci(n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Calculate the elapsed time in milliseconds
    std::cout<<"Calculation method : " << method <<std::endl;
    std::cout<<"The " << n << " Fibonacci number is : " << FiboN << std::endl;
    std::cout<<"Time taken : " << duration << "ms" << std::endl;
    std::cout<<std::endl;
}
int main(){
    int n;
    std::cout<<"Give the position of Fibonacci number : ";
    std::cin>>n;
    
    calculate(FiboIter, n, "Iteration");
    calculate(FiboRecur, n, "Recurrence");

    // For memorization let's initialize the array
    for(int i=0; i < SIZE; i++){
        F[i] = -1;
    }

    // OR,
    // int value = -1;
    // std::fill(F, F+SIZE, value);

    calculate(FiboRM, n, "Recurrence with Memorization");
}

// 46th is the largest Fibonacci using integer data type, larger will overflow.

//Let's start another lesson