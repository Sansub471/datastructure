// #pragma once

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
// removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

#include<string>

bool isPalindrome(std::string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !std::isalnum(s[left])) {
            ++left;
        }
        while (left < right && !std::isalnum(s[right])) {
            --right;
        }

        // Compare characters after converting to lowercase
        if (std::tolower(s[left]) != std::tolower(s[right])) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}