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
