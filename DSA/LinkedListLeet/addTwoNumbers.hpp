#pragma once

#include<vector>
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

ListNode* getLinkedList(const std::vector<int>& elems){
    ListNode* head = nullptr;
    for(const auto& elem : elems){
        head = LinkedList::InsertAtEnd(head, elem);
    }
    return head;
}

   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr && l2 != nullptr) return l2;
        if(l2 == nullptr && l1 != nullptr) return l1;

        ListNode* tempL1 = l1->next; // optional
        ListNode* tempL2 = l2->next; // optional
        int sum = l1->data + l2->data; 
        int carry = sum / 10;
        ListNode* result = new ListNode(sum % 10); // track of head
        ListNode* temp = result; // track of tail

        while(tempL1 != nullptr && tempL2 != nullptr){
            sum = tempL1->data + tempL2->data + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
            temp = temp->next;
        }

        // One list is longer
        ListNode* tmp = tempL1 != nullptr ? tempL1 : tempL2;
        while(tmp != nullptr){
            sum = tmp->data + carry;
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            tmp = tmp->next;
            temp = temp->next;
        }

        if(carry > 0) temp->next = new ListNode(carry);
        return result;

    }