#pragma once
#include<vector>
#include<queue>

// Findind the kth largest element in an array
// 1. Quickselect Algorithm (Best Choice)
// Quickselect is a variation of the Quicksort algorithm that works in 
// O(n) on average. Instead of sorting the entire array, it partially partitions the array such that the kth largest element is at its correct position.

// Steps:
// Partition the Array:

// Choose a pivot element and partition the array into two parts:
// Left: Elements greater than the pivot.
// Right: Elements smaller than the pivot.
// Check the Pivot's Position:

// If the pivot is at the 
// k-th position (from the end), you've found the kth largest element.
// If the pivot's position is greater than 
// k, recursively process the left partition.
// If the pivot's position is less than 
// k, recursively process the right partition.
// Repeat until the pivot lands in the desired position.

// 2. Min-Heap Approach
// This method involves using a heap to efficiently keep track of the kth largest element.

// Steps:
// Create a Min-Heap of size 
// k.
// Add the first 
// k elements of the array to the heap.
// For each remaining element:
// If the element is larger than the root of the heap (smallest element in the heap), replace the root with this element and re-heapify.
// The root of the heap will be the kth largest element.
// Time Complexity:
// Building the heap: O(k)
// Processing remaining elements: O((n - k)logk)
// Total: O(nlogk)