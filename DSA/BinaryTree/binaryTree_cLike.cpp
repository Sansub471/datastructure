// The structure implementation is more C like
#include"binaryTree.hpp"
#include"isFullBinaryTree.cpp"
#include"binaryTreeTraversal.cpp"

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
    return 0;
}
