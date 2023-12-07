#include<iostream>

int main(int argc, char** argv){
    int decimal = 15; //Decimal
    int octal = 017; // Octal
    int hexadecimal = 0x0f; // Hexadecimal
    int binary = 0b0001111; // Binary - C++14

    std::cout << "The Number System in C++" << std::endl;
    std::cout << "Decimal : " <<  decimal <<std::endl;
    std::cout << "Hexadecimal : " << hexadecimal << std::endl;
    std::cout << "Octal : " << octal << std::endl;
    std::cout << "Binary : " << binary << std::endl;
    return 0;
}