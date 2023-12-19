#include<iostream>

// precedance : which operation to do first.
// associativity : which direction or which order

int main(){

    int a {6};
    int b {3};
    int c {8};
    int d {9};
    int e {3};
    int f {2};
    int g {5};

    int result = a + b * c - d / e  - f + g ; 

    // by precedance, * first then / and finally associativity left to right

    std::cout<<"The result is : " << result << std::endl;
    return 0;
}

// Link : check this out to referesh your memory
// https://en.cppreference.com/w/cpp/language/operator_precedence