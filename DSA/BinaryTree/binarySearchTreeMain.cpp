
#include"binarySearchTree.cpp"

int main(){
    SNode* bst1 = BST_ONE();
    CNode* bst2 = BST_TWO();

    std::cout<<"----------------------Binary Search Tree------------------"<<std::endl;
    std::cout<<"Tree one(inorder) : "; inorderDFS(bst1); std::cout<<std::endl;
    std::cout<<"Tree two(inorder) : "; inorderDFS(bst2); std::cout<<std::endl;

    int key = 5;
    std::cout<<"Tree one has " << key << " ? : " << SearchBST(bst1, key) << std::endl;
    std::cout<<"Tree two has " << key << " ? : " << SearchBST(bst2, key) << std::endl;

    bst1 = InsertBST(bst1, key);
    bst2 = InsertBST(bst2, key);
    std::cout<<std::endl;
    std::cout<<"Tree one(inorder) : "; inorderDFS(bst1); std::cout<<std::endl;
    std::cout<<"Tree two(inorder) : "; inorderDFS(bst2); std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Tree one has " << key << " ? : " << SearchBST(bst1, key) << std::endl;
    std::cout<<"Tree two has " << key << " ? : " << SearchBST(bst2, key) << std::endl;

    // delete a node
    key = 7 ; // leaf node deletion
    bst2 = deleteBSTNode(bst2, key);
    std::cout<<"Tree two, deleted node : " << key << std::endl;
    std::cout<<"Tree two(inorder) : "; inorderDFS(bst2); std::cout<<std::endl;
    return 0;
}
