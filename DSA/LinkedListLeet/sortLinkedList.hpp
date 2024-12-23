#pragma once
#include"../Linked_list/linked_list.hpp"

typedef LinkedList::Node ListNode;

// Sorting a linked list with merge sort

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); // Dummy node for the merged list
    ListNode* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes (if any)
    tail->next = (l1 != nullptr) ? l1 : l2;

    return dummy.next;
}

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != nullptr) {
        prev->next = nullptr; // Split the list into two halves
    }

    return slow;
}

ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Base case: single node or empty list
    }

    // Split the list into two halves
    ListNode* mid = findMiddle(head);

    // Recursively sort each half
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    // Merge the sorted halves
    return mergeTwoLists(left, right);
}


// Time Complexity
// Finding the middle: O(n).
// Merging two lists: O(n).
// Since the list is divided into halves recursively, the depth of recursion is O(logn).
// Overall time complexity: O(nlogn).

// Space Complexity
// Merge process: O(1) (in-place merging).
// Recursion stack: O(logn) for O(logn) recursive calls