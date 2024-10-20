#pragma once

#include<vector>
#include<unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_map;
    for(int i = 0; i < nums.size(); i++){
        int comp = target - nums[i];
        if(num_map.find(comp) != num_map.end()){
            return {num_map[comp], i};
        }
        num_map[nums[i]] = i; // add current element
    }
    return {};
}