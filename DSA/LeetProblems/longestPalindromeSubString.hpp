#pragma once
#include<string>

std::string expandAroundCenter(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

std::string longestPalindrome(std::string s) {
    if (s.empty()) return "";

    std::string longest = "";
    for (int i = 0; i < s.size(); i++) {
        // Check odd-length palindromes
        std::string odd = expandAroundCenter(s, i, i);
        if (odd.size() > longest.size()) longest = odd;

        // Check even-length palindromes
        std::string even = expandAroundCenter(s, i, i + 1);
        if (even.size() > longest.size()) longest = even;
    }

    return longest;
}