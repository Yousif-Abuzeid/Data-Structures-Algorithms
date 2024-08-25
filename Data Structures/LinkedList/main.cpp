#include "LinkedList.hpp"
//Test cases
int main() {
    // Test parameterized constructor
    myDataStructures::LinkedList<int> L1({1, 2, 3, 4, 5});
    std::cout << "Initial list:" << std::endl;
    L1.display();

    // Test insert method
    L1.insert(5);
    L1.insert(10);
    L1.insert(15);
    L1.insert(20);
    L1.insert(20);
    L1.insert(20);
    L1.insert(20);
    std::cout << "After insertions:" << std::endl;
    L1.display();

    // Test PopStart method
    L1.PopStart();
    L1.PopStart();
    std::cout << "After popping from start:" << std::endl;
    L1.display();

    // Test insertAtStart method
    L1.insert(40);
    L1.PopEnd();
    std::cout << "After popping from end and inserting at start:" << std::endl;
    L1.insertAtStart(100);
    L1.display();

    // Test subscript operator
    std::cout << "Element at index 0: " << L1[0] << std::endl;
    std::cout << "Element at index 2: " << L1[2] << std::endl;

    // Test search and count methods
    L1.insert(50);
    L1.insert(60);
    L1.insert(70);
    std::cout << "Search for 50 found at index: " << L1.search(50) << std::endl;
    std::cout << "Count of 20: " << L1.count(20) << std::endl;

    // Test move constructor
    myDataStructures::LinkedList<int> L2(std::move(L1));
    std::cout << "List L2 after move construction:" << std::endl;
    L2.display();
    std::cout << "List L1 after move (should be empty):" << std::endl;
    L1.display();

    return 0;
}
