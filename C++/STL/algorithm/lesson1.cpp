#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {

    vector<int> source = {1, 2, 3, 4, 5};

    // create destination vector of size 5
    vector<int> destination(5);
    
    // copy the contents of source to destination
    copy(source.begin(), source.end(), destination.begin());

    // print elements of destination vector
    for(int num : destination) {
        cout << num << " ";
    }

    return 0;
}

// Functions	Description
// sort()	Sort the elements of the container.
// copy()	Copy elements within a given range.
// move()	Move the given range of elements.
// swap()	Exchange values of two objects.
// merge()	Merge sorted ranges.
// replace()	Replace the value of an element.
// remove()	Remove an element.