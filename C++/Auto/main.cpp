#include<iostream>

// This lesson is about auto in C++
// Let the compiler determine the data type itself.
// Let the compiler deduce the type

int main(){

    auto var1 {12};
    auto var2 = 78;
    auto var3 {34.0}; // double is default 
    auto var4 {23.78f}; // float
    auto var5 {15.56l}; // long double
    auto var6 {'e'}; // character

    // int modifier suffixes
    auto var7 {123u}; // unsigned
    auto var8 {1234ul}; // unsigned long
    auto var9 {123ll}; // long long

    // This is only for printing
    std::cout << "var 1 occupies : " << sizeof(var1) << " bytes." << std::endl;
    std::cout << "var 2 occupies : " << sizeof(var2) << " bytes." << std::endl;
    std::cout << "var 3 occupies : " << sizeof(var3) << " bytes." << std::endl;
    std::cout << "var 4 occupies : " << sizeof(var4) << " bytes." << std::endl;
    std::cout << "var 5 occupies : " << sizeof(var5) << " bytes." << std::endl;
    std::cout << "var 6 occupies : " << sizeof(var6) << " bytes." << std::endl;
    std::cout << "var 7 occupies : " << sizeof(var7) << " bytes." << std::endl;
    std::cout << "var 8 occupies : " << sizeof(var8) << " bytes." << std::endl;
    std::cout << "var 9 occupies : " << sizeof(var9) << " bytes." << std::endl;
    return 0;
}