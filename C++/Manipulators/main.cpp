#include<iostream>
#include<iomanip>


// input/ output manipulators.
int main()
{   
    std::cout<< "Printing a new line ... "<<std::endl; // print a new line

    //std::flush;
    std::setw(15); // setwidth e.g a Formatted Table
    std::right; // right justification
    std::internal; // sign is left justified, data is right justified.
    // -    45.0233
    // -    902.023

   { // std::boolalpha and std::noboolalpha
    bool flag = true;
    bool flag2 = false;
    
    std::cout << "The true bool : " << flag << std::endl;
    std::cout << std::boolalpha; // control bool output format : 1/0 or true/ false

    std::cout << "The true bool : " << flag << std::endl;
    std::cout << std::noboolalpha; // disable boolalpha

    std::cout<< "The false bool : " << flag2 << std::endl;
   }

   { // show number sign.

    std::cout<<"Manipulator std:: showpos and std::noshowpos" << std::endl;
    std::cout<<std::showpos; // show or hide the + sign for positive numbers.

    int pos_num {34};
    int neg_num {-45};

    std::cout<< "pos_num : " << pos_num << std::endl;
    std::cout<< "neg_num : " << neg_num << std::endl;

    std::cout<<std::noshowpos;
    std::cout<< "pos_num : " << pos_num << std::endl;
    std::cout<< "neg_num : " << neg_num << std::endl;
   }

   {// Number system manipulators
    // std::dec, std::hex, std::oct

    int pos_int {52719};
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

    // These number systems are not reflected in floating point number
    // The floating point numbers are stored differently in the memory
   }

    {// showbase and noshowbase : show the base for integral types
    std::cout << "showbase and noshowbase : show the base for integral types" <<std::endl;
    int pos_int = 717171;
    std::cout << "pos_int (noshowbase: default) : " << std::endl;
    std::cout << "(dec) : " << std::dec << pos_int << std::endl;
    std::cout << "(hex) : " << std::hex << pos_int << std::endl;
    std::cout << "(oct) : " << std::oct << pos_int << std::endl;

    std::cout << "pos_int (showbase) : " << std::endl;
    std::cout << std::showbase;
    std::cout << "(dec) : " << std::dec << pos_int << std::endl;
    std::cout << "(hex) : " << std::hex << pos_int << std::endl;
    std::cout << "(oct) : " << std::oct << pos_int << std::endl;

    }

    {// uppercase and nouppercase
    int pos_int = 717171;
    std::cout << "pos_int (nouppercase: default) : " << std::endl;
    std::cout << "(dec) : " << std::dec << pos_int << std::endl;
    std::cout << "(hex) : " << std::hex << pos_int << std::endl;
    std::cout << "(oct) : " << std::oct << pos_int << std::endl;

    std::cout << "pos_int (uppercasae) : " << std::endl;
    std::cout << std::uppercase;
    std::cout << "(dec) : " << std::dec << pos_int << std::endl;
    std::cout << "(hex) : " << std::hex << pos_int << std::endl;
    std::cout << "(oct) : " << std::oct << pos_int << std::endl;
    }

    {// control floating point numbers
    // std::scientific and std::fixed
    // Let's start the floating point numbers now, print it in scientific and fixed way.
    double var_double = 8349.34304;
    std::cout<<std::scientific<<var_double<<std::endl;
    std::cout<<std::fixed<<var_double<<std::endl;

    double pi{3.14159265358979};
    long double plank{6.62607015e-34}; // Js (Joule-seconds)
    double goldenRatio{1.618};
    std::cout<< "double values (default: use scientific where necessary)"<<std::endl;
    std::cout<<std::setprecision(3); // default is 6
    std::cout<< "PI : " << pi <<std::endl;
    std::cout<<std::setprecision(4);
    std::cout<< "Plank's Constant : " << plank << std::endl;
    std::cout<< "Golden ratio : " << goldenRatio << std::endl;

    // if precision is bigger than the supported type, it will print garbage
    // for eg. double supports 15 (say)
    std::cout<<"Scientific Plank's Constant : " << std::setprecision(8)<< 
    std::scientific<< plank << std::endl;
    
    }

    { // showpoint and noshowpoint : show trailing zeros if necessary
    // Force output of the decimal point

    // flush to make sure previous blocks have no impact
    std::cout<<std::flush;

    double d{34.1};
    double e{101.99};
    double f{12.0};
    int g{45};

    std::cout<<"noshowpoint (default) : " << std::endl;
    std::cout<<"d : " << d << std::endl;
    std::cout<<"e : " << e << std::endl;
    std::cout<<"f : " << f << std::endl;
    std::cout<<"g : " << g << std::endl;

    std::cout<<"showpoint: " << std::endl;
    std::cout<<std::showpoint;
    std::cout<<"d : " << d << std::endl;
    std::cout<<"e : " << e << std::endl;
    std::cout<<"f : " << f << std::endl;
    std::cout<<"g : " << g << std::endl; 

    // Note : The std::showpoint manipulator is primarily intended for floating-point numbers to ensure that the decimal point and 
    // trailing zeros are always displayed. Its effect on integer types is not standardized, and in some implementations, it may lead 
    // to unexpected behavior, such as interpreting the integer as an octal value.
    // g's value is printed in octal here.
    }
    return 0;
}
