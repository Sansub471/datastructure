#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

// use macro to represent color
#define RED true
#define BLACK false

// can use enumerator as well
enum COLOR {Black, Red};

#include<iostream>
#include<vector>

#ifndef RED_BLACK_NODE
#define RED_BLACK_NODE
// RED is true, BLACK is false
    class Node {
    public:
        int data;
        Node* parent;
        Node* left;
        Node* right;
        bool color;
        //COLOR colour;
    };
#endif
    typedef Node* RBNodePtr;
    class RedBlackTree{
        private:
            Node* root;
            Node* TNULL;
        
            void initializeNULLNode(Node* node, Node* parent);
            Node* newNode(int key);
            // preorder
            void preOrderHelper(Node* node);
            // inorder
            void inOrderHelper(Node* node);
            // post order
            void postOrderHelper(Node* node);

            // Search helper function
            Node* searchTreeHelper(Node* node, int key);

            // For balancing tree after deletion
            void deleteFix(Node* x);
            void rbTransplant(Node* v, Node* u);
            void deleteNodeHelper(Node* node, int key);

            // For balancing tree after insertion
            void insertFix(Node* node);

            void printHelper(Node* root, std::string indent, bool last);
        public:
            RedBlackTree(); // constructor
            void preOrder(){
                preOrderHelper(this->root);
                }

            void inOrder(){
                inOrderHelper(this->root);
                }

            void postOrder(){
                postOrderHelper(this->root);
                }

            Node* searchTree(int key){
                return searchTreeHelper(this->root, key);
            }

            Node* minimun(Node* node);
            Node* maximum(Node* node);
            Node* successor(Node* node);
            Node* predecessor(Node* node);

            void leftRotate(Node* X);
            void rightRotate(Node* Y);

            // Inserting a node
            void insertNode(int key);

            RBNodePtr getRoot();

            // Delete a node
            void deleteNode(int data);

            // Search the tree
            bool search(int data);

            void printTree();
    };

// create R-B Tree from given list of elements
RedBlackTree* getRBTree(std::vector<int>& rbElems);
void getrbTree(RedBlackTree* rbt, std::vector<int>& rbElems);
#endif