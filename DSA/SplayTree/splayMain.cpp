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

int main() {
    SplayTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);

    cout << "Inorder traversal after inserts: ";
    tree.display();

    tree.search(30);
    cout << "Inorder traversal after searching 30: ";
    tree.display();

    tree.remove(30);
    cout << "Inorder traversal after deleting 30: ";
    tree.display();

    return 0;
}
