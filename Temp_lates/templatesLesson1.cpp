// Brief introduction to templates.
// The simple idea is to pass the data type as a parameter so that
//  we don’t need to write the same code for different data types

#include <iostream>

template <typename T> T myMax(T x, T y){
    return (x > y) ? x : y;
}

template <typename T, typename U, typename V> V mySum(T t, U u){
    return t + u;
}

int main()
{
    // call myMax for int
    std::cout<<myMax<int>(3,7)<<std::endl;
    // call myMax for double
    std::cout << myMax<double>(3.0, 7.0) << std::endl;
    // call myMax for char
    std::cout << myMax<char>('g', 'e') << std::endl;

    //call mySum for <int> <float><double>
    std::cout<<mySum<int, float, double>(23, 45.4)<<std::endl;
    
    // call mysum for <float> <double> <double>
    std::cout<<mySum<float, double, double>(12.23, 89.12)<<std::endl;

    std::cout<<mySum<int, double, int>(12, 89.12)<<std::endl;
    //std::cout<<mySum<float, double, double>(12.23, 89.12)<<std::endl;
    //std::cout<<mySum<float, double, double>(12.23, 89.12)<<std::endl;

    return 0;
}
