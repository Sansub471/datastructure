#include<iostream>
#include<string>

// std:: cout  -> printing data to the console
// std:: cin -> reading data from the console
// std:: cerr ->  printing errors to the console
// std:: clog -> printing log message to the console

int main(int agrc, char** argv){

    std::cout << "Hello C++" << std::endl;

    int age {23};
    std::cout << "The age is : " << age <<std::endl;

    std:: cerr << "Error message : something is wrong." << std::endl;

    std::clog << "Log message : Something happened." << std::endl;
    
    std::string full_name;
    std::cout<< "Give me your name : " <<std::endl;
    std::getline(std::cin, full_name);
    std::cout<< "Your name is "<<full_name<<std::endl;

    return 0;
}