#include<iostream>
#include<vector>

#include"../localLib/randomIntElems.hpp"
#include"../localLib/treeTraversalPrint.hpp"

namespace BST{
    #include"../BinaryTree/binarySearchTree.hpp"
}
namespace AVL{
    #include"../AVLTree/AVLTree.hpp"
}
namespace RB{
    #include"../RedBlackTree/redBlackTree.hpp"
}

#include"heightOfBST.hpp"
#include"maxMinNode.hpp"

int main(){
    // Creating variations of BST trees, including AVL and RB Tree
    RandomIntElements tree = RandomIntElements(2, 100, 20);
    std::vector<int> randomElems = tree.getRandomNumbers();
    std::cout<<"The array to create trees are: "; 
    tree.printElements();

    // Creating BST Trees
    BST::CNode* bst = BST::createBSTree(static_cast<BST::CNode*>(nullptr), randomElems);
    std::cout<<"The binary search tree is : "<<std::endl;
    Traversal::printTree(bst);


    const std::string task = "Creating AVL Tree from random elements";
    AVL::Node* avl = AVL::AVLTree(randomElems, task);
    //Traversal::printTree(avl);
    //AVL::printAVLTree(avl);

    RB::RedBlackTree* rbt = RB::RBTree(randomElems);
    // Why can't I access the methods of rbt object?
    //rbt->printTree(); // Why is this not working?
    //Traversal::printTree(rbt->getRoot());

    std::cout<<"The height of BST = " << BSTheight(bst) << std::endl;
    std::cout<<"The height of AVL = " << BSTheight(avl) << std::endl;
    //std::cout<<"The height of RBT = " << BSTheight(rbt->getRoot()) << std::endl;
}