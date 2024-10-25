#pragma once
#include<vector>
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int p1=0, p2=0;
    std::vector<int> nums;
    while(p1 < nums1.size() && p2 < nums2.size()){
        if(nums1.at(p1) <= nums2.at(p2)){
            nums.push_back(nums1.at(p1));
            p1++;
        }
        else{
            nums.push_back(nums2.at(p2));
            p2++;
        }
    }
    while(p1 < nums1.size()){
        nums.push_back(nums1.at(p1));
        p1++;
    }
    while(p2 < nums2.size()){
        nums.push_back(nums2.at(p2));
        p2++;
    }
    double pos = (nums.size()+1) / 2.0;
    int index = (nums.size()+1) / 2;
    double median = nums.at(index-1) + (pos - index)*(nums.at(index) - nums.at(index-1));
    return median;  
}