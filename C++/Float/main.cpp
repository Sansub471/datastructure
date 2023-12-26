#include<iostream>
#include<iomanip>

// type             size        precision   comment
// float              4             7       
// double             8             15      recommended default
// long double        12            > double

// Memory depends on compiler
// long double is showing 16 on my system

int main(int argc, char** argv){
    float num {23.9898f}; // the f makes sure it's floating point
    // 

    float floating_num (897.2380); // 4 bytes
    double double_num {8897234.1293182301}; // 8 bytes
    long double long_double_num {908.1209839018290381902380912L}; // 12 bytes


    double number1 {1.924e8};
    double number2 {3.498e-11};

    //std::cout << std::setprecision(8); // control the precision from std::cout
    std::cout << "The floating_num : " << floating_num << ", size = " << sizeof(floating_num) << std::endl;
    std::cout << "The double_num : " << double_num << ", size = " << sizeof(double_num) << std::endl;
    std::cout << "The long_double_num : " << long_double_num << ", size = " << sizeof(long_double_num) << std::endl;
    
    std::cout << "Number 1 : " << number2 << std::endl;
    

    // Infinity 
    double result {number1 / 0.0};
    std::cout << "Infinity result : " << result << std::endl;

    // NaN 
    double nan {0.0 / 0.0 };
    std::cout << "NaN in C++ : " << nan << std::endl;
    return 0;
}