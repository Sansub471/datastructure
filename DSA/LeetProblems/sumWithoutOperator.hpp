#pragma once
// Sum two numbers without using + or - sign
int getSum(int a, int b) {
    while(b != 0){
        int carry  = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int subtract(int a, int b) {
    return getSum(a, getSum(~b, 1));   // a + (-b)
}