#pragma once

// Square root without using the built in funciton
int mySqrt(int x) {
    if(x == 0 || x == 1) return x;
    int low = 1, high = x / 2; // for x > 1 it can be x/2
    while(low <= high){
        int mid = low + (high - low) / 2;
        int temp = x / mid;
        if(mid == temp) return mid;
        else if(mid < temp){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;

    // O(log x ) complexity
}