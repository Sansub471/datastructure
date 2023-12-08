#include<iostream>

int main(int agrc, char** agrv){

    // Assignment initialization
    int number = 45 ; // int usually takes 4 bytes of memory
    int value {78}; // Braced initializaiton


    // Functional initialization
    int val(129);
    int num (4.5); // Stores 4, information lost


    // Assignment notation

    int sum = val + number;

    std::cout << "Size of number is : " << sizeof(number) << std::endl;
    std::cout << "The num is : " << num << std::endl;


    // Let's look at the signed and unsigned integers.
    // They will occupy 4bytes like a normal integer


    // The possible integer modifiers.

    short short_var {-32768}; // 2 bytes, it means implicitly int
    short int short_int {455}; //
    signed short signed_short {122}; // 
    signed short int signed_short_int {-456}; // 
    unsigned short unsigned_short {38}; // 
    unsigned short int unsigned_short_int {456}; // unsigned short

    std::cout<< "The size of short is : " << sizeof(short_var) <<std::endl;

    int int_var {55}; // 4 bytes
    signed signed_var {66}; // 
    signed int signed_int {77};
    unsigned unsigned_var {19};
    unsigned int unsigned_int {17};

    std::cout<< "The size of signed is : " << sizeof(signed_var) << std::endl;

    long long long_long {8888}; // 8 bytes
    long long int long_long_int {9999};
    signed long long signe_long_long {4444};
    signed long long int signed_long_long_int {1234567};
    unsigned long long int unsigned_long_long_int {1232138};

    std::cout << "The size of long long is : " << sizeof(long_long) << std::endl;
    return 0;

}

// This kind of initialization works with other variables as well.
// Modifiers work on integers
