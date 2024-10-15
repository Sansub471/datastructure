#include<iostream>
#include<vector>

#include"AVLTree.hpp"

int main(){
    // Create an array to insert elements into AVL tree
    std::vector<int> avltree {33,13,53,61,13,21,11,12,8,9};
    const std::string task = " create AVL tree and check balancing, left and right turns. ";
    Node* root = AVL::createAVLTree(avltree, task);

    // AVL tree with Left-Right rotation
    std::vector<int> lravl {50,30,70,10,40,35};
    const std::string task1 = " with Left-Right rotation case.";
    Node* root1 = AVL::createAVLTree(lravl, task1);
 
    // AVL Tree with Right-Left Rotation
    std::vector<int> rlavl {30,50,10,70,60};
    const std::string task2 = " with Right-Left rotation.";
    Node* root2 = AVL::createAVLTree(rlavl, task2);
 
    // Delete example
    std::vector<int> delAVL {33,13,53,21,61,9,11,8};
    const std::string task3 = " delete node.";
    Node* root3 = AVL::createAVLTree(delAVL, task3);

    // node with both children
    int key = 13;
    const std::string dtask1 = "node with both children.";
    root3 = AVL::removeAVLNode(root3, key, dtask1);

    // delete leafnode
    key = 35;
    const std::string dtask2 = "leafnode.";
    root1 = AVL::removeAVLNode(root1, key, dtask2);

    // delete node with one children
    key = 8;
    const std::string dtask3 = "node with one children.";
    root = AVL::removeAVLNode(root, key, dtask3);
 
    // non-existent node
    key = 78;
    const std::string dtask4 = "non-existent node.";
    root2 = AVL::removeAVLNode(root2, key, dtask4);   
    return 0;
}