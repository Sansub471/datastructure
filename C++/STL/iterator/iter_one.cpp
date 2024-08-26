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

    return 0;
}
