// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

# pragma once
#include<stack>
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

ListNode* reorderList(ListNode* head) {
    ListNode* headptr = head;
    ListNode* slow = head;
    ListNode* fast = head;

    // traverse upto middle of the list
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    // reordered list will terminate at the middle
    ListNode* midNode = slow;
    slow = slow->next;
    midNode->next = nullptr;

    // kep the lower half of nodes in stack
    std::stack<ListNode*> revhalf;
    while(slow != nullptr){
        revhalf.push(slow);
        slow = slow->next;
    }

    // reorder the list
    while(headptr->next != nullptr && !revhalf.empty()){
        ListNode* temp = revhalf.top();
        revhalf.pop();
        temp->next = headptr->next;
        headptr->next = temp;
        headptr = headptr->next->next;
    }
    // headptr reaches to null first if number of nodes is even
    // stack gets emptied if the numner of nodes is odd

    // number of nodes even, one node left in stack
    if(!revhalf.empty()){
        ListNode* temp = revhalf.top();
        temp->next = nullptr;
        headptr->next = temp;
        headptr = headptr->next; // temp
        revhalf.pop();
    }
    return head;
}

