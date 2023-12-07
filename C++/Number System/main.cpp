#include<iostream>

int main(int argc, char** argv){
    int decimal = 15; //Decimal
    int octal = 017; // Octal
    int hexadecimal = 0x0f; // Hexadecimal
    int binary = 0b000101010; // Binary 

    std::cout << "The Number System in C++" << std::endl;
    std::cout << "Decimal : " <<  decimal <<std::endl;
    std::cout << "Octal : " << octal << std::endl;
    std::cout << "Binary : " << binary << std::endl;
    return 0;
}