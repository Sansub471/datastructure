#include<iostream>
#include<deque>

template<typename T>
    void PrintDeque(std::deque<T>& dq){
        for(const auto& elem: dq){
            std::cout<<elem<<"  ";
        }
    std::cout<<std::endl;
    }

int main(){
    // Syntax : std::deque<type> dq;

    // 1. initializer list
    std::deque<int> dqnumbers ={8,9,5,4,3,2,1,9,10};
    std::deque<std::string> dqwords {"queue", "meow", "few", "sew", "dew", "hue"};

    std::cout<<"The numbers are :"; 
    PrintDeque(dqnumbers);

    std::cout<<"The words are   : "; 
    PrintDeque(dqwords);

    // Other ways to create dequeu
    // 1. Fill Constructor Method

    std::deque<int> deque1(5,12); // (size, val)
    std::cout<<"The filled deque is : ";
    PrintDeque(deque1);

    // 2. Range method initialization
    std::deque<int> dupnumbers(dqnumbers.begin() + 2, dqnumbers.end()-2);
    // end point is exclusive
    std::cout<<"The copied deque is : ";
    PrintDeque(dupnumbers);

    // Common methods of Deque
    // 1. push_back() : insert element at the back
    // 2. push_front() : insert element at the front
    // 3. pop_back() : removes element from the front
    // 4. pop_front() : removes element from the front
    // 5. front() : returns the elements at the front
    // 6. back() : returns the element at the back
    // 7. at() : sets/ returns the element at specified index
    // 8. size() : returns the number of elements
    // 9. empty() : returns true if the deque is empty

    // Can use [] operator to access element at the given index.
    // Not preferred as it doesn't throw out of bound error.

    // at() method can change element as well
    deque1.at(0) = 13;
    std::cout<<"The filled deque is : ";
    PrintDeque(deque1);
    

    return 0;
}