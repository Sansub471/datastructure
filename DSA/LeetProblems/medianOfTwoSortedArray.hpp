#pragma once
#include<vector>
std::vector<int> mergedArrays(std::vector<int>& nums1, std::vector<int>& nums2){
    int p1=0, p2=0;
    std::vector<int> merged;
    while(p1 < nums1.size() && p2 < nums2.size()){
        if(nums1[p1] <= nums2[p2]){
            merged.push_back(nums1[p1++]);
        }
        else{
            merged.push_back(nums2[p2++]);
        }
    }
    while(p1 < nums1.size()) merged.push_back(nums1[p1++]);
    while(p2 < nums2.size()) merged.push_back(nums2[p2++]);
    return merged;
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> merged = mergedArrays(nums1, nums2);
    int n = merged.size();
    if(n % 2 == 1){
        return merged[n / 2];
    }else{
        return ((merged[n / 2 - 1] + merged[n / 2]) / 2.0);
    }      
}