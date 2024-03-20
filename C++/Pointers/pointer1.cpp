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
    std::cout<<"The size    of sentence : "<<sizeof(sentence) << std::endl;
    return 0;
}