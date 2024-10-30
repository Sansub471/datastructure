// Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:

#pragma once
#include<vector>
// Search matrix I
bool searchMatrixI(std::vector<std::vector<int>>& matrix, int target) {
    for(int i = 0; i < matrix.size(); ++i){
        if(matrix[i][0] <= target && target <= matrix[i][matrix[i].size() - 1]){
            int left = 0, right = matrix[i].size() - 1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(matrix[i][mid] == target) return true;
                if(matrix[i][mid] > target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
    }
    return false;
}

// Search matrix II
bool searchMatrixII(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[row].size() - 1;
    while(row < matrix.size() && col >= 0){
        if(matrix[row][col] == target){
            matrix.clear();
            return true;
        }
        if(matrix[row][col] > target){
            --col;
        }else{
            ++row;
        }
    }
    matrix.clear();
    return false;
}