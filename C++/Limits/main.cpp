#include<iostream>

// Goal : Learn about numeric limit
// #include<limits> library in C++

// Floating point : 
// lowest               min             max
// -3.40282e+38         0 1.17549e-38   3.40282e+38

// Signed integer (this is short)
// min              max
// -32768           32767

// For unsigned min is zero and max is the maximum for that data type

#include<limits>


int main()
{
    std::cout<< "The range for short is from " << std::numeric_limits<short>::min() << " to " 
                << std::numeric_limits<short>::max() << std::endl; // equivalent to short int

    std::cout<< "The range for short int  is from " << std::numeric_limits<short int>::min() << " to " 
                << std::numeric_limits<short int>::max() << std::endl;
    std::cout<<std::endl;
    
    std::cout<< "The range for unsigned short is from " << std::numeric_limits<unsigned short>::min() << " to " 
                << std::numeric_limits<unsigned short>::max() << std::endl;

    std::cout<<std::endl;

    std::cout<< "The range for int is from " << std::numeric_limits<int>::min() << 
                " to " << std::numeric_limits<int>::max() << std::endl;

    std::cout<< "The range for signed int is from " << std::numeric_limits<signed int>::min() << 
                " to " << std::numeric_limits<signed int>::max() << std::endl; // equivalent to int
    std::cout<<std::endl;

    std::cout<< "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to " 
                << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout<<std::endl;

    std::cout<< "The range for long is from " << std::numeric_limits<long>::min() << " to " 
                << std::numeric_limits<long>::max() << std::endl; // equivalent to long int or signed long or signed long int

    std::cout<< "The range for signed long is from " << std::numeric_limits<signed long>::min() << 
                " to " << std::numeric_limits<signed long>::max() << std::endl;

    std::cout<< "The range for long int is from " << std::numeric_limits<long int>::min() << " to " 
                << std::numeric_limits<long int>::max() << std::endl;
    std::cout<<std::endl;

    std::cout<< "The range for unsigned long int is from " << std::numeric_limits<unsigned long int>::min() << " to " 
                << std::numeric_limits<unsigned long int>::max() << std::endl; // equivalent to unsigned long

    std::cout<< "The range for unsigned long is from " << std::numeric_limits<unsigned long>::min() << " to " 
                << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout<<std::endl;

    std::cout<< "The range for long long is from " << std::numeric_limits<long long>::min() << " to " 
                << std::numeric_limits<long long>::max() << std::endl; // equivalent to long long int or signed long long or signed long long int

    std::cout<< "The range for unsigned long long is from " << std::numeric_limits<unsigned long long>::min() << " to " 
                << std::numeric_limits<unsigned long long>::max() << std::endl; // equivalent to unsigned long long int
    std::cout<<std::endl;

    long long1 = {3499};
    long long long2 = {897998};
    std::cout<< "The size of long is : " << sizeof(long1) << std::endl;
    std::cout<< "The size of long long is : " << sizeof(long long) << std::endl;
    std::cout<<std::endl; // Here both long and long are allocated 8 bytes

    /**
    std::cout<< "The range for char is from " << std::numeric_limits<char>::min() << " to " 
                << std::numeric_limits<char>::max() << std::endl; // equivalent to signed char
    std::cout<< "The range for unsigned signed char is from " << std::numeric_limits<signed char>::min() << " to " 
                << std::numeric_limits<signed char>::max() << std::endl;  
    std::cout<< "The range for unsigned char is from " << std::numeric_limits<unsigned char>::min() << " to " 
                << std::numeric_limits<signed char>::max() << std::endl; 
    std::cout<<std::endl;
    **/

    std::cout<< "The range for float is from " << std::numeric_limits<float>::min() << " to " 
                << std::numeric_limits<float>::max() << std::endl;

    std::cout<< "The range for double is from " << std::numeric_limits<double>::min() << " to " 
                << std::numeric_limits<double>::max() << std::endl; 

    std::cout<< "The range for long double is from " << std::numeric_limits<long double>::min() << " to " 
                << std::numeric_limits<long double>::max() << std::endl;

    // Completion of Limit library

    return 0;
}
