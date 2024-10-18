#include<iostream>
#include<vector>

#include"binarySearchTree.hpp"
#include"../localLib/randomIntElems.hpp"
#include"../localLib/treeTraversalPrint.hpp"

#include"../BSTProblems/levelTraversalArray.hpp"
#include"../BSTProblems/levelOrderBottom.hpp"
#include"../BSTProblems/avgOfLevels.hpp"
#include"../BSTProblems/treeTilt.hpp"
#include"../BSTProblems/uniqueBST1toN.hpp"
#include"../BSTProblems/sortedArrayToBST.hpp"
#include"../BSTProblems/zigzagLevelOrder.hpp"

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
    RandomIntElements treeElems = RandomIntElements(2, 100, 10);
    std::vector<int> randomElems = treeElems.getRandomNumbers();
    std::cout<<"\nThe array to create BST is: "; 
    treeElems.printElements();

    CNode* cbst = createBSTree(static_cast<CNode*>(nullptr), randomElems);
    Traversal::printTree(cbst);
    // nullptr initializes the root pointer to an empty state (i.e., no tree yet).
    // static_cast<BST::CNode*>(nullptr) explicitly casts the null pointer to the desired 
    // type (BST::CNode*) so that the templated function knows the correct node type (CNode*, SNode*, or Node<T>*) to work with.

    std::cout<<"\nThe level order traversal(left-right) is:";
    Traversal::levelOrder(cbst);
    std::cout<<"\nThe level order traversal(right-left) is:";
    Traversal::levelOrderR(cbst); std::cout<<std::endl; std::cout<<std::endl;

    // array of levelwise nodes
    std::vector<std::vector<int>> treeOne = levelTraversalArray(bst1);
    std::cout<<"Level Order, tree one : ";
    Traversal::printVector2D(treeOne);

    std::vector<std::vector<int>> treeTwo = levelTraversalArray(bst2);
    std::cout<<"Level Order, tree two : ";
    Traversal::printVector2D(treeTwo);
    std::cout<<std::endl;

    //CNode* bst3 = BST_THREE();
    std::vector<std::vector<int>> treeThree = levelTraversalArray(cbst);
    std::cout<<"Level Order, cbst : ";
    Traversal::printVector2D(treeThree);

    treeThree = levelOrderTraverse(cbst);
    std::cout<<"Level Order, cbst : ";
    Traversal::printVector2D(treeThree);

    // zig-zag level order traversal
    std::vector<std::vector<int>> zigzagTreeThree = zigzagLevelOrder(cbst);
    std::cout<<"\nZig-zag Level order, cbst : ";
    Traversal::printVector2D(zigzagTreeThree);
    zigzagTreeThree = zigzagLevelOrderLeet(cbst);
    std::cout<<"Zig-zag Level order, cbst : ";
    Traversal::printVector2D(zigzagTreeThree);

    // reverse level wise nodes
    std::vector<std::vector<int>> treeThreeRev = levelOrderBottom(cbst);
    std::cout<<"\nReverse level order, cbst : ";
    Traversal::printVector2D(treeThreeRev);
    std::cout<<std::endl;

    // average of tree levels
    std::vector<double> avgLevelOne = avgOfLevels(bst1);
    std::cout<<"Average of levels, tree one : ";
    Traversal::printVector1D(avgLevelOne);

    // tree tilt
    int tilt = treeTilt(bst2);
    std::cout<<"\nThe tilt of tree two = " << tilt << std::endl;
    Traversal::printTree(bst2);

    // unique BST from numbers 1 to N
    std::vector<CNode*> trees = uniqueBST1toN<CNode>(3);
    std::cout<<"\nThe unique BSTs are(pre-order) :";
    Traversal::printBST1toN(trees);

    // sorted array to BST
    std::vector<int> nums {1,2,3};
    CNode* arr2bst = sortedArrayToBST<CNode>(nums);
    std::cout<<"\nSorted Array Binary Search Tree is :\n";
    Traversal::printTree(arr2bst);


    delete bst2;
    delete bst1;
    delete cbst;
    return 0;
}
