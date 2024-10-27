// Chech if a linked list is palindrome
#pragma once
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

ListNode* reverseList(ListNode* head){
    ListNode* prevNode = nullptr, *currentNode = head, *nextNode = head;
    while(currentNode){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return prevNode;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* newHead = reverseList(slow->next);
    while(newHead){
        if(head->val != newHead->val)    return false;
        head = head->next;
        newHead = newHead->next;
    }
    return true;
}