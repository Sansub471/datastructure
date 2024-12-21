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
    // ListNode* dummy = new ListNode(0, head);
    ListNode* headptr = head;
    
    std::queue<ListNode*> lesser;
    std::queue<ListNode*> greater;
    while(headptr->next != nullptr){
        if(headptr->val < x){
            lesser.push(headptr);
        }else{
            greater.push(headptr);
        }
        headptr = headptr->next;
    }
    if(!lesser.empty()) {
        headptr = lesser.front();
        lesser.pop();
    }else{
        headptr = greater.front();
        greater.pop();
    }
    ListNode* newhead = headptr;
    while(!lesser.empty()){
        headptr->next = lesser.front();
        headptr = headptr->next;
        lesser.pop();
    }
    while(!greater.empty()){
        headptr = greater.front();
        headptr = headptr->next;
        greater.pop();
    }
    headptr->next = nullptr;
    return newhead;        
}