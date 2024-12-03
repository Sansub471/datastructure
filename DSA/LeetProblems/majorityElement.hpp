#pragma once
#include<vector>
#include<algorithm>
int majorityElement(std::vector<int>& nums) {
    // int n = nums.size();
    // std::sort(nums.begin(), nums.end());
    // int count = 0;
    // int i;
    // for(i = 0; i < n; ++i){
    //     if(i > 0 && nums[i] == nums[i - 1]){
    //         ++count;
    //         continue;
    //     }else{
    //         if(count > n/2) return nums[i-1];
    //         count = 1;
    //     }
    // }
    // if(count > n/2) return nums[i-1];
    // // for compiler
    // return -1;

    // For linear approach Boyer-Moore voting algorithm
    // majority element can cancel out non majority element and still be left with majority element
    int count = 0;
    int candidate = nums[0];

    //1. Find the candidate
    for(int num : nums){
        if(count == 0){
            candidate = num;
        }

        count += (num == candidate) ? 1 : -1;
    }
    //2. Optional step, verify the candidate
    count = 0;
    for(int num : nums){
        if(num == candidate){
            ++count;
        }
    }
    return count > nums.size() / 2 ? candidate : -1;

    // O(N) as well as O(1)
}

// Sorting takes O(NlogN) where as after sorting only O(N) hence sorting time is the time complexity

std::vector<int> majorityElement2(std::vector<int>& nums) {
    // int n = nums.size();
    // std::sort(nums.begin(), nums.end());
    // std::vector<int> result;
    // int count = 0, i;
    // for(i = 0; i < n; ++i){
    //     if(i > 0 && nums[i] == nums[i-1]){
    //         ++count;
    //         continue;
    //     }else{
    //         if(count > n / 3) result.push_back(nums[i-1]);
    //         count = 1;
    //     }
    // }
    // if(count > n / 3) result.push_back(nums[i-1]);
    // return result;

    // Liner complexity 
    // k = 3, hence at most k - 1 candidates
    int candidate1 =0, candidate2 = 1;
    int count1 = 0, count2 = 0;
    std::vector<int> result;
    int n = nums.size();
    for(int num: nums){
        if(num == candidate1){
            ++count1;
        }else if(num == candidate2){
            ++count2;
        }else if(count1 == 0){
            candidate1 = num;
            count1 = 1;
        }else if(count2 == 0){
            candidate2 = num;
            count2 = 1;
        }else{
            --count1; 
            --count2;
        }
    }
    count1 = count2 = 0;
    for(int num : nums){
        if(num == candidate1) ++count1;
        if(num == candidate2) ++count2;
    }
    if(count1 > n / 3) result.push_back(candidate1);
    if(count2 > n / 3) result.push_back(candidate2);
    return result;
}