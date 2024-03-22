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
    
    char* msg1 = "The pointer in C++";
    
    // Let's take few notes here ; 
    // There are other types of string in C++
    // 1. std::string 
    
    std::string name = "DellInspiron15i7";
    std::cout<<"std::string  = " << name << std::endl;
    // 2. char[]
    // 3. cosnt char* 

    return 0;
}