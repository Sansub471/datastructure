// You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform 
// this absolute path into its simplified canonical path.

// The rules of a Unix-style file system are as follows:

// A single period '.' represents the current directory.
// A double period '..' represents the previous/parent directory.
// Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
// Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, 
// '...' and '....' are valid directory or file names.
// The simplified canonical path should follow these rules:

// The path must start with a single slash '/'.
// Directories within the path must be separated by exactly one slash '/'.
// The path must not end with a slash '/', unless it is the root directory.
// The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
// Return the simplified canonical path.
#pragma once
#include<stack>
#include<string>
std::string simplifyPath(std::string path) {
    std::stack<char> simplePath;
    std::string temp;
    bool parent = false;
    for(int i = path.length() - 1; i >= 0; --i){
        char ch = path[i];
        if(simplePath.empty() && ch == '/') continue;
        if(ch=='.'){
            temp.push_back(ch);
            continue;
        }
        if(parent && ch != '/'){
            continue;
        }else if(parent && ch == '/'){
            parent = false;
            continue;
        }
        if(temp.length() > 2){
            for(int j=temp.length() - 1; j>=0; --j){
                simplePath.push(temp[j]);
            }
        }else if(temp.length() == 2 && ch == '/'){
                parent = true;
                temp = "";
                continue;
        }else{
            temp = "";
        }
        if(!simplePath.empty() && ch =='/' && simplePath.top() == '/'){
            continue;
        }
        simplePath.push(ch);
    }
    if(simplePath.empty() || simplePath.top() != '/') simplePath.push('/');
    temp.clear();
    while(!simplePath.empty()){
        temp.push_back(simplePath.top());
        simplePath.pop();
    }
    return temp;
}