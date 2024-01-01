#include<iostream>
#include<iomanip>


// input/ output manipulators.
int main()
{   
    std::cout<< "Printing a new line ... "<<std::endl; // print a new line

    //std::flush;
    std::setw(15); // setwidth e.g a Formatted Table
    std::right; // right justification
    std::internal; // sign in left justified, data is right justified.
    // -    45.0233
    // -    902.023

   
    bool flag = true;
    bool flag2 = false;
    
    std::cout << "The true bool : " << flag << std::endl;
    std::cout << std::boolalpha; // control bool output format : 1/0 or true/ false

    std::cout << "The true bool : " << flag << std::endl;
    std::cout << std::noboolalpha; // disable boolalpha

    std::cout<< "The false bool : " << flag2 << std::endl;

    // show number sign.

    std::cout<<"Manipulator std:: showpos and std::noshowpos" << std::endl;
    std::cout<<std::showpos; // show or hide the + sign for positive numbers.

    int pos_num {34};
    int neg_num {-45};

    std::cout<< "pos_num : " << pos_num << std::endl;
    std::cout<< "neg_num : " << neg_num << std::endl;

    std::cout<<std::noshowpos;
    std::cout<< "pos_num : " << pos_num << std::endl;
    std::cout<< "neg_num : " << neg_num << std::endl;


    // Number system manipulators
    // std::dec, std::hex, std::oct

    int pos_int {1024};
    int neg_int {-256};
    double double_var {489.24};

    std::cout << std::endl;
    std::cout << "pos_int in different bases : " << std::endl;
    std::cout << "(dec) : " << std::dec << pos_int << std::endl;
    std::cout << "(hex) : " << std::hex << pos_int << std::endl;
    std::cout << "(oct) : " << std::oct << pos_int << std::endl;


    std::cout << std::endl;
    std::cout << "neg_int in different bases : " << std::endl;
    std::cout << "(dec) : " << std::dec << neg_int << std::endl;
    std::cout << "(hex) : " << std::hex << neg_int << std::endl;
    std::cout << "(oct) : " << std::oct << neg_int << std::endl;

    std::cout << std::endl;
    std::cout << "double_var in different bases : " << std::endl;
    std::cout << "(dec) : " << std::dec << double_var << std::endl;
    std::cout << "(hex) : " << std::hex << double_var << std::endl;
    std::cout << "(oct) : " << std::oct << double_var << std::endl;

    


    return 0;
}