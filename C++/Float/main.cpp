#include<iostream>

// type             size        precision   comment
// float              4             7       
// double             8             15      recommended default
// long double        12            > double

// Memory depends on compiler
// long double is showing 16 on my system

int main(int argc, char** argv){
    float floating_num (897.2380); // 4 bytes
    double double_num {8897234.1293182301}; // 8 bytes
    long double long_double_num {908.1209839018290381902380912}; // 12 bytes

    std::cout << "The floating_num : " << floating_num << ", size = " << sizeof(floating_num) << std::endl;
    std::cout << "The double_num : " << double_num << ", size = " << sizeof(double_num) << std::endl;
    std::cout << "The long_double_num : " << long_double_num << ", size = " << sizeof(long_double_num) << std::endl;
    return 0;
}