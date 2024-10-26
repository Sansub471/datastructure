#pragma once 
// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
// where ⌊x⌋ denotes the largest integer less than or equal to x.

// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;
ListNode* deleteMiddle(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prevSlow = nullptr; // for odd case
    
    // traverse to the middle node
    while(fast->next != nullptr && fast->next->next != nullptr){
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is just before the middle node, total nodes even
    // slow is at the middle node, total node odd

    // odd case, fast goes upto the last node
    // even case, fast goes upto the second last node
    ListNode* temp;
    // odd case, at least 3 nodes. Single node case handled at top
    if(fast->next == nullptr){
        temp = slow;
        prevSlow->next = temp->next; // slow->next
    }else{ // even case
        temp = slow->next;
        slow->next = temp->next; // slow->next->next
    }
    delete temp;
    return head;        
}