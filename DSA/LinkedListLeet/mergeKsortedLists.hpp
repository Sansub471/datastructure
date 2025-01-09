#pragma once
// Hard : 23. Merge k Sorted Lists
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

#include<vector>
#include"../Linked_list/linked_list.hpp"
#include<queue>

typedef LinkedList::Node ListNode;

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;

    // Custom comparator for the priority queue (min-heap)
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
    };

    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> minHeap(cmp);

    // Add the head of each list to the heap
    for (auto list : lists) {
        if (list) minHeap.push(list);
    }

    // Dummy node to start the merged list
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (!minHeap.empty()) {
        // Get the smallest node from the heap
        ListNode* smallest = minHeap.top();
        minHeap.pop();

        // Add it to the merged list
        tail->next = smallest;
        tail = tail->next;

        // If the smallest node has a next node, push it into the heap
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }
    return dummy->next;
}

// Code Analysis :
// The problem requires merging k sorted lists by repeatedly taking the smallest node. A min-heap helps efficiently 
// track the smallest node in O(logk) time, making the solution optimal

// Time Complexity: O(Nlogk), where N is the total number of nodes across all lists, and 
//                 k is the number of lists. 
// Space Complexity: O(k) for the priority queue.