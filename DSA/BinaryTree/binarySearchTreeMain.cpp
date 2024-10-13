
#include"binarySearchTree.cpp"
#include"../localLib/randomIntElems.hpp"

int main(){
    SNode* bst1 = BST_ONE();
    CNode* bst2 = BST_TWO();

    std::cout<<"----------------------Binary Search Tree------------------"<<std::endl;
    std::cout<<"Tree one(inorder) : "; inorderDFS(bst1); std::cout<<std::endl;
    printTree(bst1);
    std::cout<<"Tree two(inorder) : "; inorderDFS(bst2); std::cout<<std::endl;
    printTree(bst2);

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

    // creating a BST with randomly generated array
    RandomIntElements tree = RandomIntElements(2, 100, 20);
    std::vector<int> randomElems = tree.getRandomNumbers();
    std::cout<<"\nThe array to create BST is: "; 
    tree.printElements();

    CNode* cbst = createBSTree(static_cast<CNode*>(nullptr), randomElems);
    printTree(cbst);
    // nullptr initializes the root pointer to an empty state (i.e., no tree yet).
    // static_cast<BST::CNode*>(nullptr) explicitly casts the null pointer to the desired 
    // type (BST::CNode*) so that the templated function knows the correct node type (CNode*, SNode*, or Node<T>*) to work with.
    return 0;
}
