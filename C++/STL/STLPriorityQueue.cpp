#include<iostream>
#include<queue>

template<typename T>
    void PrintPQueue(std::priority_queue<T> pq){
        while(!pq.empty()){
            std::cout<<pq.top()<<"  ";
            pq.pop();
        }
    std::cout<<std::endl;
    }

template<typename T>
    void PrintMinPrioQueue(std::priority_queue<T, std::vector<T>, std::greater<T>> pq){
        while(!pq.empty()){
            std::cout<<pq.top()<<"  ";
            pq.pop();
        }
    std::cout<<std::endl;
    }

int main(){

    // Syntax : std::priority_queue<type> pq;

    std::priority_queue<int> primes;
    std::priority_queue<std::string> words;

    // by default STL priority queue gives the largest element the highest
    // priority.

    // Methods : the basic methods to work with priority queue are
    // 1. push() : inserts the element into the priority queue
    // 2. pop() : removes the element with highes priority
    // 3. top() : returns the element with the highest priority
    // 4. size() : returns the number of elements
    // 5. empty() : true if the priority_queue is empty

    // Insert element into the priority queue.
    primes.push(13); primes.push(7); primes.push(11);
    primes.push(2); primes.push(5); primes.push(3);

    words.push("name"); words.push("fame"); words.push("tame");
    words.push("shame"); words.push("game"); words.push("dame");

    std::cout<<"The prime numbers are : ";
    PrintPQueue(primes);

    std::cout<<"\nThe words are : ";
    PrintPQueue(words);

    // Remove element using pop()
    // check the PrintQueue() function

    // Access element using top() method
    // empty() and size() functions are pretty straight forward.

    // Min-Heap Priority Queue
    // std::priority_queue<type, vector<type>, greater<type>> pq;
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> food;
    food.push("apple"); food.push("oranges"); food.push("egg");
    food.push("rice"); food.push("pudding"); food.push("broccoli");

    std::cout<<"The min-heap food is : ";
    PrintMinPrioQueue(food);


    return 0;
}