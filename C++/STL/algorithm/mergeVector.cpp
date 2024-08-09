#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {

    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {4, 5, 6};

    // print vec1 and vec2 before swap
    cout << "Before swap:" << endl;
    cout << "vec1: ";
    for(int num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "vec2: ";
    for(int num : vec2) {
        cout << num << " ";
    }
    cout << endl;

    // swap vec1 and vec2
    swap(vec1, vec2);

    // print vec1 and vec2 after swap
    cout << "After swap:" << endl;
    cout << "vec1: ";
    for(int num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    cout << "vec2: ";
    for(int num : vec2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
