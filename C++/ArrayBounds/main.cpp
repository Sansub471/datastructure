#include<iostream>


int main(){
    int numbers[]{1,2,3,4,5,6,7,8,9,10,77};
    // Read beyond bounds : will read garbage or crash your program
    std::cout<<"numbers[22]" << numbers[22] << std::endl;

    // write beyond bounds. The compiler allows it. But you don't own
    // the memory so others program may modify your data or you might 
    // be modyfing the data of other program
    // not a good practice
    // it might corrupt the data at that location
    // the program will crash

    numbers[349039] = 89;
    std::cout<<"numbers[349039]" << numbers[349039] << std::endl;

    return 0;
}