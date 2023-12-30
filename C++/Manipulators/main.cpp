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

    std::showpos; // show or hide the + sign for positive numbers.

    int pos_num {34};
    int neg_num {-45};

    std::cout<< "pos_num : " << pos_num << std::endl;
    std::cout<< "neg_num : " << neg_num << std::endl;

    return 0;
}