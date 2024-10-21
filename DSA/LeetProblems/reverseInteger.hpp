#pragma once
#include<iostream>

//The largest positive number that can be reversed without overflow is 1463847412.
//The largest negative number that can be reversed without overflow is -1463847412.

// Reverse a given integer, 0 if overflow.
int reverseInteger(int N){
    int reverse = 0;
    int carry;
    int sign = N < 0 ? -1 : 1;
    N = std::abs(N);

    while(N != 0){
        carry = N % 10;
        if(reverse > (INT32_MAX - carry ) / 10){
            return 0;
        }
        reverse = reverse * 10 + carry;
        N /=  10;
    }
    reverse *= sign;
    if(reverse < INT32_MIN || reverse > INT32_MAX){
        return 0;
    }
    return reverse;
}

// you can't check if(rev*10 + carry > INT_MAX)
// if true, overflow has occured.


// Leetcode 
int reverse(int x) {
    int64_t result = 0; // signed long
    while (x != 0) {
        result *= 10;
        result += x % 10;
        x /= 10;
    }
    if (result > INT32_MAX || result < INT32_MIN) {
        return 0;
    }
    return result;
}