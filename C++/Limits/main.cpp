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
                << std::numeric_limits<short>::max() << std::endl;
    std::cout<< "The range for unsigned short is from " << std::numeric_limits<unsigned short>::min() << " to " 
                << std::numeric_limits<unsigned short>::max() << std::endl;

    std::cout<< "The range for int is from " << std::numeric_limits<short>::min() << 
                " to " << std::numeric_limits<int>::max() << std::endl;
    std::cout<< "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to " 
                << std::numeric_limits<unsigned int>::max() << std::endl;

    std::cout<< "The range for long is from " << std::numeric_limits<long>::min() << " to " 
                << std::numeric_limits<long>::max() << std::endl; // equivalent to long int

    std::cout<< "The range for long int is from " << std::numeric_limits<long int>::min() << " to " 
                << std::numeric_limits<long int>::max() << std::endl;
    
    std::cout<< "The range for unsigned long int is from " << std::numeric_limits<unsigned long int>::min() << " to " 
                << std::numeric_limits<unsigned long int>::max() << std::endl; // equivalent to unsigned long

    std::cout<< "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to " 
                << std::numeric_limits<unsigned int>::max() << std::endl;

    std::cout<< "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to " 
                << std::numeric_limits<unsigned int>::max() << std::endl;

    std::cout<< "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to " 
                << std::numeric_limits<unsigned int>::max() << std::endl;
    return 0;
}
