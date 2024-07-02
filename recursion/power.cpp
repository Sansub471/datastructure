#include<iostream>
#include<chrono>

// Iterative solution
long long PowIter(int x, int n){
    long long res = 1;
    for(int i = 1; i <= n ; i++){
        res *= x;
    }
    return res;
}

// Recursion : Method I
// x^n = {  x * x^(n-1) if n > 0
//          1 if n == 0
//        }
// T(n) = O(n)
long long PowRecurI(int x, int n){
    if (n == 0){
        return 1;
    }
    else{
        return x * PowRecurI(x, n - 1);
    }
}

// Recursion : Method II
// Recurrence function : 
// x^n = {  x^(n/2) * x^(n/2) if n is even
//          x * x^(n-1) if n is odd
//          1 if n == 0
//        }
// T(n) = O(logn)
long long PowRecurII(int x, int n){
    if(n == 0){
        return 1;
    }
    else if( n % 2 == 0){
        long long y = PowRecurII(x, n / 2);
        return y * y;
    }
    else{
        return x * PowRecurII(x, n - 1);
    }
}

void calculation(long long (*function)(int, int), int x, int n, const std::string& method){
    auto start = std::chrono::high_resolution_clock::now();
    long long result  = function(x, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout<<"Calculation method : " << method <<std::endl;
    std::cout<<"The " << n << " Pow( " << x <<" , " << n << " ) : " << result << std::endl;
    std::cout<<"Time taken : " << duration << "ms" << std::endl;
    std::cout<<std::endl;
}
int main(){
    std::cout<<"The Power(x,n) : " << std::endl;
    int x, n;
    std::cout<<"Enter x : "; std::cin>>x; 
    std::cout<<"Enter n : "; std::cin>>n;

    if (x < 0 || n < 0){
        std::cout<<"Only positive values expected!"<<std::endl;
        return -1;
    }

    calculation(PowIter, x, n, "Iteration");
    calculation(PowRecurI, x, n, "Recurrence I");
    calculation(PowRecurII, x, n, "Recurrence II");

    return 0;
}