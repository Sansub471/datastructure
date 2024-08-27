#include<iostream>
#include<algorithm>
#include<vector>

// using vector to demonstrate, it works on other containers too

template <typename T>
    void PrintVector(std::vector<T>& myvec){
        std::cout<<"The elements are : ";
        for(const T& elem : myvec){
            std::cout<<elem<<"\t";
        }
        std::cout<<std::endl;
    }


int main(){
    std::vector<int> numbers {2, 8, 1, 2, 9, 20, 12, 90, 34, 88, 13, 77, 17};

    std::cout<<"The size of vector is : "<< sizeof(numbers) << std::endl;
    // The size of will give us the size of vector object, not the size of its elements
    // The vector object's implementation has three pointers, each of size 8 byte hence 24 is returned
    // The details is not necessary right now.
    // Use vec.size() function to get the number of elements


    int size = numbers.size();
    std::vector<int> cpnum(size);

    // copy
    std::copy(numbers.begin(), numbers.end(), cpnum.begin());
    // copy(start, end, destination)
    // sart and end are from source vector; 'start' is inclusive while 'end' is exclusive
    // destination is the location in the destination vector
    // it may always not be begin() and end() be  creative

    std::cout<<"The number of elements is : " << size << std::endl;

    // sorting ascending
    std::cout<<"Before sorting, ";
    PrintVector(numbers);

    std::sort(numbers.begin(), numbers.end());
    // sort(start, end)
    // start : starting point of sorting
    // end   : ending point of sorting elements (exclusive)

    std::cout<<"After sorting, ";
    PrintVector(numbers);

    std::cout<<"The copied vector cpnum, ";
    PrintVector(cpnum);

    // descending sorting
    std::sort(cpnum.begin(), cpnum.end(), std::greater<int>()); // T = O(N log N), S = O(1)
    //std::sort(cpnum.rbegin(), cpnum.rend()); // T and S are same
    
    std::cout<<"After descending sort cpnum, ";
    PrintVector(cpnum);
    return 0;
}