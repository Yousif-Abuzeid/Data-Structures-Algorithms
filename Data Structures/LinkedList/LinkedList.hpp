#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <initializer_list>
#include <iostream>
namespace myDataStructures {

// Forward declaration of LinkedList class
template <typename T>
class LinkedList;

// Node class to represent each element in the linked list
template <typename T>
class Node {
private:
    T value;              // Value stored in the node
    Node<T>* next;        // Pointer to the next node in the list

public:
    // Friend declaration to grant LinkedList access to private members
    friend class LinkedList<T>;

    // Default constructor
    Node() : value(0), next(nullptr) {}

    // Parameterized constructor
    Node(T val) : value(val), next(nullptr) {}
};

// LinkedList class to manage the list operations
template <typename T>
class LinkedList {
private:
    Node<T>* Head;        // Pointer to the first node in the list

public:
    // Default constructor
    LinkedList() : Head(nullptr) {}

    // Parameterized constructor using initializer list
    LinkedList(std::initializer_list<T> list) : Head(nullptr) {
        for (auto i = list.begin(); i != list.end(); ++i) {
            this->insert(*i);
        }
    }

    // Copy constructor
    LinkedList(const LinkedList<T>& ref) : Head(nullptr) {
        Node<T>* current = ref.Head;
        while (current != nullptr) {
            this->insert(current->value);
            current = current->next;
        }
    }

    // Move constructor
    LinkedList(LinkedList<T>&& ref) : Head(ref.Head) {
        ref.Head = nullptr;
    }

    // Copy assignment operator
    LinkedList<T>& operator=(const LinkedList<T>& ref) {
        if (this == &ref) {
            return *this;
        }
        // Clear existing list
        this->~LinkedList();

        Node<T>* current = ref.Head;
        while (current != nullptr) {
            this->insert(current->value);
            current = current->next;
        }
        return *this;
    }

    // Move assignment operator
    LinkedList<T>& operator=(LinkedList<T>&& ref) {
        if (this == &ref) {
            return *this;
        }
        // Clear existing list
        this->~LinkedList();

        Head = ref.Head;
        ref.Head = nullptr;
        return *this;
    }

    // Destructor
    ~LinkedList() {
        Node<T>* current = Head;
        Node<T>* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        Head = nullptr;
    }

    // Method to insert a value at the end of the list
    void insert(T val) {
        if (Head == nullptr) {
            Head = new Node<T>(val);
        } else {
            Node<T>* current = Head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node<T>(val);
        }
    }

    // Method to insert a value at the start of the list
    void insertAtStart(T val) {
        Node<T>* temp = new Node<T>(val);
        temp->next = Head;
        Head = temp;
    }

    // Method to get the size of the list
    int size() const {
        int count = 0;
        Node<T>* current = Head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Method to search for a value in the list and return its index
    int search(T val) const {
        Node<T>* current = Head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == val) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Value not found
    }

    // Method to count occurrences of a value in the list
    int count(T val) const {
        Node<T>* current = Head;
        int count = 0;
        while (current != nullptr) {
            if (current->value == val) {
                count++;
            }
            current = current->next;
        }
        return count;
    }

    // Method to remove the first node from the list
    void PopStart() {
        if (Head == nullptr) {
            return; // Empty list
        }
        if (Head->next == nullptr) {
            delete Head; // Only one node in the list
            Head = nullptr;
            return;
        }
        Node<T>* temp = Head;
        Head = Head->next;
        delete temp;
    }

    // Method to remove the last node from the list
    void PopEnd() {
        if (Head == nullptr) {
            return; // Empty list
        }
        if (Head->next == nullptr) {
            delete Head; // Only one node in the list
            Head = nullptr;
            return;
        }
        Node<T>* current = Head;
        Node<T>* previous = nullptr;
        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        delete current;
        previous->next = nullptr;
    }

    // Method to display the list elements
    void display() const {
        if (Head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node<T>* current = Head;
        while (current->next != nullptr) {
            std::cout << current->value << " -> ";
            current = current->next;
        }
        std::cout << current->value << std::endl;
    }

    // Overloaded subscript operator to access elements by index
    T& operator[](int pos) const {
        if (pos >= this->size() || pos < 0) {
            std::cout << "Index out of range" << std::endl;
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = Head;
        int count = 0;
        while (count != pos) {
            current = current->next;
            count++;
        }
        return current->value;
    }
};
    
    } // namespace myDataStructures




#endif // !