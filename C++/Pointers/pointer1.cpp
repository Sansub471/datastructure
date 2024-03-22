#include<iostream>
// This is the first class on pointers
// Already familiar with pointer to other data types
// Declaring pointer to char

int main(){
    // can use normal pointer to char like for double, int, float, and
    // anything else really

    char* pchar{nullptr};
    char charval = 'A';
    pchar = &charval;

    std::cout<<"The value stored in pchar : " << *pchar << std::endl;

    // This is how we normally think, but there is something special here
    // We can use string literal, "String Literal" with char*
    const char* sentence{"The const* char pointer declaration."};
    std::cout<<"The address of sentence : "<< &sentence << std::endl;
    std::cout<<"The size    of sentence : "<< sizeof(sentence) << std::endl;

    // The first character will be pointed by the the first character
    // of the string literal

    std::cout<<"The *sentence is : " << *sentence << std::endl;
    // It will print the first character of the string literal
    std::cout<<"The *sentence + 1 is : " << *(sentence + 1) << std::endl;
    // The second character and the arithematic works like any othe pointer type

    // What if we want to modify the char array? 
    // The easy solution is to use the char array char[]{}

    char sen[]{"Fewa is the biggest lake of Nepal."};
    sen[0] = 'R'; sen[1]='a'; sen[2]='r'; sen[3] = 'a';
    std::cout<<"Info, lake of Nepal : " << sen << std::endl;

    char sen1[]{"My name is Subash Mainali"};
    sen1[0] ='N';
    std::cout<<"Info, name : " << sen1 << std::endl;
       
    // Let's take few notes here ; 
    // There are other types of string in C++
    // 1. std::string 
    
    std::string name = "DellInspiron15i7";
    std::cout<<"std::string  = " << name << std::endl;
    //      std::string is an instantiation of the basic_string class
    //      tempelate that uses char(i.e. bytes) as its characters type.
    //      Don't use cstring or string.h functions with std::string strings.
    //      because cstring strings are of const char* type.
    
    // 2. char[]
    char str[] = "This string can be modified later.";
    //Pros:     can modify the string later on
    //Cons:    this is statically allocated sized array which consumes space in the stack
    //         large size array required for concatenation or maipulate since the 
    //          size of string is fixed.
    //          Can use cstring or string.h library functions.      
    
    // 3. const char* 
    const char* line = "This is cont* char type string, cannot be modified later.";
    // Pros :   only one pointer required to refer to whole string, memory efficient
    //          No need to declare the size of array before.
    // Cons : char* is okay in C, but not in C++. In C-string is an array of characters
    //         while in C++, string is an array of const characters

    //          Can't modify the string later on, however it can point to another string.
    std::cout<<"Old line string is : " << line << std::endl;
    line = str;
    std::cout<<"New line string is : " << line << std::endl;
    
    // Is the opposite possible?
    const char* line2 = "This is the second line type string.";
    //str = line2; // incompatible type in assignment of 'const char*' to 'char []'
    std::cout<<"line2 assigned to str : " << str << std::endl;

    return 0;
}