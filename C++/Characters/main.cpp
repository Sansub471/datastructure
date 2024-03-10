#include<iostream>
#include<cstring>

// Character takes one byte of memory

int main(){
    char name = 'A';
    char value = 35; // ASCII character code for #

    // One byte in memory : 2^8 = 256 different values ( 0 - 255 )
    std::cout << "The char is : " << name << std::endl;

    // print character of the associated value, default
    std::cout << "The value is : " << value << std::endl;
    std::cout << "The char from value: " << value << " is " << 
    static_cast<int>(value)<<std::endl; // interpret as number
    return 0;
}