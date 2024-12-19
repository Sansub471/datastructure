#pragma once
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr) return head; // rotating single node k time or empty list
    ListNode* slow = nullptr;

    // count the no. of nodes and calculate effective rotation
    ListNode* headptr = head;
    int countNodes = 0;
    while(headptr->next != nullptr) {
        ++countNodes;
        headptr = headptr->next;
    }
    for(int i = 0; i < k; ++i){
        ListNode* fast = head;
        while(fast->next->next != nullptr) fast = fast->next;
        slow = fast->next;
        slow->next = head;
        head = slow;
        fast->next = nullptr;
    }
    return head;
}