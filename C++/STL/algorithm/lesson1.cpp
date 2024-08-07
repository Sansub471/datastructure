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