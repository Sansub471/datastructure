#include"redBlackTree.cpp"
#include"../localLib/randomIntElems.hpp"

int main(){
    RedBlackTree rbt, rbt1; // rbtTree and rbtFour
    
    std::vector<int> rbtElemOne = {33, 53, 21, 31, 13, 10, 9, 12, 13, 13, 13, 13, 45, 40};
    std::vector<int> rbtElemTwo = {33, 53, 21, 31, 13, 10, 9, 12, 13, 13, 13, 13};
    std::vector<int> rbtElemThree = {33, 53, 21, 31, 13, 10, 9, 12, 13, 13, 13, 13, 45, 40, 32};
    std::vector<int> rbtElemFour = {33, 53, 21, 31, 13, 10, 9, 12, 13, 13, 13, 13, 45, 40, 32, 49};
   
    // Insertion operation
    RedBlackTree* rbtOne = getRBTree(rbtElemOne);
    RedBlackTree* rbtTwo = getRBTree(rbtElemTwo);
    //RedBlackTree* rbtThree = getRBTree(rbtElemThree);
    getrbTree(&rbt, rbtElemThree);
    //RedBlackTree* rbtFour = getRBTree(rbtElemFour);
    getrbTree(&rbt1, rbtElemFour);
   
    std::cout<<"RBTree one : "<<std::endl;
    rbtOne->printTree();  //(*rbtOne).printTree();
    std::cout<<std::endl;

    std::cout<<"RBTree three : "<<std::endl;
    rbt.printTree();
    std::cout<<std::endl;

    // Delete operation
    deleteOperation(rbtOne, 33, "one"); // nTBd with two children, it's in-order successor not the child of nTBd
    deleteOperation(rbtTwo, 33, "two"); // nTBs with two children, it's in-order successor is a child of nTBd
    deleteOperation(rbtOne, 12, "one"); // nTBd is the leaf node
    deleteOperation(&rbt,   31, "three"); // nTBd with only right child
    deleteOperation(&rbt1,  53, "four"); // nTBd with only left child
    deleteOperation(&rbt1,  21, "four"); // nTBd is the root

    // search operation
    int key = 49;
    if(rbt1.search(key)){
        std::cout<<"\nNode " << key << " found.\n";
    }else{
        std::cout<<"\nNode" << key << " not found.\n";
    }

    // create a large RB Tree with random elements
    try{
        RandomIntElements tree = RandomIntElements(1, 10000, 7000);
        std::vector<int> randomElems = tree.getRandomNumbers();
        if(!randomElems.empty()){
            RedBlackTree* RBTree = getRBTree(randomElems);
            RBTree->printTree();

            // insert
            int newKey = tree.getNextRandomElement();
            RBTree->insertNode(newKey);

            // delete
            int nTBd = tree.getRandomElement();
            RBTree->deleteNode(nTBd);          
            
        }
    }catch(const std::invalid_argument& e){
        std::cerr<<"Caught exception. " << e.what() << std::endl;
    }
    return 0;
}

