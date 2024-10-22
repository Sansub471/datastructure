#pragma once
#include"../Linked_list/linked_list.hpp"
typedef LinkedList::Node ListNode;

// merge two sorted lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(!list1 && !list2) return nullptr;
    ListNode* dummy = new ListNode(); // keep track of result head
    ListNode* result = dummy; 
    while(list1 && list2){
        if(list1->val <= list2->val){
            result->next = list1;
            list1 = list1->next;
        }else{
            result->next = list2;
            list2 = list2->next;
        }
        result = result->next;
    }
    ListNode* emptyChk = list1 ? list1 : list2;
    result->next = emptyChk ? emptyChk : nullptr;
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;        
}
