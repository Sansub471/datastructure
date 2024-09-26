#include"redBlackTree.hpp"

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
    if(root == TNULL || key == root->data) return root;
    if(key < root->data) return searchTreeHelper(root->left, key);
    return searchTreeHelper(root->right, key);
}

void RedBlackTree::deleteFix(Node* x){
    RBNodePtr s;
    while(x != root && x->color == BLACK){
        if(x == x->parent->left){
            s = x->parent->right;
            if(s->color == RED){
                s->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                s = x->parent->right;
            }

            if(s->left->color == BLACK && s->right->color == BLACK){
                s->color = RED;
                x = x->parent;
            }else{
                if(s->right->color == BLACK){
                    s->left->color = BLACK;
                    s->color = RED;
                    rightRotate(s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->right->color = BLACK;
                leftRotate(x->parent);
                x =  root;
            }
        }else{
            s = x->parent->left;
            if(s->color == RED){
                s->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                s = x->parent->left;
            }

            if(s->right->color == BLACK && s->right->color == BLACK){
                s->color = RED;
                x = x->parent;
            }else{
                if(s->left->color == BLACK){
                    s->right->color = BLACK;
                    s->color = RED;
                    leftRotate(s);
                    s = x->parent->left;
                }
                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RedBlackTree::rbTransplant(Node* u, Node* v){
    if(u->parent == nullptr){
        root = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RedBlackTree::deleteNodeHelper(Node* node, int key){
    //RBNodePtr node = this->root;
    RBNodePtr z = TNULL;
    RBNodePtr x, y;
    while(node != TNULL){
        if(node->data == key){
            z = node;
            //break;
            // break will delete the first occurence of the key
            // without it, it will delete the rightmost occurence of duplicate keys
            // can implement to delete the leftmost occurence of the duplicate key as well.

            // Visualizer : https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
            // deleted from the left, but this code does it from the right, hence result might be different
        }
        // previous : key <= node->data hence confused but same
        if(node->data <= key){
            node = node->right;
        }else{
            node = node->left;
        }
    }

    if(z == TNULL){
        std::cout<<"Key not found in the tree."<<std::endl;
        return;
    }

    y = z;
    bool y_original_color = y->color;
    if(z->left == TNULL){
        x = z->right;
        rbTransplant(z, z->right);
    }else if(z->right == TNULL){
        x = z->left;
        rbTransplant(z, z->left);
    }else{
        y = minimun(z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == z){
            x->parent = y;
        }else{
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;
    if(y_original_color == BLACK){
        deleteFix(x);
    }

}

void RedBlackTree::insertFix(Node* newNode){
    RBNodePtr uncleNode; // 
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
                    rightRotate(newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                leftRotate(newNode->parent->parent);
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
                    leftRotate(newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                rightRotate(newNode->parent->parent);
            }
        }
        if(newNode == root) break;
    }
    root->color = BLACK;
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
        root = newNode;
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
    insertFix(newNode);
}

RBNodePtr RedBlackTree::getRoot(){
                return this->root;
}

void RedBlackTree::deleteNode(int data){
    deleteNodeHelper(this->root, data);
}

void RedBlackTree::printTree(){
    if(root){
        printHelper(this->root, "", true);
    }
}


RedBlackTree* getRBTree(std::vector<int>& rbElems){
    RedBlackTree* rbt = new RedBlackTree;
    for(const auto& elem : rbElems){
        rbt->insert(elem);
    }
    return rbt;
}

void getrbTree(RedBlackTree* rbt, std::vector<int>& rbElems){
    for(const auto& elem : rbElems){
        (*rbt).insert(elem); // rbt->insert(elem); 
    }
}
int main(){
    RedBlackTree rbt;
    
    std::vector<int> rbtElemOne = {33, 53, 21, 31, 13, 10, 9, 12, 40, 45};
    RedBlackTree* rbtOne = getRBTree(rbtElemOne);
    rbtOne->printTree();  //(*rbtOne).printTree();

    std::cout<<std::endl;
    getrbTree(&rbt, rbtElemOne);
    rbt.printTree();

    //rbt.deleteNode(33);
    //rbt.printTree();
    return 0;
}