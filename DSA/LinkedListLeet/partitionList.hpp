#pragma once
// Given the head of a linked list and a value x, partition it such that all nodes less than x come 
// before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]

#include<queue>
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

ListNode* partition(ListNode* head, int x) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* lesser_dummy = new ListNode(0, nullptr);
    ListNode* lesser_ptr = nullptr;

    ListNode* greaterEqual_dummy = new ListNode(0, nullptr);
    ListNode* greaterEqual_ptr = nullptr;

    ListNode* headptr = head;
    while(headptr->next != nullptr){
        if(headptr->val < x){
            if(lesser_dummy->next == nullptr){
                lesser_dummy->next = headptr;
                lesser_ptr = headptr;
                lesser_ptr->next = nullptr;
            }
            lesser_ptr->next = headptr;
            lesser_ptr = headptr;
            lesser_ptr->next = nullptr;
        }else{
            if(greaterEqual_dummy->next == nullptr){
                greaterEqual_dummy->next = headptr;
                greaterEqual_ptr = headptr;
                greaterEqual_ptr->next = nullptr;

            }
            greaterEqual_ptr->next = headptr;
            greaterEqual_ptr = headptr;
            greaterEqual_ptr->next = nullptr;
        }
        headptr = headptr->next;
    }

    // join the two lists
    lesser_ptr->next = greaterEqual_dummy->next;
    delete greaterEqual_dummy;
    
    ListNode* temp = lesser_dummy;
    lesser_dummy = lesser_dummy->next;
    delete temp;
    return lesser_dummy;
}