#include<iostream>
#include<vector>

// Wrapping the include files in different namespaces to avoid Node class conflict
namespace AVL {
    #include"../AVLTree/AVLTree.hpp"
}

namespace RB {
    #include"../RedBlackTree/redBlackTree.hpp"
}

namespace BST{
    #include"../BinaryTree/binarySearchTree.hpp"
}
#include"../localLib/randomIntElems.hpp"
#include"heightOfBST.cpp"
#include"maxMinNode.cpp"

int main(){
    // Creating variations of BST trees, including AVL and RB Tree
    RandomIntElements tree = RandomIntElements(7, 100, 20);
    std::vector<int> randomElems = tree.getRandomNumbers();
    std::cout<<"The array to create trees are: "; 
    tree.printElements();    
}