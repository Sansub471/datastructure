#include<iostream>

// Unbalanced m-way tree for now.
#include <iostream>
#include <vector>
using namespace std;

template <typename Key, int M>
struct MNode {
    int count = 0;                         // number of keys
    Key keys[M-1];                         // slots for keys
    MNode* children[M] = {nullptr};       // child pointers
    bool isLeaf = true;
};

template <typename Key, int M>
class MWayTree {
    using Node = MNode<Key, M>;
    Node* root = nullptr;

public:
    MWayTree() { root = new Node(); }

    Node* search(Node* node, const Key& k) {
        if (!node) return nullptr;
        int i = 0;
        while (i < node->count && k > node->keys[i]) i++;
        if (i < node->count && k == node->keys[i]) return node;
        if (node->isLeaf) return nullptr;
        return search(node->children[i], k);
    }

    void insert(const Key& k) {
        Node* node = root;
        // find leaf
        while (!node->isLeaf) {
            int i = 0;
            while (i < node->count && k > node->keys[i]) i++;
            node = node->children[i];
        }
        // insert if space
        if (node->count < M - 1) {
            int i = node->count - 1;
            while (i >= 0 && node->keys[i] > k) {
                node->keys[i+1] = node->keys[i];
                i--;
            }
            node->keys[i+1] = k;
            node->count++;
        } else {
            // for now, skip splitting: you can add child allocation logic here
            cout << "Node full — splitting not implemented\n";
        }
    }

    void insertAndShow(const Key& k) {
        insert(k);
        cout << "Inserted " << k << "\n";
    }

    bool contains(const Key& k) {
        return search(root, k) != nullptr;
    }
};

int main() {
    const int M = 4;
    MWayTree<int, M> T;
    int arr[] = {10, 20, 5, 15, 25, 12};
    for (int x : arr) T.insertAndShow(x);

    cout << "Search 15: " << (T.contains(15) ? "found" : "not found") << "\n";
    cout << "Search 100: " << (T.contains(100) ? "found" : "not found") << "\n";
    return 0;
}
