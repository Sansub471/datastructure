#include"redBlackTree.hpp"

#include"../localLib/randomIntElems.hpp"

// private methods
void RedBlackTree::initializeNULLNode(Node* node, Node* parent){
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = BLACK;
}

Node* RedBlackTree::newNode(int key){
    Node* node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = RED;
    //node->colour = Red;
    return node;
}

void RedBlackTree::preOrderHelper(Node* node){
    if(node != TNULL){
        std::cout<<node->data<<", ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}


void RedBlackTree::inOrderHelper(Node* node){
    if(node != TNULL){
        inOrderHelper(node->left);
        std::cout<<node->data<<", ";
        inOrderHelper(node->right);
    }
}

void RedBlackTree::postOrderHelper(Node* node){
    if(node != TNULL){
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout<<node->data<<", ";
    }
}

Node* RedBlackTree::searchTreeHelper(Node* root, int key){
    // root is local here
    if(root == TNULL || key == root->data) return root;
    if(key < root->data) return searchTreeHelper(root->left, key);
    return searchTreeHelper(root->right, key);
}

void RedBlackTree::deleteFix(Node* u){
    RBNodePtr s; // sibling of u
    while(u != this->root && u->color == BLACK){
        // s is right child case
        if(u == u->parent->left){
            s = u->parent->right;
            // if sibling is RED, Right case.
            if(s->color == RED){
                s->color = BLACK;
                u->parent->color = RED;
                this->leftRotate(u->parent);
                s = u->parent->right;
            }

            // if sibling is BLACK
            // both children of sibling are BLACK or both nephews are BLACK
            if(s->left->color == BLACK && s->right->color == BLACK){
                s->color = RED;
                u = u->parent; // recur for the parent of u
            }// at least one of the sibling's children is RED or at least one of the nephew is RED
            else{
                // Only left child of s is RED, Right-Left case
                if(s->right->color == BLACK){
                    s->left->color = BLACK;
                    s->color = RED;
                    this->rightRotate(s);
                    s = u->parent->right;
                }

                // Right child of s is RED or both children are RED, Right-Right case
                s->color = u->parent->color;
                u->parent->color = BLACK;
                s->right->color = BLACK;
                this->leftRotate(u->parent);
                u =  this->root;
            }
        }// s is left child case
        else{
            s = u->parent->left;
            // if sibling is RED, Left case.
            if(s->color == RED){
                s->color = BLACK;
                u->parent->color = RED;
                this->rightRotate(u->parent);
                s = u->parent->left;
            }

            // if sibling is BLACK
            // both children of sibling are BLACK or both nephews are BLACK
            if(s->left->color == BLACK && s->right->color == BLACK){
                s->color = RED;
                u = u->parent; // recur for the parent of u
            }// at least one of the sibling's children is RED or at least one of the nephew is RED
            else{
                // Only right child of s is RED, Left-Right case
                if(s->left->color == BLACK){
                    s->right->color = BLACK;
                    s->color = RED;
                    this->leftRotate(s);
                    s = u->parent->left;
                }

                // Left child of s is RED or both children are RED, Left-Left case
                s->color = u->parent->color;
                u->parent->color = BLACK;
                s->left->color = BLACK;
                this->rightRotate(u->parent);
                u = this->root;
            }
        }
    }
    u->color = BLACK;
}

void RedBlackTree::rbTransplant(Node* v, Node* u){
    if(v->parent == nullptr){
        this->root = u;
    }else if(v == v->parent->left){
        v->parent->left = u;
    }else{
        v->parent->right = u;
    }
    u->parent = v->parent;
}

void RedBlackTree::deleteNodeHelper(Node* node, int key){
    RBNodePtr z = TNULL; // nTBd
    RBNodePtr y; // inorder successor of nTBd
    RBNodePtr x; // child of nTBd(z or y), u in geeks theory
    // for leaf node or node with one child case, z is nTBd
    // for node with two children, y becomes nTBd

    // From BST deletion, nTBd with no child or one child cases would be enough
    // BST search for nTBd
    while(node != TNULL){
        if(node->data == key){
            z = node;
            break; // nodeToBeDeleted found; nTBd 
        }
        if(key >= node->data){
            node = node->right;
        }else{
            node = node->left;
        }
    }
    
    if(z == TNULL){
        std::cout<<"Key not found or tree NULL."<<std::endl;
        return;
    }
  
    bool nTBdColor = z->color;

    // nTBd is leaf or no left child
    if(z->left == TNULL){
        x = z->right;
        this->rbTransplant(z, x);
    }// nTBd has no right child
    else if(z->right == TNULL){
        x = z->left;
        this->rbTransplant(z, x);
    }// nTBd has both children
    else{
        y = this->minimun(z->right); // in-order successor, leaf node or a node with only right child
        nTBdColor = y->color; // the node is copied in place of original nTBd, and y is actually deleted from memory
        x = y->right; // if y has a child it must be the right child
        if(y->parent == z){
            x->parent = y; 
        }else{
            this->rbTransplant(y, x); // x takes the place of y
            y->right = z->right;
            y->right->parent = y;
        } 
        this->rbTransplant(z, y); // y takes the place of z
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;
    if(nTBdColor == BLACK){
        this->deleteFix(x);
    }

}

void RedBlackTree::insertFix(Node* newNode){
    RBNodePtr uncleNode; 
    // parent is RED
    while(newNode->parent->color == RED){
        // newNode's parent is the right child of its grandparent
        if(newNode->parent == newNode->parent->parent->right){
            uncleNode = newNode->parent->parent->left;
            // newNode's uncle(left sibling of newNode's parent) is RED
            if(uncleNode->color == RED){
                uncleNode->color = BLACK;
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }// newNode's uncle(left sibling of newNode's parent) is BLACK
            else{
                // newNode is the left child of its parent
                if(newNode == newNode->parent->left){
                    newNode = newNode->parent;
                    this->rightRotate(newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                this->leftRotate(newNode->parent->parent);
            }
        }// newNode's parent is the left child of its grandparent
        else{
            uncleNode = newNode->parent->parent->right;
            // newNode's uncle(right sibling of newNode's parent) is RED
            if(uncleNode->color == RED){
                uncleNode->color = BLACK;
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }//newNode's uncle(right sibling of newNode's parent) is BLACK
            else{
                // newNode is the right child of its parent
                if(newNode == newNode->parent->right){
                    newNode = newNode->parent;
                    this->leftRotate(newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                this->rightRotate(newNode->parent->parent);
            }
        }
        if(newNode == this->root) break;
    }
    this->root->color = BLACK;
}

void RedBlackTree::printHelper(Node* root, std::string indent, bool last){
    if(root != TNULL){
        std::cout<< indent;
        if(last){
            std::cout<<"R----";
            indent+= "   ";
        }else{
            std::cout<<"L----";
            indent += "|   ";
        }
    std::string sColor = root->color ? "RED" : "BLACK";
    std::cout<<root->data << "("<<sColor<<")"<<std::endl;
    printHelper(root->left, indent, false);
    printHelper(root->right, indent, true);
    }
}

// public methods
RedBlackTree::RedBlackTree(){
    TNULL = new Node;
    TNULL->color = BLACK;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
}

Node* RedBlackTree::minimun(Node* root){
    while(root->left != TNULL){
        root = root->left;
    }
    return root;
    // root used here is local, don't be confused
}

Node* RedBlackTree::maximum(Node* root){
    while(root->right != TNULL){
        root = root->right;
    }
    return root; 
}

Node* RedBlackTree::successor(Node* root){
    if(root->right != TNULL) return this->minimun(root->right);
    Node* node = root->parent;
    while(node != TNULL && root == node->right){
        root = node;
        node = node->parent;
    }
    return node;
}

Node* RedBlackTree::predecessor(Node* root){
    if(root->left != TNULL) return this->maximum(root->left);
    Node* node = root->parent;
    while(node != TNULL && root == node->left){
        root = node;
        node = node->parent;
    }
    return node;
}

void RedBlackTree::leftRotate(Node* X){
    Node* Y = X->right;
    X->right = Y->left;
    if(Y->left != TNULL) Y->left->parent = X;
    Y->parent = X->parent;
    if(X->parent == nullptr){
        this->root = Y;
    }else if(X == X->parent->left){
        X->parent->left = Y;
    }else{
        X->parent->right = Y;
    }
    Y->left = X;
    X->parent = Y;
}

void RedBlackTree::rightRotate(Node* Y){
    Node* X = Y->left;
    Y->left = X->right;
    if(X->right != TNULL) X->right->parent = Y;
    X->parent = Y->parent;
    if(Y->parent == nullptr){
        this->root = X;
    }else if(Y == Y->parent->right){
        Y->parent->right = X;
    }else{
        Y->parent->left = X;
    }
    X->right = Y;
    Y->parent = X;
}

void RedBlackTree::insertNode(int key){
    // creating a newNode
    Node* newNode = new Node;
    newNode->parent = nullptr;
    newNode->data = key;
    newNode->left = TNULL;
    newNode->right = TNULL;
    newNode->color = RED;

    // Y be leaf and X be root
    Node* Y = nullptr;
    RBNodePtr X = this->root; // typedef Node* RBNodePtr

    // check if the tree is empty, if it is won't execute
    while(X != TNULL){
        Y = X;
        //X = node->data < X->data ? X->left : X->right;
        if(newNode->data < X->data){
            X = X->left;
        }else{
            X = X->right;
        }
    }

    // Y - tracks the parent of X. When X is TNULL,
    // Y is the parent of leaf(i.e. TNULL or NIL) 
    newNode->parent = Y;

    // implies empty tree
    if(Y == nullptr){ 
        this->root = newNode;
    }else if(newNode->data < Y->data){
        Y->left = newNode;
    }else{
        Y->right = newNode;
    }

    // empty tree, coloring root black
    if(newNode->parent == nullptr){
        newNode->color = BLACK;
        return;
    }

    // for height 2, no balancing or recoloring required.
    if(newNode->parent->parent == nullptr) return;

    // pass newNode to insertFix()
    this->insertFix(newNode);
}

RBNodePtr RedBlackTree::getRoot(){
                return this->root;
}

void RedBlackTree::deleteNode(int data){
    this->deleteNodeHelper(this->root, data);
}

bool RedBlackTree::search(int data){
    Node* node = this->searchTreeHelper(this->root, data);
    if(node != TNULL){
        return true;
    }
    return false;
}

void RedBlackTree::printTree(){
    if(this->root){
        this->printHelper(this->root, "", true);
    }
}

bool RedBlackTree::isTreeEmpty(){
    if(this->root == this->TNULL) return true;
    return false;
}

// outside methods
RedBlackTree* getRBTree(std::vector<int>& rbElems){
    RedBlackTree* rbt = new RedBlackTree;
    for(const auto& elem : rbElems){
        rbt->insertNode(elem);
    }
    return rbt;
}

void getrbTree(RedBlackTree* rbt, std::vector<int>& rbElems){
    for(const auto& elem : rbElems){
        (*rbt).insertNode(elem); // rbt->insert(elem); 
    }
}

void deleteOperation(RedBlackTree* rbt, int nTBd, const std::string& treeName){
    std::cout<<"RBT "<<treeName<<" , Before : "<<std::endl;
    rbt->printTree();
    rbt->deleteNode(nTBd);
    std::cout<<"RBT "<<treeName<<" , After : "<<std::endl;
    rbt->printTree();
    std::cout<<std::endl;
}
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

