#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

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
    };
#endif
    typedef Node* NodePtr;
    class RedBlackTree{
        private:
            Node* root;
            Node* TNULL;
        
            void initializeNULLNode(Node* node, Node* parent);
            // preorder
            void preOrderHelper(Node* node);
            // inorder
            void inOrderHelper(Node* node);
            // post order
            void postOrderHelper(Node* node);

            // Search helper function
            Node* searchTreeHelper(Node* node, int key);
        
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
            

            

    };
#endif