#include"binarySearchTree.hpp"

template <typename T>
    bool SearchBST(T* root, int key){
        // check for emptiness
        if(root == nullptr) return false;

        // if current node is the key
        if(key == root->data) return true;
        if(key <  root->data) return SearchBST(root->left, key);
        if(key >  root->data) return SearchBST(root->right, key);

        // logically not necessary but the compiler expects a return type from every possible path
        return false;
    }


int main(){
    SNode* bst1 = BST_ONE();
    CNode* bst2 = BST_TWO();

    std::cout<<"----------------------Binary Search Tree------------------"<<std::endl;
    std::cout<<"Tree one(inorder) : "; inorderDFS(bst1); std::cout<<std::endl;
    std::cout<<"Tree two(inorder) : "; inorderDFS(bst2); std::cout<<std::endl;

    int key = 5;
    std::cout<<"Tree one has " << key << " ? : " << SearchBST(bst1, key) << std::endl;
    std::cout<<"Tree two has " << key << " ? : " << SearchBST(bst2, key) << std::endl;
    return 0;
}