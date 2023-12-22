#include<iostream>


// input/ output manipulators.
int main()
{   
    std::cout<< " Printing a new line ... "<<std::endl; // print a new line

    std::flush;
    std::setw(); // setwidth e.g a Formatted Table
    std::right; // right justification
    std::internal; // sign in left justified, data is right justified.

    std::boolalpha; // control bool output format : 1/0 or true/ false
    std::noboolalpha; // disable boolalpha
    std::showpos; // show or hide the + sign for positive numbers.
    return 0;
}