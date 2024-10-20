#ifndef AVL_TREE
#define AVL_TREE

#ifndef AVL_TREE_NODE
#define AVL_TREE_NODE

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int key){
            data = key; 
            left = nullptr;
            right = nullptr;
            height = 1;
        }
};
#endif

//For traversal function


// To create a new node
Node* newNode(int data);

// calculate height
int height(Node* node);

int max(int a, int b);
Node* rightRotate(Node* Y);
Node* leftRotate(Node* X);

int getBalanceFactor(Node* node);

// Insert a node
Node* insertNode(Node* node, int key);

// Delete a node
Node* deleteNode(Node* node, int key);

// printTree
void printTree(Node* root, std::string indent="", bool last=true);

// tree creation function
Node* createAVLTree(std::vector<int>& avlElems, const std::string& task);
    // node deletion function
Node* removeAVLNode(Node* root, int key, const std::string& task);

// For using as library
void printAVLTree(Node* root);
// tree creation
Node* AVLTree(std::vector<int>& avlElems, const std::string& task);
Node* AVLremove(Node* root, int key, const std::string& task);
#endif
