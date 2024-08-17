#include<iostream>
#include<forward_list>

template <typename T>
    void PrintForwardList(std::forward_list<T>& fwdList){
        std::cout<<"The elements of the forward list are : ";
        for(const T& elem : fwdList){
            std::cout<<elem<<"  ";
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

    // access the first element
    std::string first  = forward_words.front();
    std::cout<<"The first word is " << first << std::endl;

    // add elements to the forward list
    int_fwd_list.push_front(77);
    auto itr = int_fwd_list.begin(); // or std::forward_list<int>::iterator itr;
    ++itr; ++itr;

    int_fwd_list.insert_after(itr, 17);
    std::cout<<"The list after insertion operations \n";
    PrintForwardList(int_fwd_list);

    // update the content of the forward list
    // assign() fn replaces the original contents of the forward list with new ones.

    std::forward_list<int> firstLst {1,2,3,4,5};
    std::cout<<"The list before assign function : \n";
    PrintForwardList(firstLst);

    firstLst.assign({7,9,8,7,9,6,5,9}); // can have more than 5 elements
    std::cout<<"The list after assign function : \n";
    PrintForwardList(firstLst);

    // delete elements from forward list
    firstLst.pop_front();
    firstLst.remove(9); // remove all occurence of 9

    // firstLst.clear(); // deletes all the elements from the list
    std::cout<<"The list after deletion operations \n";
    PrintForwardList(firstLst);
    return 0;
}

// Exam is just few days away.