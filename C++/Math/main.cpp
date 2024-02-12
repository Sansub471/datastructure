#include<iostream>
#include<cmath>

int main()
{

    double sin90 = std::sin(90); // Radian
    std::cout<<"The value of sin90 is : " << sin90 << std::endl;

    double tan90 = std::tan(90);
    std::cout<<"The value of tan(90) is : " << tan90 << std::endl;

    double epow = std::exp(100);
    std::cout<<"The value of exp(100) is : " << epow << std::endl;

    double china = std::log(epow);
    std::cout<<"The log(200) is : " << china << std::endl;

    double l10 = 10;
    std::cout<<"The log10 of " << l10 << " is : " << std::log10(l10) << std::endl;

    // log and exp are inverse to each other

    float saving = -4598.900;
    std::cout<<"The saving is : " << std::abs(saving) << std::endl;

    float round = 7.7;
    std::cout<<"The ceil of " << round << " is : " << std::ceil(round) << std::endl;
    std::cout<<"The flooe of " << round << " is : " << std::floor(round) << std::endl;

    return 0;
}

// click the link for more information on cmath library
// https://en.cppreference.com/w/cpp/header/cmath