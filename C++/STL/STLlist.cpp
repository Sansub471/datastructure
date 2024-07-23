#include<iostream>
#include<list>

// list is implemented using doubly linked list
// can be accessed from both ends front and back
// Random access not allowed

template <typename T>
    void PrintList(std::list<T>& myList){
        std::cout<<"The elements are : ";
        for(const T& elem : myList){
            std::cout<<elem<<"\t";
        }
    std::cout<<std::endl;
    }

template <typename T>
    void PrintingList(std::list<T>& myList){
        std::cout<<"The elements are : ";
        for(auto it = myList.begin(); it != myList.end(); ++it){
            std::cout<<*it<<"\t";
        }
    std::cout<<std::endl;
    }

// Binary predicate fn, float type can't be compared with = opeator
// hence int part is used 
bool compare(double a, double b){
        return ((int)a == (int)b);
    }
int main(){

    std::list<int> numbers = {1,2,3,4,5,6,7,8};
    std::list<float> marks {12.5, 23.5, 89.05, 34.12, 90.22, 89.2};

    std::cout<<"The lists created are : "<<std::endl;
    PrintList(numbers);
    PrintList(marks);

    // Basic list operations
    // 1. Add element
    numbers.push_front(13); // insert at the beginning
    marks.push_back(67.45); // insert at the back

    // 2. Access list elements
    int front = numbers.front(); // first element of the list
    float back = marks.back(); // the last element of the list

    // 3. Delete list elements
    numbers.pop_back(); // remove the last element
    marks.pop_front(); // remove the first element

    // Other list functions
    /*
    1. reverse() : reverse the order of the elements
    2. sort() : sorts the list elements in a particular order, O(nlog(n))
    3. unique() : removes consecutive duplicate elements on a sorted list, 
    // time complexity : O(nlog(n)) due to sorting
    4. empty() : checks whether the list is empty
    5. size() : returns the number of elements in the list
    6. clear() : clears all the values in the list
    7. l1.merge(l2) : merge two sorted list
    */
    std::cout<<"\nThe numbers"<<std::endl;
    PrintList(numbers);

    std::cout<<"\nReversing the numbers "<<std::endl;
    numbers.reverse();
    PrintList(numbers);

    std::list<std::string> words {"hi", "my", "bye", "shy", "tie", "pie"};
    std::cout<<"\nThe words are "<< std::endl;
    PrintList(words);

    std::cout<<"\nThe sorted words are "<<std::endl;
    words.sort();
    PrintList(words);

    // unique : works on sorted list only
    // list_name.unique(BinaryPredicate name) : parameter is optional
    // Binary predicate returns true if the elements should be treated as equal.
    // Syntax : bool name(data_type a, data_type b);

    std::list<double> listone = { 2.55, 3.15, 4.16, 4.16,
                          4.77, 12.65, 12.65, 13.59 };
    std::list<double> listtwo = { 2.55, 3.15, 4.16, 4.16,
                          4.77, 12.65, 12.65, 13.59 };
    
    listone.sort();
    listtwo.sort();

    listone.unique(); // without parameter
    listtwo.unique(compare); // with binary predicate

    std::cout<<"\nUnique without binary predicate.\n";
    PrintingList(listone);

    std::cout<<"\nUnique with binary predicate.\n";
    PrintingList(listtwo);
   

    return 0;
}