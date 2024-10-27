#pragma once
#include<unordered_map>
#include<string>

int romanToInt(std::string s) {
    std::unordered_map<char, int> romanIntMap{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int  intVal = romanIntMap[s[0]];
    if(s.length() < 2) return intVal;
    for(int i = 1; i < s.length(); ++i){
        int currVal = romanIntMap[s[i]];
        if(romanIntMap[s[i - 1]] < romanIntMap[s[i]]){
            currVal -= 2 * romanIntMap[s[i - 1]];
        }
        intVal += currVal;
    }
    return intVal;
}