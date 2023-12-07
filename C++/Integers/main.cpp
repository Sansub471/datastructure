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
    return 0;

}