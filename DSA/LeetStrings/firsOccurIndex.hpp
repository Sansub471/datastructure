#pragma once
#include<string>

int strStr(std::string& haystack, std::string& needle) {
    const int SIZE = haystack.length();
    const int sz = needle.length();
    for(int i = 0 ; i < SIZE; ++i){
        if(haystack.substr(i, sz) == needle) return i;
    }
    return -1;
}