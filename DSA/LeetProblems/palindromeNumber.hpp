#pragma once
bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x !=0)) return false; // negative and number ending with zero
    int revhalf = 0;
    while(x > revhalf){
        revhalf = revhalf * 10 + x % 10;
        x /= 10;
    }
    // revhalf = x or odd digits case reject the middle digit
    // eg. 1234321
    return x == revhalf || x == revhalf/10;
}

// T(n) = O(logN)
// S(n) = O(1)