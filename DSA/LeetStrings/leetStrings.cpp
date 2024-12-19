#include<iostream>
#include<string>

#include"firsOccurIndex.hpp"

int main(){
    std::string haystack = "sadbutsad";
    std::string needle = "sad";
    int index = strStr(haystack, needle);
    return 0;
}