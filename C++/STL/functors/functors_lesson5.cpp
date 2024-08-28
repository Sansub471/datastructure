// Create your own custom functor and use it with STL algorithm
// Let's count the number of prime numbers.
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

class isPrime{
    public:
        bool operator()(int N){
            if(N <= 1){
                return false;
            }
            // 2 and 3 are prime numbers
            if(N <= 3){
                return true;
            }
            if(N % 2 == 0 || N % 3 == 0){
                return false;
            }
            // check for divisors from 5 to sqrt(N)
            for(int i=5; i*i <= N; i+=6){

                // if N is divisible by i or i + 2
                if(N % i == 0 || N % (i+2) == 0){
                    return false;
                }
            }
            // no divisors means prime
            return true;
        }
};

int main(){
    std::vector<int> num {2,3,7,5,11,13,17,34,23,94,97,93,121,37,73,45645689,45645701};

    isPrime primeCheck;

    int count = std::count_if(num.begin(), num.end(), primeCheck);
    std::cout<<"The total number of primes in the vector is : " << count << std::endl;
    return 0;
}