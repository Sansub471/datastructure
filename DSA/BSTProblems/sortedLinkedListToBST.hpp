#pragma once

#include<vector>
#include<algorithm>

#include"../Linked_list/linked_list.hpp"
#include"../localLib/randomIntElems.hpp"

// Create a sorted linked list with integers
// int lower : lower limit
// int upper : upper limit
// int size : optional : if not given, max_size > (upper - lower + 1) / 2
LinkedList::Node* sortedLinkedList(int lower, int upper, int max_size = -1){
    RandomIntElements randElems = RandomIntElements(lower, upper, max_size);
    std::vector<int> linkedNums = randElems.getRandomNumbers();
    std::sort(linkedNums.begin(), linkedNums.end(), std::greater<int>());
    LinkedList::Node* head = nullptr;
    for(const auto& elem : linkedNums){
        head = LinkedList::Insert(head, elem);
    }
    return head;
}

// How to sort a given linked list?

template<typename T>
    T* createTree(LinkedList::Node* head, int start, int end){
        if(head == nullptr) return nullptr;
        if(start > end) return nullptr;
        int mid = start + (end - start) / 2;
        int count = 0;
        LinkedList::Node* temp = head;
        while(count != mid){
            temp = temp->next;
            count++;
        }
        T* node = new T(temp->data);
        node->left = createTree<T>(head, start, mid - 1);
        node->right = createTree<T>(head, mid + 1, end);
        return node;
    }

template<typename T>
    T* sortedListToBST(LinkedList::Node* head) {
        if(head == nullptr) return nullptr;
        LinkedList::Node* node = head;
        int size = 0; // zero indexed linked list
        while(node->next != nullptr){
            node = node->next;
            size++;
        }
        return createTree<T>(head, 0, size);
    }
// Time complexity : O(Nlog(N))

// Leetcode solution
template<typename T>
    T* sortedListToBSTLeet(LinkedList::Node* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return new T(head->data);
        
        LinkedList::Node* prev_slow = nullptr;
        LinkedList::Node* slow = head;
        LinkedList::Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        T* root = new T(slow->data);
        prev_slow->next = nullptr;
        root->left = sortedListToBST<T>(head);
        root->right = sortedListToBST<T>(slow->next);

        return root;
    }