#include<iostream>
#include<vector>
#include<algorithm>

// Syntax : std::vector<T> vector_name;
// The type parameter <T> specifies the type of the vector.
// The size is not required, it can grow dynamically during execution.

void PrintVector(std::vector<int>& vec){
    std::cout<<"The elements are : ";
    for(const int& i : vec){
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
}


template<typename T>
    void PrintingVector(std::vector<T>& vec){
        std::cout<<"The elements from printing functions : ";
        for(const T& elem : vec){
            std::cout<<elem<<"\t";
        }
    std::cout<<std::endl;
    }
int main(){
    // Initialization Method I
    // 1. Initializer list
    std::vector<int> vec1 = {1,2,3,4,5};

    // 2. Uniform initilization
    std::vector<int> vec2 {13,17,77, 27, 37};

    // Initialization Method II
    std::vector<int> vec3(5,12);// 5 is size and 12 is the value
    // equivalent to : std::vector<int> vec3 = {12,12,12,12,12}

    std::vector<double> vec4 {12.34, 56.34, 76.23, 89.23, 99.23, 34.12};

    // cosnt reference ranged loop
    std::cout<<"The vector2 elements : ";
    for(const int& num : vec2){
        std::cout<< num << "\t";
    }
    std::cout<<std::endl;

    // 'const num&' : is a constant reference to each element of the vector
    // it avoids copying element to 'num'
    // 'const' ensures elements are not modified in the loop
    // efficient for large complex values

    // normal ranged loop
    std::cout<<"The vector3 elements : ";
    for(int i : vec3){
        std::cout<<i<<"\t";
    }
    std::cout<<std::endl;
    // Less efficient for large complex values.
    // copies the elements of vec3 to 'int i'


    // Basic operations
    // 1. Add elements : insert an element into the end of the vector
    vec2.push_back(99);
    vec2.push_back(37);

    // We can use insert() and emplace() functions to add elements to vector
    // vector_name.insert(position, val);
    // position : specifies the iterator which points to the position
    vec2.insert(vec2.begin()+2, 90);
    vec2.insert(vec2.end(), 78);

    PrintVector(vec2);
    std::cout<<std::endl;


    // insert multiple elments : vector_name.insert(position, size, val)
    // position : iterator where the insertion is to be done
    // size : no. of times 'val' is to be inserted at the position
    // val : value to be inserted

    vec2.insert(vec2.begin(), 2, 13);

    // insert range of elements at given index
    // vector_name.insert(position, iter1, iter2)
    // position : the position at which insertion to be done in vector
    // iterator 1 : the starting position from which the elements are to be inserted
    // iterator 2 : the ending position till which elements are to be inserted

    std::vector<int> original {1,2,3,4,5};
    std::vector<int> temp {5,9,0,3,10,12};

    original.insert(original.begin()+1, temp.begin()+2, temp.end());
    std::cout<<"The original vector : "<<std::endl;
    PrintVector(original);
    std::cout<<std::endl;



    PrintingVector(vec4);

    // 2. Access elements : at() func and [] where only at() func thorws
    // out of bound error while [] doesn't
    int num = vec2.at(0);
    std::cout<<"The element at index 0 : " << num << std::endl;
    std::cout<<"The element at index 2 : " << vec2.at(2) << std::endl;

    std::cout<<"The element at index 3 : " << vec2[3] << std::endl;

    // 3. Change Vector Element : 
    vec2.at(0) = 31;
    vec2.at(3) = 53;

    PrintingVector(vec2);

    // 4. Delete Elements 
    vec2.pop_back(); // remove the last element

    // Other functions 
    // 5. size()  : returns the number of elements
    // 6. clear() : removes all the elements of the vector
    // 7. front() : returns the first element of the vector
    // 8. back()  : returns the last element of the vector
    // 9. empty() : returns 1(true) if empty is empty
    // 10. capacity() : checks the overall size of a vector

    std::cout<<"The size of vec4 is : " << vec4.capacity() << std::endl;
    std::cout<<"The size of double : " << sizeof(double) << std::endl;

    vec4.push_back(45.89);
    std::cout<<"The size of vec4 is : " << vec4.capacity() << std::endl;

    // 11. erase() : remove elements from a conatiner from the specified pos or range

    // erase syntax : 
    // vector_name.erase(position); delete from specific position
    // vector_name.erase(start_pos, end_pos); deletion in range
    // positions are in the form of iterator.

    std::vector<int> myvector = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int>::iterator itr1, itr2;
    itr1 = myvector.begin() + 2;
    itr2 = myvector.begin() + 4;

    std::cout<<"Element : " << *itr1 << "\t " << myvector[2]<< std::endl;

    std::cout<<std::endl<<"Original vector : ";
    PrintingVector(myvector);

    myvector.erase(itr1); // O(n)
    std::cout<<"Erase at a position : ";
    PrintingVector(myvector);

    myvector.erase(itr1, itr2);
    std::cout<<"Erase range : ";
    PrintingVector(myvector);

    // Removing an element based on its value
    std::vector<int> values = {1,2,3,4,5,3,2,1,3,3};
    // know the position using find() and delete it
    int valueToDelete = 3;
    auto it = std::find(values.begin(), values.end(), valueToDelete);
    // if found returns the iter to its position otherwise iter to the last position
    // T(n) = O(n)
    if(it != values.end()){
        values.erase(it);
    }

    // clear() removes all the elements reducing vector size to 0
    // erase() removes specific element or range of elements, and reducing size accordingly
    
    PrintingVector(vec4);
    
    return 0;
}
