#include<iostream>


// integral types less than 4 bytes in size don't support 
// arithmetic operations

// e.g. char | short int

int main(){

    short int var1{10};
    short int var2{20};

    char var3 {40};
    char var4 {50};

    std::cout<<"Size of var1 : " << sizeof(var1) << std::endl;
    std::cout<<"Size of var2 : " << sizeof(var2) << std::endl;
    std::cout<<"Size of var3 : " << sizeof(var3) << std::endl;
    std::cout<<"Size of var4 : " << sizeof(var4) << std::endl;

    auto result1 = var1 + var2; // converted to int
    auto result2 = var3 + var4; // converted to int

    // Int is the smallest type which can accomodate these arithmetic operations
    // The same behaviour is present on other operators like bitwise
    // shift operators (>> and << )

    std::cout<<"Size of result1 : " << sizeof(result1) << std::endl;
    std::cout<<"Size of result2 : " << sizeof(result2) << std::endl;
    return 0;
}
