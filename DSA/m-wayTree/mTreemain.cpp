#include"mTree.hpp"

int main() {
    const int M = 4;
    MWayTree<int, M> T;
    int arr[] = {10, 20, 5, 15, 25, 12};
    for (int x : arr) T.insertAndShow(x);

    cout << "Search 15: " << (T.contains(15) ? "found" : "not found") << "\n";
    cout << "Search 100: " << (T.contains(100) ? "found" : "not found") << "\n";
    return 0;
}