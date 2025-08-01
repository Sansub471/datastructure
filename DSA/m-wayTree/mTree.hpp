#include<iostream>
#include<vector>

// m-way Tree Node
template<typename Key, int M>
struct MNode {
    int count = 0; // current number of keys, tracking occupied key slots
    Key keys[M - 1]; // upto M - 1 keys
    MNode* children[M] = {nullptr}; // up to M children
    bool isLeaf = true;
};

