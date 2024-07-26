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
    

    // Iterators
    // Syntax : std::deque<type>::iterator iterator_name;

    std::deque<int>::iterator iter_int;
    std::deque<std::string>::iterator iter_str;

    int i = 2;
    iter_int = dqnumbers.begin() + i; // element at ith index, generalized
    iter_str = dqwords.end() - 1; // end() points to the iterator one past the last element

    std::cout<<"The last word in the deque is : " << *iter_str << std::endl;
    std::cout<<"The number at index["<<i<<"] is : " << *iter_int << std::endl;
    
    // FAQs
    // 1. How to remove elements at the specified index?
    dqnumbers.erase(dqnumbers.begin()+i); // delete at index i

    // 2. How to remove elements in a certain index range?
    dqwords.erase(dqwords.begin()+1, dqwords.begin()+3);
    // end point is exclusive

    // 3. Remove all the elements
    // clear() method

    // How to determine size?
    // size() and empty() methos to check

    // Can we use auto to initialize a deque iterator?
    // Yes, it can be used to initialize a deque iterator but not without initialization.

    auto itr = dqwords.begin(); // ok
    // auto itr1;  is invalid

    return 0;
}