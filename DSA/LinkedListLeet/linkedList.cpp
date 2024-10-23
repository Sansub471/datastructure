#include<iostream>
#include<vector>

// Link list implementation without a separate node class

class MyLinkedList {
private:
    int val;
    MyLinkedList* next;
public:
    MyLinkedList() :val(0), next(nullptr){}
    MyLinkedList(int x) : val(x), next(nullptr){}
    MyLinkedList(int x, MyLinkedList* node) : val(x), next(node){}
    
    // nodes are zero-indexed
    int get(int index) {
        if(index < 0) return -1;
        MyLinkedList* headptr = this->next;
        int i = 0;
        while(i <= index && headptr != nullptr){
            if(i == index) return headptr->val;
            headptr = headptr->next;
            i++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        MyLinkedList* newNode = new MyLinkedList(val);
        newNode->next = this->next;
        this->next = newNode;       
    }
    
    void addAtTail(int val) {
        MyLinkedList* newNode = new MyLinkedList(val);
        if(this->next == nullptr){
            this->next = newNode;
            return;
        }
        MyLinkedList* headptr = this->next;
        while(headptr->next != nullptr){
            headptr = headptr->next;
        }
        headptr->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0) return;
        MyLinkedList* dummy = new MyLinkedList(0, this->next); // dummy->next = head;
        int icount = 0;
        MyLinkedList* headptr = dummy;
        while(icount < index  && headptr->next != nullptr){
            headptr = headptr->next;
            icount++;
        }

        if(icount < index){
            this->next = dummy->next; // prevent memory leak
            delete dummy;
            return; // index > list.length
        }
        MyLinkedList* newNode = new MyLinkedList(val);
        newNode->next = headptr->next;
        headptr->next = newNode;
        // Adjust head
        this->next = dummy->next;
        delete dummy;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0) return;
        if(this->next == nullptr) return;
        MyLinkedList* dummy = new MyLinkedList(0, this->next); // dummy->next = head
        int icount = 0;
        MyLinkedList* headptr = dummy;
        while(icount < index && headptr->next != nullptr){
            headptr = headptr->next;
            icount++;
        }
        if(headptr->next == nullptr){
            this->next = dummy->next;
            delete dummy;
            return;
        }
        MyLinkedList* temp = headptr->next;
        headptr->next = headptr->next->next;
        delete temp;

        this->next = dummy->next;
        delete dummy;
        return;
    }

    // Method to display the list in a vector-style format
    void printList() {
        std::vector<int> result;
        MyLinkedList* headptr = this->next;
        while (headptr != nullptr) {
            result.push_back(headptr->val);
            headptr = headptr->next;
        }
        std::cout << "[";
        for (int i = 0; i < result.size(); i++) {
            std::cout << result[i];
            if (i < result.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    int param_1 = obj->get(1); // 2
    obj->deleteAtIndex(1);
    param_1 = obj->get(1); // 3
    return 0;
}

// Leet implementation
class Node{
public:
    int val;
    Node*next;
    Node(int x){
        this->val=x;
        this->next=nullptr;
    }
};
class MyLinkedList {
    private :
    Node*head;
    int size;
public:
    MyLinkedList() {
        this->head=nullptr;
        this->size=0;
        }
    
    int get(int index) {
        if(index<0 || index>=size) return -1;
        Node*temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node*newNode= new Node(val);
        newNode->next=head;
        head=newNode;
        size+=1;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0) {
            addAtHead(val);
            return;
        }
        if(index==size) {
            addAtTail(val);
            return;
        }
        if(index>size) return;
        Node*temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node*newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        size+=1;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        if(index==0) {
            head=head->next;
            size-=1;
            return;
        }
        Node*temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node*del=temp->next;
        temp->next=temp->next->next;
        size-=1;
        delete del;

    }
};