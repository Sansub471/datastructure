#pragma once
#include<vector>
void mergeSortedInplace(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0){
            nums1 = nums2;
            return;
        }
        int i = m - 1; // ptr for last element in nums1
        int j = n - 1; // nums2
        int k = m + n -1; // nums1 after merge
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }

        // if any element left in nums2, move into nums1
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }