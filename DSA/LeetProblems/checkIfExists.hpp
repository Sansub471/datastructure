#pragma once
// 1346. Check If N and Its Double Exist
// Given an array arr of integers, check if there exist two indices i and j such that :

// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]
 

// Example 1:

// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
#include<vector>
bool checkIfExist(std::vector<int>& arr) {
    
    // Brute force solution
    const int SIZE = arr.size();
    for( int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            if( i == j) continue;
            if(arr[i] == 2 * arr[j]) return true;
        }
    }
    return false;
}