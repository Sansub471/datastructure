// C++ Program to Check if a Number is Prime using Square
// Root Optimized Trial Division Approach
#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int N)
{

    // If the number is less than or equal to 1,
    // it is not prime
    if (N <= 1) {
        return false;
    }

    // If the number is 2 or 3, it is prime
    if (N <= 3) {
        return true;
    }

    // If the number is divisible by 2 or 3,
    // it is not prime
    if (N % 2 == 0 || N % 3 == 0) {
        return false;
    }

    // Check for divisors from 5
    // to the square root of N
    for (int i = 5; i * i <= N; i += 6) {

        // If N is divisible by i or (i + 2),
        // it is not prime
        if (N % i == 0 || N % (i + 2) == 0) {
            return false;
        }
    }

    // If no divisors are found, it is prime
    return true;
}

// Driver code
int main()
{
    int N = 45645701;
    cout << "Is " << N << " prime - ";

    if (isPrime(N)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}