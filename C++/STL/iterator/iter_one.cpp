#include<iostream>
#include<vector>
#include<iterator>

// operators supported by iterators
// Iterator Type	Supported Operators
// Input Iterator	++, *, ->, ==, !=
// Output Iterator	++, *, =
// Forward Iterator	++, *, ->, ==, !=
// Bidirectional Iterator	++, --, *, ->, ==, !=
// Random Access Iterator	++, --, *, ->, [], +, -, <, <=, >, >=, ==, !=

// Iterator Type	            Data type
// Input Iterator	            eg. input stream
// Output Iterator	            eg. output stream
// Forward Iterator	            eg. forward_list
// Bidirectional Iterator	    eg. list, set, multiset, map, and multimap
// Random Access Iterator	    eg. vector, deque, array

int main(){
    // constant iterator example
    std::vector<int> numbers {1,2,3,4,5,7};
    std::vector<int>::const_iterator itervec = numbers.cbegin();
    // cbegin() returns a constant iterator while begin() returns a normal iterator

    //*itervec += 77; not allowed as itervec is read only, const no modification

    std::cout<<"The value of the constant iterator is : " << *itervec << std::endl;
    itervec++;
    std::cout<<"The value of the constant iterator++ is : " << *itervec << std::endl;
    
    //*itervec += 34;

    numbers[0] = 34;
    //numbers.insert(itervec, 77);  it would create problem because the vector would be resized and iterator be invalid

    itervec = numbers.insert(itervec, 77);
    std::cout<<"The elements of the vector are : "<<std::endl;
    for(auto elem : numbers){
        std::cout<< elem << "\t";
    }
    std::cout<<std::endl;

    itervec++;
    std::cout<<"The value of the constant --iterator is : " << *itervec << std::endl;

    std::vector<int>::reverse_iterator riter = numbers.rbegin(); // last element; end() - 1 element
    // but not same as end() - 1 iterator
    // reverse iterator and normal iterator are not compatible
    std::vector<int>::iterator niter = numbers.end() - 1; // normal iterator
    std::cout<<"The rbegin is : " << *riter  << std::endl;
    std::cout<<"The end() -1 is : " << *niter << std::endl;

    std::vector<int>::iterator iter1 = numbers.begin();
    std::vector<int>::reverse_iterator riter2 = numbers.rend(); // theoretical element just before the first element
    std::advance(iter1, 5);
    std::advance(iter1, -3); // expect 2
    std::cout<<"The value of iter1 is : " << *iter1 << std::endl;

    iter1 = std::prev(iter1, 2);
    iter1 = std::next(iter1, 4); // expect 4
    std::cout<<"The value of iter1 is : " << *iter1 << std::endl;

    iter1 = std::prev(iter1, -2); // expect 7; actually goes forward: current -(-7)
    std::cout<<"The value of iter1 is : " << *iter1 << std::endl;

    iter1 = std::next(iter1, -3); // expect 3; actually goes backward: current + (-3)
    std::cout<<"The value of the iter1 is : " << *iter1 << std::endl;
    return 0;
}
