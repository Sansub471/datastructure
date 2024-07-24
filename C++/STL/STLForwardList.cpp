#include<iostream>
#include<forward_list>

template <typename T>
    void PrintForwardList(std::forward_list<T>& fwdList){
        std::cout<<"The elements of the forward list are : ";
        for(const T& elem : fwdList){
            std::cout<<elem<<"\t";
        }
    std::cout<<std::endl;
    }

int main(){
    // create an integer forward list
    std::forward_list<int> int_fwd_list {1,2,3,4,5,6,7,8,9};

    std::forward_list<std::string> forward_words = {"mine", "shine", 
                                                    "fine", "dine", "nine"};

    std::cout<<"The words are \n";
    PrintForwardList(forward_words);

    // Forward list methods
    // 1. front() : access the front element
    // 2. push_front() : add an element to the start of the list
    // 3. insert_after() : insert an element at the position right after the given position
    // 4. assign() : assign new contents to the list by replacing the current contents
    // 5. pop_front() : remove the element at the front
    // 6. remove() : remove the element with specific value
    // 7. clear() : delete all the contencts of the list

    


    return 0;

}