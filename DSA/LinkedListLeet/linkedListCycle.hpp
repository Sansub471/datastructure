#pragma once

#include<vector>
#include"../Linked_list/linked_list.hpp"
#include<unordered_map>

typedef LinkedList::Node ListNode;

bool hasCycleMine(ListNode *head) {
    if(head == nullptr) return false;
    std::unordered_map<ListNode*, int> ListMap;
    int MAX = 10000;
    int count = 0;
    ListNode* headptr = head;
    while(headptr != nullptr){
        if(!ListMap.empty()){
            if(ListMap.find(headptr) != ListMap.end()){
                int pos = ListMap[headptr];
                return true;
            }
        }
        ListMap[headptr] = count++;
        headptr = headptr->next;

        if(count > MAX) return false;
    }
    return false;
}

// leet code solution
bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;   
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }  
    return false; 
}
// This approach is called : Floyd’s Cycle Detection Algorithm, also known as the Tortoise and Hare Algorithm, 
// is a two-pointer technique to detect a cycle in a linked list. It works in two steps:

// Step 1: Detect if a cycle exists

// Use two pointers:
//     Slow Pointer (Tortoise): Moves one step at a time.
//     Fast Pointer (Hare): Moves two steps at a time.
//     If the linked list has a cycle, the slow and fast pointers will eventually meet within the cycle.
//     If the fast pointer reaches the end of the list (i.e., fast == nullptr or fast->next == nullptr), then the list has no cycle.

// Step 2: Find the starting node of the cycle

//     Once a cycle is detected (when slow and fast pointers meet), reset one pointer (e.g., slow) to the head of the list.
//     Move both pointers (slow and fast) one step at a time. The point where they meet again is the starting node of the cycle.
//     This works because the distance from the head to the cycle's start is equal to the distance from the meeting point back to 
//     the cycle's start.

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            // Cycle found, reset slow to head and move both pointers one step
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // or fast
        }
    }
    return nullptr;
}