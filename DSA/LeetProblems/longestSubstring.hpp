#pragma once
#include<iostream>
#include<unordered_map>
#include<string>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> str_map;
    int start = 0, maxLength = 0;
    for(int end = 0; end < s.length(); ++end){
        char currChar = s[end];
        if(str_map.find(currChar) != str_map.end()){
            start = std::max(start, str_map[currChar] + 1);
        }
        str_map[currChar] = end;
        maxLength = std::max(maxLength, end-start+1);
    }
    // The subtring : s.substr(start, maxLength);
    return maxLength;
}

// Leet solution
int lengthOfLongestSubstringLeet(std::string s) {
    int maxC = 0, l = 0;
    int seen[256]= {0};
    for (int r = 0; r < s.size(); r++) {
        seen[s[r]]++;

        while (seen[s[r]] > 1) {
            seen[s[l]]--; 
            l++; 
        }
        maxC = std::max(r-l+1, maxC);
    }
    return maxC;
}