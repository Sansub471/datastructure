#pragma once
#include<vector>
#include<algorithm>

void backtrackCombinations(std::vector<int>& candidates, std::vector<std::vector<int>>& combinations, std::vector<int>& currComb, int target, int index){
    if(index >= candidates.size()) return;
    int targetComp = target - candidates[index];
    if(targetComp > 0) currComb.push_back(candidates[index]);
    if(targetComp < 0) return;
    if(targetComp == 0 ){
        combinations.push_back(currComb);
    }
    backtrackCombinations(candidates, combinations, currComb, targetComp, index);      
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> combinations;
    // 1. sort the candidates to prevent duplicate combination
    std::sort(candidates.begin(), candidates.end());

    // 2. Backtracking and DF search technique
    for(int i = 0; i < candidates.size(); ++i){
        std::vector<int> currComb;
        backtrackCombinations(candidates, combinations, currComb, target, i);
    }
    return combinations;
}