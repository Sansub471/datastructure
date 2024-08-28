// Let's learn about predefined functors
// The details are at : https://www.programiz.com/cpp-programming/functors


#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
// Usually, functors are used with C++ STL as arguments to STL algorithms like sort, count_if, all_of, etc.
// In this lesson, a predefined C++ functor greater<T>(), where T is the type of the functor parameter with the STL algorithm sort.

int main() {

    // initialize vector of int
    std::vector<int> nums = {1, 20, 3, 89, 2};

    // sort the vector in descending order
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    for(const auto& num: nums) {
        std::cout << num << ", ";
    }
    std::cout<<std::endl;

    for(auto itr=nums.begin(); itr!=nums.end(); ++itr){
        std::cout<<*itr<<", ";
    }
    std::cout<<std::endl;

  return 0;
}