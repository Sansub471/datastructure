#ifndef M_WAY_TREE_TPP
#define M_WAY_TREE_TPP

#include<algorithm>

// Constructor
template<typename Key, int M>
MWayTree<Key, M>::MWayTree() : root(new Node{}){}


// Search
template<typename Key, int M>
typename MWayTree<Key, M>::Node* MWayTree<Key, M>::search(Node* node, const Key& k){
    if(!node) return nullptr;
    int i = 0;
    while(i < node->count && k > node->keys[i]) i++;
    if(i < node->count && k == node->keys[i]) return node; // key already exists
    if(node->isLeaf) return nullptr;
    return search(node->children[i], k);
}

template<typename Key, int M>
bool MWayTree<Key, M>::contains(const Key& k){
    return search(root, k) != nullptr;
}

// Insert public
template<typename Key, int M>
void MWayTree<Key, M>::insert(const Key& k){
    if(contains(key)){
        std::cout<<"Duplicate key "<< key << " ignored"<<std::endl;
    }

    // if node is full
    if(root->count == M - 1){
        // Root is full; create new root
        Node* newRoot = new Node{};
        newRoot->isLeaf = false;
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        root = newRoot;
    }

    // node is not full, then insert
    insertNonFull(root, k);
}

// Insertion into non-full node
template<typename Key, int M>
void MWayTree<Key, M>::insertNonFull(Node* node, const Key& k){
    int i = node->count - 1;
    if(node->isLeaf){
        while(i >= 0 && node-> keys[i] > k){
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = k;
        node->count++;
    }else{
        while(i >= 0 && node->keys[i] > k) i--;
        i++;
        if(node->children[i]->count == M - 1){
            std::cerr<<"Child node is full - need split\n";
            return;
        }
        insertNonFull(node->children[i], k);
    }
}
#endif

// Let's test code today