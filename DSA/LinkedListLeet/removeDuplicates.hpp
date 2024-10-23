#pragma once
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

// Problem I : Given head of sorted linked list, remove duplicates
ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        if(slow->val == fast->val){
            ListNode* temp = fast;
            slow->next = fast->next;
            fast = fast->next;
            delete temp;
        }else{
            slow = slow->next;
            fast = fast->next;
        }
    }
    // duplicate at the end
    if(fast != nullptr && slow->val == fast->val){
        slow->next = nullptr;
        delete fast;
    }
    return head;        
}

// Leet solution
ListNode* deleteDuplicatesLeet(ListNode* head) {
    ListNode* ptr=head;
    if(head==NULL)
        return NULL;

    while(ptr!=NULL){
        while(ptr->next!=NULL && ptr->val==ptr->next->val){
            ptr->next=ptr->next->next;
        }
        ptr=ptr->next;
    }

    return head;
}

// Problem II : Given head of sorted linked list, remove all nodes that 
// have duplicates. Delete all occurences of a duplicate node
ListNode* deleteDuplicatesAll(ListNode* head) {
    if(head == nullptr) return nullptr;
    ListNode* dummy = new ListNode(0, head); // dummy->next = head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    int lastDeleted = INT32_MAX;
    ListNode* prevSlow = dummy; // if remains null, slow is still head
    while(fast != nullptr){
        if(slow->val == fast->val){
            ListNode* temp = fast;
            slow->next = fast->next;
            fast = fast->next;
            lastDeleted = temp->val;
            delete temp;
        }else{
            if(slow->val == lastDeleted){
                ListNode* temp = slow;
                prevSlow->next = slow->next;
                slow = slow->next;
                fast = fast->next;
                delete temp;
            }else{
                prevSlow = slow;
                slow = slow->next;
                fast = fast->next;
            }
        }
    }
    // previous node never moves or slow never moves(dependent)
    if(slow->val == lastDeleted){
        ListNode* temp = slow;
        prevSlow->next = slow->next; // nullptr
        slow = slow->next; // fast is already null
        delete temp;
    }
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;       
}

// Leet solution
ListNode* deleteDuplicatesAllLeet(ListNode* head) {
    if(!head) return nullptr;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* temp = dummy;


    while(temp != nullptr && temp->next !=nullptr)
    {   ListNode *nextNode = temp->next;
        if(nextNode->next!= nullptr && nextNode->val == nextNode->next->val)
        {
            while(nextNode->next!= nullptr && nextNode->val == nextNode->next->val)
            {
                nextNode =nextNode->next;
            }
            temp->next = nextNode->next;
        }
        else{
            temp = temp->next;
        }

    }
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}