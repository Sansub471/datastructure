#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class SplayTree {
private:
    // Right rotate
    Node* rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    // Left rotate
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    // Splay operation
    Node* splay(Node* root, int key) {
        if (!root || root->key == key) return root;

        // Key lies in the left subtree
        if (key < root->key) {
            if (!root->left) return root;

            // Zig-Zig (Left Left)
            if (key < root->left->key) {
                root->left->left = splay(root->left->left, key);
                root = rightRotate(root);
            } 
            // Zig-Zag (Left Right)
            else if (key > root->left->key) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right) root->left = leftRotate(root->left);
            }

            return root->left ? rightRotate(root) : root;
        } 
        // Key lies in the right subtree
        else {
            if (!root->right) return root;

            // Zag-Zig (Right Left)
            if (key < root->right->key) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left) root->right = rightRotate(root->right);
            } 
            // Zag-Zag (Right Right)
            else if (key > root->right->key) {
                root->right->right = splay(root->right->right, key);
                root = leftRotate(root);
            }

            return root->right ? leftRotate(root) : root;
        }
    }

public:
    Node* root;

    SplayTree() : root(nullptr) {}

    // Search operation
    Node* search(int key) {
        root = splay(root, key);
        return (root && root->key == key) ? root : nullptr;
    }

    // Insert operation
    void insert(int key) {
        if (!root) {
            root = new Node(key);
            return;
        }

        root = splay(root, key);

        if (root->key == key) return; // Key already exists

        Node* newNode = new Node(key);
        if (key < root->key) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }

        root = newNode;
    }

    // Delete operation
    void remove(int key) {
        if (!root) return;

        root = splay(root, key);

        if (root->key != key) return; // Key not found

        if (!root->left) {
            root = root->right;
        } else {
            Node* temp = root;
            root = splay(root->left, key);
            root->right = temp->right;
        }
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};