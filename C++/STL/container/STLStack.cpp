#include<iostream>
#include<stack>

// use every stack methods to show its use
template <typename T>
    void PrintStack(std::stack<T> stk){
        std::cout<<"The size of stack = "<<stk.size()<<std::endl;
        std::cout<<"The top of stack is : " << stk.top() << std::endl;
        std::cout<<"Is the stack empty? : " << stk.empty() << std::endl;
        std::cout<<"The elements in the stack are : ";
        while(!stk.empty()){
            std::cout<<stk.top()<<"  ";
            stk.pop();
        }
    std::cout<<std::endl;
    }

int main(){
    // creation of stack
    std::stack<int> primes;
    std::stack<std::string> food;

    // Add element
    primes.push(13); primes.push(7); primes.push(11);
    primes.push(2); primes.push(5); primes.push(3);

    food.push("apple"); food.push("oranges"); food.push("egg");
    food.push("rice"); food.push("pudding"); food.push("broccoli");

    // Stack Methods
    // 1. push() : adds an element into the stack
    // 2. pop() : removes an element from the stack
    // 3. top() : returns an element on top of the stack
    // 4. size() : returns the no. of element in the stack
    // 5. empty() : returns true if the stack is empty

    std::cout<<"-----------The primes stack :------\n";
    PrintStack(primes);

    std::cout<<"\n----------------The food stack : -----------\n";
    PrintStack(food);
    return 0;
}

// DSA and Telecommunicatino lesson