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
    ListNode* lesser_ptr = lesser_dummy;

    ListNode* greaterEqual_dummy = new ListNode(0, nullptr);
    ListNode* greaterEqual_ptr = greaterEqual_dummy;

    ListNode* headptr = head;
    while(headptr != nullptr){
        if(headptr->val < x){
            lesser_ptr->next = headptr;
            lesser_ptr = headptr;
        }else{
            greaterEqual_ptr->next = headptr;
            greaterEqual_ptr = headptr;
        }
        headptr = headptr->next;
    }

    greaterEqual_ptr->next = nullptr; // terminate the greater equal list

    // join the two lists
    lesser_ptr->next = greaterEqual_dummy->next;
    delete greaterEqual_dummy;
    
    ListNode* new_head = lesser_dummy->next;
    delete lesser_dummy;
    return new_head;
}