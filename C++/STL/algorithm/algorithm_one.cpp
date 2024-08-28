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
    std::cout<<"\nBefore sorting, ";
    PrintVector(numbers);

    std::sort(numbers.begin(), numbers.end());
    // sort(start, end)
    // start : starting point of sorting
    // end   : ending point of sorting elements (exclusive)

    std::cout<<"After sorting, ";
    PrintVector(numbers);

    std::cout<<"\nThe copied vector cpnum, ";
    PrintVector(cpnum);

    // descending sorting
    std::sort(cpnum.begin(), cpnum.end(), std::greater<int>()); // T = O(N log N), S = O(1)
    //std::sort(cpnum.rbegin(), cpnum.rend()); // T and S are same
    
    std::cout<<"After descending sort cpnum, ";
    PrintVector(cpnum);

    // move operation
    std::vector<std::string> source {"here", "there", "fear", "pear", "shear", "gear", "mere"};
    std::vector<std::string> destination(source.size());

    std::cout<<"\nThe source, "; PrintVector(source);
    std::cout<<"The destination, "; PrintVector(destination);

    std::move(source.begin(), source.end()-2, destination.begin());
    std::cout<<"After the move operation : \n";
    std::cout<<"The source, "; PrintVector(source);
    std::cout<<"The destination, "; PrintVector(destination);

    // syntax : move(first, last, destination)
    // last is exclusive

    // swap operation
    std::swap(source, destination);
    std::cout<<"\nThe swapping operation:\n";
    std::cout<<"The source, "; PrintVector(source);
    std::cout<<"The destination, "; PrintVector(destination);

    // merge operation
    // merge(first1, last1, first2,  last2, result);
    // Here,

    // first1, last1 - iterators specifying the first input range.
    // first2, last2 - iterators specifying the second input range.
    // result - iterator specifying the beginning of the destination range.
    std::vector<std::string> merged(source.size());
    std::vector<std::string>::iterator first1, last1, first2, last2, result;
    std::merge(source.begin(), source.begin() + 5, destination.end()-2, destination.end(), merged.begin());
    std::cout<<"The merged vector, ";
    PrintVector(merged);

    // merged vector is returned in sorted order

    // Replace a vector element
    // replace(first, last, old_value, new_value);
    // Here,

    // first, last - iterators specifying the range to transform.
    // old_value - value to be replaced.
    // new_value - replacement value.
    std::cout<<"\nThe cpnum before replacement, ";
    PrintVector(cpnum);

    std::replace(cpnum.begin(), cpnum.end(), 2, 13);
    std::cout<<"The replaced cpnum elements, ";
    PrintVector(cpnum);

    // Delete a first occurence of an element
    // remove(first, last, val);
    // Here,

    // first, last - iterators specifying the range to transform
    // val - value to be removed

    std::remove(cpnum.begin(), cpnum.end(), 13);
    std::cout<<"After removing first occurence of 13, ";
    PrintVector(cpnum);
    return 0;
}