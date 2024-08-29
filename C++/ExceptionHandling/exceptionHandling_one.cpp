#include<iostream>
#include<iomanip>

// Basic syntax of exception handling
// try {

//     // code that may raise an exception
//     throw argument;
// }

// catch (exception) {
//     // code to handle exception
// } 

int main(){
    std::cout<<"Give the numbers : "<<std::endl;
    float num, deno;
    std::cout<<"Numerator: "; std::cin>>num;
    std::cout<<"Denominator: "; std::cin>>deno;

    try{
        if (deno == 0){
            throw 0;
        }
        float quotient = num / deno;
        std::cout<<"The quotient is : " << std::setprecision(2) << quotient << std::endl;
    }

    catch(int num_exception){
        std::cout<<"Division by " << num_exception<< " is not possible. Mathematical error." << std::endl;
    }
    return 0;
}

// We can throw any literal or variable or class, depending on the situation and depending on what we want 
// to execute inside the catch block. The catch parameter int num_exception takes the value passed by the 
// throw statement i.e. the literal 0.