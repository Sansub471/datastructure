#include"mTree.hpp"


int main() {
    const int M = 4;
    MWayTree<int, M> m_tree;

    int arr[] = {10, 20, 5, 15, 25, 12};
    for(int x : arr){
        m_tree.insert(x);
    }

    std::cout<<"Search 15: "<< (m_tree.contains(15) ? "Found" : "Not Found") << "\n";
    std::cout<<"Search 99: "<< (m_tree.contains(99) ? "Found" : "Not Found") << "\n";

    
    return 0;
}

