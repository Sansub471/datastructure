#ifndef M_WAY_TREE
#define M_WAY_TREE

#include<iostream>
#include<vector>

// m-way Tree Node

#ifndef MTreeNode
#define MTreeNode
template<typename Key, int M>
struct MNode {
    int count = 0; // current number of keys, tracking occupied key slots
    Key keys[M - 1]; // upto M - 1 keys
    MNode* children[M] = {nullptr}; // up to M children
    bool isLeaf = true;
};

#endif

template<typename Key, int M>
class MWayTree {
    private:
        using Node = MNode<Key, M>; // Node is just an alias for MNode<Key, M>
        Node* root;

        // linearly search single element in a node
        // if not found, recursively decend into the correct child based on where
        // the key would fall
        Node* search(Node* node, const Key& k); 
      
        void insertNonFull(Node* node, const Key& k);
        void splitChild(Node* parent, int index);
        void printNode(Node* node, int depth);

    public:
        MWayTree();
        
        bool contains(const Key& k);
        
        void insert(const Key& k);
        void print();
};

#include"mTree.tpp" // Template implementation

// Note : Template definition must be visible at compile time, can't compile them as .cpp file
// C++ templates must be defined in the same translation unit where they're used.

/*
📦 What’s a "translation unit"?
A translation unit is basically one .cpp file plus everything it includes (like headers).

So when you compile main.cpp, it becomes its own "world" — the compiler only sees whatever you #include in that file.

🚫 The Problem
If your template function or class definition is only in a .cpp file (like MWayTree.cpp), and you're just #include ing 
the .hpp file in main.cpp, then the compiler:

Sees the template declaration (what it looks like)

❌ But can’t see how it works, so it can’t build the actual version like MWayTree<int, 4>

✅ The Fix
Put the full template code (not just the declaration) in a header file (.hpp) or a separate included file (.tpp) 
— and include it in your .hpp.

This way, when any .cpp includes your .hpp, it has everything it needs to build that version of the template.

📌 Analogy
Imagine you give your friend a blueprint (header file) of a machine (your template class), and tell them 
to build one for a specific use case.

If you don’t also give them the instructions (source code/definitions), they won’t know how to actually 
build it.


*/

/*
File Roles in C++
📁 File Role Summary
Extension	Common Use	                            Meaning / Convention
.ipp	Inline/preprocessor/template code	"Inline PreProcessor" or "Impl Parts"
.inl	Inline code	                        "Inline"
.tpp	Template implementation	            "Template PreProcessor" or "Template Parts"


*/

#endif

// When will I complete the table? 