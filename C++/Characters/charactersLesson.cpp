#include<iostream>
int main(){
    // character array
    char msg[5] {'H', 'e', 'l','l','o'};

    // printing the array using looping
    std::cout<<"The message is : ";
    for(auto m : msg){
        std::cout<< m ;
    }
    std::cout<<std::endl;
    // This method works, but it's not a good idea to use it like this, 
    // writing each character is not easy
    // Don't use string with no null-termination
    
    std::cout<<"Another message is : ";
    char msg1[]{'N', 'E', 'P', 'A', 'L', '\0'};
    for(auto m : msg1){
        std::cout<<m;
    }
    std::cout<<std::endl;
    // null terminated strings in C++ are called C-string
    // it comes from the C-programming language

    char msg3[6]{'H','e','l','l','o'}; // remaining space is filled with null
    std::cout<< msg3 << std::endl;
    std::cout<<"Size of msg3 : " << sizeof(msg3) << std::endl;

    char msg4[]{'H','e','l','l','o'}; // This is not a c string
    // as there is no null character
    std::cout<<"The msg4 is : " << msg4 << std::endl;
    std::cout<<"Size of msg4 : " << sizeof(msg4) << std::endl;
    // We see unexpected result while printing msg4 because there is no
    // null termination

    // C-string is difficult to work with
    // In C++, we have string literals
    char msg5[] {"Hello C++, you have been a real pain in the ass."};
    std::cout<<"String literal : " << msg5 << std::endl;

    const char* message {"Pointer to string literal in C++"};
    // const is necessary in C++ now because modifying non-const string literal 
    // can lead to undefined behaviour
    // or bug risk
    std::cout<<"The char pointer : " << message << std::endl;


    return 0;
}
