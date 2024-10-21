// The structure implementation is more C like
#include"binaryTree.hpp"
#include"binaryTreeTraversal.hpp"

#include"isFullBinary.hpp"
#include"isPerfectBinary.hpp"
#include"isCompleteBinary.hpp"
#include"isBalancedBinary.hpp"
#include"isBinarySearchTree.hpp"

int main(){
    struct Node* root = newNode(7);
    root->left = newNode(9);
    root->right = newNode(13);

    root->left->left = newNode(5);
    root->left->right = newNode(3);

    root->right->left = newNode(2);
    root->right->right = newNode(11);

    std::cout<<"\nThe pre-order traversal : "; Preorder(root);
    std::cout<<"\nThe in-order traversal  : "; Inorder(root);
    std::cout<<"\nThe post-order traversal: "; Postorder(root);
    std::cout<<std::endl;

    std::cout<<"The tree is Full Binary or not? : " << isFullBinaryTree(root) << std::endl;
    // to check if full binary add one more element at the extreme left and check if full binary
    root->left->left->left = newNode(17);
    std::cout<<"The tree is Full Binary or not? : " << isFullBinaryTree(root) << std::endl;
    root->left->left->right = newNode(23);
    std::cout<<"The tree is Full Binary or not? : " << isFullBinaryTree(root) << std::endl;

    std::cout<<"The Depth of the tree is : " << depth(root) << std::endl;

    struct Node* pbt = perfectBinaryTree();
    std::cout<<"\n-------------Perfect Binary Tree--------"<<std::endl;
    std::cout<<"The inorder traversal of tree : "; Inorder(pbt); std::cout<<std::endl;
    int d = depth(pbt);
    std::cout<<"The depth of the tree : " << d << std::endl;

    std::cout<<"Is the tree a PBT ? " << isPerfectBinaryTree(pbt, d) << std::endl;

    struct Node* cbt = completeBinaryTree();
    std::cout<<"\n-------------Complete Binary Tree--------"<<std::endl;
    std::cout<<"The inorder traversal of tree : "; Inorder(cbt); std::cout<<std::endl;
    int countNodes = countNodesNumber(cbt);
    std::cout<<"The number of nodes is : " << countNodes << std::endl;
    int index = 0; 
    if(isCompleteBinary(cbt, index, countNodes)){
        std::cout<<"The tree is a complete binary tree."<<std::endl;
    }
    else{
        std::cout<<"The tree is not a complete binary tree."<<std::endl;
    }

    struct Node* bbt = balancedBinaryTree();
    std::cout<<"\n-------------Balanced Binary Tree--------"<<std::endl;
    std::cout<<"The inorder traversal of tree : "; Inorder(bbt); std::cout<<std::endl;
    int height = 0; 
    if(isBalancedBinary(bbt, &height)){
        std::cout<<"The tree is a balanced binary tree."<<std::endl;
    }
    else{
        std::cout<<"The tree is not a balanced binary tree."<<std::endl;
    }
    std::cout<<"The height of the tree is : " << height << std::endl; // gives +1
    return 0;
}
