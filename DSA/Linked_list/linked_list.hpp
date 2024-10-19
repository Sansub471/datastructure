#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

namespace LinkedList {
    struct Node {
        int data; 
        Node* next;

        // Constructors
        Node() : data(0), next(nullptr) {}
        Node(int x) : data(x), next(nullptr) {}
        Node(int x, Node* nextNode) : data(x), next(nextNode) {}
    };

    Node* headpoint = nullptr;

    // Insert at the beginning
    Node* Insert(Node* head, int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        return head;
    }

    // Insert at a specific position
    Node* InsertPosition(Node* head, int data, int n) {
        Node* temp1 = new Node(data);
        if (n == 1) { 
            temp1->next = head;
            head = temp1;
            return head;
        }
        Node* temp2 = head;
        for(int i = 0; i < n - 2; ++i) {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
        return head;
    }

    // Insert at the end
    Node* InsertAtEnd(Node* head, int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            return head;
        }
        Node* temp1 = head;
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        return head;
    }

    // Delete a node at a given position
    Node* DeletePosition(Node* head, int n) {
        Node* temp = head;
        if (n == 1) {
            head = temp->next;
            delete temp;
            return head;
        }
        for (int i = 0; i < n - 2; ++i) {
            temp = temp->next;
        }
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        return head;
    }

    // Reverse the linked list iteratively
    Node* ReverseByIteration(Node* head) {
        Node* current = head;
        Node* prev = nullptr;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    // Print the list iteratively
    void PrintList(Node* head) {
        while (head != nullptr) {
            std::cout << head->data << " ";  
            head = head->next;
        }
        std::cout << std::endl;
    }

    // Reverse the list recursively
    void ReverseByRecursion(Node* p) {
        if (p->next == nullptr) {
            headpoint = p;
            return;
        }
        ReverseByRecursion(p->next);
        Node* q = p->next;
        q->next = p;
        p->next = nullptr;
    }

    // Print the list recursively
    void PrintRecursion(Node* head) {
        if (head == nullptr) {
            std::cout << std::endl;
            return;
        }
        std::cout << head->data << " ";  
        PrintRecursion(head->next);
    }

    // Reverse print the list recursively
    void ReversePrintRecursion(Node* head) {
        if (head == nullptr) return;
        ReversePrintRecursion(head->next);
        std::cout << head->data << " ";  
    }
}
#endif