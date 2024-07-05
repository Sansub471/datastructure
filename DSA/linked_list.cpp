#include <iostream>

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Display the elements of the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList myList;

    // Insert elements into the list
    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    // Display the list
    myList.display();

    return 0;
}