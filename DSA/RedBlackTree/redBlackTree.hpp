#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#ifndef RED_BLACK_NODE
#define RED_BLACK_NODE
// RED if true, BLACK is false
    class Node {
    public:
        int data;
        Node* parent;
        Node* left;
        Node* right;
        bool color;
    };

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
    };
#endif



#endif