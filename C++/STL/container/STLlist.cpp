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

// comparator which compares elements internally, merge fn
template <typename T>
    bool comparator(const T& first, const T& second){
        return first < second;
    }

// bool comparator(int first, int second){
//     return first < second;
// }
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
    
    // merge without comparator
    std::list<int> list1 {20, 10, 30, 20};
    std::list<int> list2 {50, 40, 60, 40};

    //list1.sort(); list2.sort();
    
    list1.merge(list2);
    std::cout<<"\nThe list1 is \n";
    PrintList(list1);

    std::cout<<"\nThe list2 is \n";
    PrintList(list2);

    // Time complexity: O(n + m - 1)
    // n : size of list1, m : size of list2

    // with comparator
    // list1_name.merge(list2_name, comparator)
    
    std::list<int> lst1 {1, 89, 23, 90};
    std::list<int> lst2 {10, 11, 7, 3, 2};

    // sort lists first to get final list sorted
    lst1.sort(comparator<int>);
    lst2.sort(comparator<int>);

    // merge operation
    lst1.merge(lst2, comparator<int>);
    std::cout<<"\nMerged with comparator function \n";
    PrintList(lst1);

    // Use of iterator
    std::list<int>::iterator itr;
    itr = lst1.begin();
    ++itr;

    std::cout<<"The second element is " << *itr << std::endl;

    // Add element at a specific position
    // list_name.insert(iterator, value);
    lst1.insert(itr, 77);
    PrintList(lst1);

    // Remove element from a specific position
    // list_name.remove(element)

    // Remove() using value
    lst1.push_back(90);
    lst1.push_back(90);

    std::cout<<"\nBefore removing by value\n";
    PrintList(lst1);

    std::cout<<"\nAfter removing by value\n";
    lst1.remove(90);
    PrintList(lst1);
    // All 90 will be removed

    // Remove() using iterator
    std::list<int>::iterator iter;
    iter = lst1.begin();
    lst1.push_back(77);
    lst1.push_back(77);
    std::cout<<"\nBefore removing by iterator\n";
    PrintList(lst1);

    ++iter; // index 1 element
    lst1.remove(*iter);
    // Removes all the values pointed by the iterator
    std::cout<<"\nAfter removing by iterator\n";
    PrintList(lst1);

    // by value and dereferencing *itr seems same to me



    return 0;
}