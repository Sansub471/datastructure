#pragma once
#include<unordered_map>
#include<vector>
#include<string>

void backtrack(const std::string& digits, const std::unordered_map<char, std::string>& digitMap, 
                std::string& current, int index, std::vector<std::string>& result){
    // base case
    if(index == digits.size()){
        result.push_back(current);
        return;
    }

    // & alias to mapped string.
    const std::string& letters = digitMap.at(digits[index]);
    for(char letter : letters){
        current.push_back(letter);
        backtrack(digits,digitMap, current, index + 1, result);
        current.pop_back();
    }

    if(letters.empty()){
        backtrack(digits, digitMap, current, index + 1,result);
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    std::unordered_map<char, std::string> digitMap = {
        {'0',""},{'1',""},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    std::vector<std::string> result;

    if(digits.empty()) return result;
    
    std::string current;
    backtrack(digits, digitMap, current, 0, result);
    return result;
}