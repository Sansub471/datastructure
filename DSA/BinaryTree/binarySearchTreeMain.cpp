#include<iostream>
#include<vector>

#include"binarySearchTree.hpp"
#include"../localLib/randomIntElems.hpp"
#include"../localLib/treeTraversalPrint.hpp"

#include"../BSTProblems/levelTraversalArray.hpp"

int main(){
    SNode* bst1 = BST_ONE();
    CNode* bst2 = BST_TWO();

    std::cout<<"----------------------Binary Search Tree------------------"<<std::endl;
    std::cout<<"Tree one(inorder) : "; Traversal::inorderDFS(bst1); std::cout<<std::endl;
    Traversal::printTree(bst1);
    std::cout<<"Tree two(inorder) : "; Traversal::inorderDFS(bst2); std::cout<<std::endl;
    Traversal::printTree(bst2);

    int key = 5;
    std::cout<<"Tree one has " << key << " ? : " << SearchBST(bst1, key) << std::endl;
    std::cout<<"Tree two has " << key << " ? : " << SearchBST(bst2, key) << std::endl;

    bst1 = InsertBST(bst1, key);
    bst2 = InsertBST(bst2, key);
    std::cout<<std::endl;
    std::cout<<"Tree one(inorder) : "; Traversal::inorderDFS(bst1); std::cout<<std::endl;
    std::cout<<"Tree two(inorder) : "; Traversal::inorderDFS(bst2); std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Tree one has " << key << " ? : " << SearchBST(bst1, key) << std::endl;
    std::cout<<"Tree two has " << key << " ? : " << SearchBST(bst2, key) << std::endl;

    // delete a node
    key = 7 ; // leaf node deletion
    bst2 = deleteBSTNode(bst2, key);
    std::cout<<"Tree two, deleted node : " << key << std::endl;
    std::cout<<"Tree two(inorder) : "; Traversal::inorderDFS(bst2); std::cout<<std::endl;

    // creating a BST with randomly generated array
    RandomIntElements tree = RandomIntElements(2, 100, 10);
    std::vector<int> randomElems = tree.getRandomNumbers();
    std::cout<<"\nThe array to create BST is: "; 
    tree.printElements();

    CNode* cbst = createBSTree(static_cast<CNode*>(nullptr), randomElems);
    Traversal::printTree(cbst);
    // nullptr initializes the root pointer to an empty state (i.e., no tree yet).
    // static_cast<BST::CNode*>(nullptr) explicitly casts the null pointer to the desired 
    // type (BST::CNode*) so that the templated function knows the correct node type (CNode*, SNode*, or Node<T>*) to work with.

    std::cout<<"\nThe level order traversal(left-right) is:";
    Traversal::levelOrder(cbst);
    std::cout<<std::endl;

    std::cout<<"\nThe level order traversal(right-left) is:";
    Traversal::levelOrderR(cbst);
    std::cout<<std::endl;

    // array of levelwise nodes
    std::vector<std::vector<int>> treeOne = levelTraversalArray(bst1);
    std::vector<std::vector<int>> treeTwo = levelTraversalArray(bst2);

    CNode* bst3 = BST_THREE();
    std::vector<std::vector<int>> treeThree = levelTraversalArray(bst3);
    



    delete bst2;
    delete bst1;
    delete cbst;
    return 0;
}
