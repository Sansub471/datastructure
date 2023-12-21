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
    int result1 = b + d / f - a + g + c * e + g / f;
    int result2 = a/b*c + d - e + f; // Associativity left to right
    int result3 = a*b/c + d - e +f; // Associativity left to right


    // by precedance, * first then / and finally associativity left to right

    std::cout<<"The result is : " << result << std::endl;
    std::cout<<"The result one is : " << result1 << std::endl;
    std::cout<<"The result two is : " << result2 << std::endl;
    std::cout<<"The result three is : " << result3 << std::endl;
    return 0;
}

// Link : check this out to referesh your memory
// https://en.cppreference.com/w/cpp/language/operator_precedence

// Hint : use parenthesis at the right place to make things clear and save time
// Use () to make things very clear for readibility.