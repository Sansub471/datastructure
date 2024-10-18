#include<iostream>
#include<vector>

#include"AVLTree.hpp"

int main(){
    // Create an array to insert elements into AVL tree
    std::vector<int> avltree {33,13,53,61,13,21,11,12,8,9};
    const std::string task = " create AVL tree and check balancing, left and right turns. ";
    Node* root = createAVLTree(avltree, task);

    // AVL tree with Left-Right rotation
    std::vector<int> lravl {50,30,70,10,40,35};
    const std::string task1 = " with Left-Right rotation case.";
    Node* root1 = createAVLTree(lravl, task1);
 
    // AVL Tree with Right-Left Rotation
    std::vector<int> rlavl {30,50,10,70,60};
    const std::string task2 = " with Right-Left rotation.";
    Node* root2 = createAVLTree(rlavl, task2);
 
    // Delete example
    std::vector<int> delAVL {33,13,53,21,61,9,11,8};
    const std::string task3 = " delete node.";
    Node* root3 = createAVLTree(delAVL, task3);

    // node with both children
    int key = 13;
    const std::string dtask1 = "node with both children.";
    root3 = removeAVLNode(root3, key, dtask1);
    printTree(root3);

    // delete leafnode
    key = 35;
    const std::string dtask2 = "leafnode.";
    root1 = removeAVLNode(root1, key, dtask2);
    printTree(root1);

    // delete node with one children
    key = 8;
    const std::string dtask3 = "node with one children.";
    root = removeAVLNode(root, key, dtask3);
    printTree(root);
 
    // non-existent node
    key = 78;
    const std::string dtask4 = "non-existent node.";
    root2 = removeAVLNode(root2, key, dtask4);
    printTree(root2);

    // delete allocated memory
    delete root, root1, root2, root3;   
    return 0;
}