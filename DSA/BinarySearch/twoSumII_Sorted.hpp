#pragma once
// The second part of the two sum problem
// 167. Two Sum II - Input Array Is Sorted
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Your solution must use only constant extra space.

// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// Brute force two sum solution, it works even for not sorted but too slow

#include<vector>


std::vector<int> twoSumI(std::vector<int>& numbers, int target) {
    // Brute force solution
    for(int i = 0; i < numbers.size(); ++i){
        int comp = target - numbers[i];
        for(int j = 0; j < numbers.size(); ++j){
            if( i == j) continue;
            if(numbers[j] == comp) return {i + 1, j + 1};
        }
    }
    // should never reach here
    return {-1, -1};
    
}

// O(n^2)

// The two-pointer approach is the easiest and the most efficient 
std::vector<int> twoSumII(std::vector<int>& numbers, int target) {
    int low = 0, high = numbers.size() - 1;
    while(low < high){
        int sum = numbers[low] + numbers[high];
        if(sum == target){
            return {++low, ++high};
        }else if(sum > target){
            --high;
        }else{
            ++low;
        }
    }
    // should never reach here
    return {};
}
// O(N)

// Binary search approach
