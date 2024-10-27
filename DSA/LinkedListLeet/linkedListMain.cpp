// All linked list related problems will be run from here.
#include<vector>

#include"getLinkList.hpp"
#include"addTwoNumbers.hpp"
#include"palindromeList.hpp"
#include"../LeetProblems/sumWithoutOperator.hpp"

#include"mergeTwoLists.hpp"
#include"reorderList.hpp"
#include"deleteMiddleNode.hpp"

int main(){
    // change the values to meet your requirement
    std::vector<int> l1 = {1,2,3,4,3,2,1};
    std::vector<int> l2 = {5};

    ListNode* linked1 = getLinkedList(l1);
    ListNode* linked2 = getLinkedList(l2);

    std::cout<<"The first linked list is : "; 
    LinkedList::PrintList(linked1);
    std::cout<<"The second linked list is : ";
    LinkedList::PrintList(linked2);

    // add two numbers
    ListNode* result = addTwoNumbers(linked1, linked2);
    std::cout<<"The sum of linked lists is : ";
    LinkedList::PrintList(result);

    // mergeTwosortedLists, ascending
    result = mergeTwoLists(linked1, linked2);
    std::cout<<"The merged list is : ";
    LinkedList::PrintList(result);

    // palindrome list
    std::vector<int> palList {1,2,3,4,3,2,1};
    ListNode* palLinked = getLinkedList(palList);
    std::cout<<"Palindrome linked list : ";
    LinkedList::PrintList(palLinked);
    bool palindrome = isPalindrome(palLinked);
    std::cout<<"Palindrome ? " << palindrome <<std::endl;

    // reorder linked list
    std::vector<int> reorder = {1,2,3,4};
    ListNode* reorderlist = getLinkedList(reorder);
    reorderList(reorderlist);

    // delete middle
    std::vector<int> delMid = {2,1};
    ListNode* delMidhead = getLinkedList(delMid);
    std::cout<<"Before deleting middle element : "; 
    LinkedList::PrintList(delMidhead);
    delMidhead = deleteMiddle(delMidhead);
    std::cout<<"After deleting middle element: ";
    LinkedList::PrintList(delMidhead);

    return 0;
}