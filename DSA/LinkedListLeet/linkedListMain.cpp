// All linked list related problems will be run from here.

#include"addTwoNumbers.hpp"

int main(){
    std::vector<int> l1 = {9,9,9,9,9,9,9};
    std::vector<int> l2 = {9,9,9,9};
    ListNode* linked1 = getLinkedList(l1);
    ListNode* linked2 = getLinkedList(l2);
    std::cout<<"The first linked list is : "; 
    LinkedList::PrintList(linked1);
    std::cout<<"The second linked list is : ";
    LinkedList::PrintList(linked2);

    ListNode* result = addTwoNumbers(linked1, linked2);
    std::cout<<"The sum of linked lists is : ";
    LinkedList::PrintList(result);

    return 0;
}