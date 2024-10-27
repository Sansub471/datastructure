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