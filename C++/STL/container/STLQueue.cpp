#include<iostream>
#include<queue>

// Not passed by reference because the element should be popped
template<typename T>
    void PrintQueue(std::queue<T> Q){
        while(!Q.empty()){
            std::cout<<Q.front()<<"  ";
            Q.pop();
        }
    std::cout<<std::endl;
    }

int main(){
    // Syntax : std::queue<type> var_name;
    std::queue<int> numbers;
    std::queue<std::string> words;

    // Methods 
    // 1. push() : insert an element at the back
    // 2. pop() : remove an element from the front
    // 3. front() : return the first element of the queue
    // 4. back() : return the last element of the queue
    // 5. size() : returns the no. of elements in the queue
    // 6. empty() : returns true if the queue is empty.

    // Add element 
    words.push("name");
    words.push("fame");
    words.push("shame");
    words.push("game");
    words.push("tame");

    std::cout<<"The words in the queue are : ";
    PrintQueue(words);

    numbers.push(13);
    numbers.push(7);
    numbers.push(3);
    numbers.push(2);
    numbers.push(11);
    std::cout<<"\nThe prime numbers in the queue are : ";
    PrintQueue(numbers);

    // Remove element from the queue.
    words.pop(); numbers.pop(); // pop fron the front of the queue
    std::cout<<"\nThe words in the queue are : ";
    PrintQueue(words);

    std::cout<<"\nThe prime numbers in the queue are : ";
    PrintQueue(numbers);

    // Access the elements using front() and back()
    std::cout<<"The front of words queue  : " << words.front() << std::endl;
    std::cout<<"The back of numbers queue : "<< numbers.back() << std::endl;

    // size() of the queue
    std::cout<<"The size of words queue = " << words.size() << std::endl;

    // check if empty()
    

    return 0;
}
// Back on my programming days. 