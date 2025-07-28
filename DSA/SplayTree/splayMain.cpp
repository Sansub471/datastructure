#include"splay.hpp"

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
