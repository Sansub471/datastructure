#include"redBlackTree.hpp"

// private methods
void RedBlackTree::initializeNULLNode(Node* node, Node* parent){
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = false; // black
}

Node* RedBlackTree::newNode(int key){
    Node* node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = true; // red
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
    if(root == TNULL || key == root->data) return root;
    if(key < root->data) return searchTreeHelper(root->left, key);
    return searchTreeHelper(root->right, key);
}

void RedBlackTree::insertFix(Node* newNode){
    RBNodePtr uncleNode; // 
    // parent is RED
    while(newNode->parent->color == true){
        // newNode's parent is the right child of its grandparent
        if(newNode->parent == newNode->parent->parent->right){
            uncleNode = newNode->parent->parent->left;
            // newNode's uncle(left sibling of newNode's parent) is RED
            if(uncleNode->color == true){
                uncleNode->color = false;
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                newNode = newNode->parent->parent;
            }// newNode'e uncle(left sibling of newNode's parent) is BLACK
            else{
                // newNode is the left child of its parent
                if(newNode == newNode->parent->left){
                    newNode = newNode->parent;
                    rightRotate(newNode);
                }
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                leftRotate(newNode->parent->parent);
            }
        }// newNode's parent is the left child of its grandparent
        else{
            uncleNode = newNode->parent->parent->right;
            // newNode's uncle(right sibling of newNode's parent) is RED
            if(uncleNode->color == true){
                uncleNode->color = false;
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                newNode = newNode->parent->parent;
            }//newNode's uncle(right sibling of newNode's parent) is BLACK
            else{
                // newNode is the right child of its parent
                if(newNode == newNode->parent->right){
                    newNode = newNode->parent;
                    leftRotate(newNode);
                }
                newNode->parent->color = false;
                newNode->parent->parent->color = true;
                rightRotate(newNode->parent->parent);
            }
        }
        if(newNode == root) break;
    }
    root->color = false;
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
    TNULL->color = false;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
}

Node* RedBlackTree::minimun(Node* root){
    while(root->left != TNULL){
        root = root->left;
    }
    return root;
}

Node* RedBlackTree::maximum(Node* root){
    while(root->right != TNULL){
        root = root->right;
    }
    return root; 
}

Node* RedBlackTree::successor(Node* root){
    if(root->right != TNULL) return minimun(root->right);
    Node* node = root->parent;
    while(node != TNULL && root == node->right){
        root = node;
        node = node->parent;
    }
    return node;
}

Node* RedBlackTree::predecessor(Node* root){
    if(root->left != TNULL) return maximum(root->left);
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

void RedBlackTree::insert(int key){
    // creating a newNode
    Node* newNode = new Node;
    newNode->parent = nullptr;
    newNode->data = key;
    newNode->left = TNULL;
    newNode->right = TNULL;
    newNode->color = true; // RED

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
        root = newNode;
    }else if(newNode->data < Y->data){
        Y->left = newNode;
    }else{
        Y->right = newNode;
    }

    // empty tree, coloring root black
    if(newNode->parent == nullptr){
        newNode->color = false;
        return;
    }

    // for height 2, no balancing or recoloring required.
    if(newNode->parent->parent == nullptr) return;

    // pass newNode to insertFix()
    insertFix(newNode);
}

int main(){
    RedBlackTree rbt;
    rbt.insert(33);
    rbt.insert(53);
    rbt.insert(21);
    rbt.insert(31);
    rbt.insert(13);
    rbt.insert(10);
    rbt.insert(9);
    rbt.printTree();
    return 0;
}
