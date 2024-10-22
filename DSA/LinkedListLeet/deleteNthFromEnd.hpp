#pragma once
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

// Delete the nth node from last, given head and n
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr) return nullptr;
    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* first  = dummy;
    ListNode* second = dummy;

    // take first to n+1
    for(int i=0; i <= n; ++i) first = first->next; 
    while(first != nullptr){
        first = first->next;
        second = second->next;
    }
    // second is just before the node to be deleted
    // n+1 th place from last
    ListNode* temp = second->next;
    second->next = second->next->next;
    delete temp;

    // adjust head
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}
