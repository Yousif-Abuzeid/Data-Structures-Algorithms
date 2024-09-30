#ifndef BST_HPP
#define BST_HPP 

#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

namespace myDataStructures {

    /**
     * @brief A class representing a node in a binary search tree.
     * 
     * @tparam T The type of the value stored in the node.
     */
    template<typename T>
    class NodeTree {
    public:
        std::shared_ptr<NodeTree<T>> left;   ///< Pointer to the left child node.
        std::shared_ptr<NodeTree<T>> right;  ///< Pointer to the right child node.
        std::shared_ptr<NodeTree<T>> parent; ///< Pointer to the parent node.
        T value;                             ///< Value stored in the node.

        /**
         * @brief Construct a new NodeTree object.
         * 
         * @param val The value to be stored in the node.
         * @param parent Pointer to the parent node (default is nullptr).
         */
        NodeTree(T val, std::shared_ptr<NodeTree<T>> parent = nullptr)
            : left(nullptr), right(nullptr), parent(parent), value(val) {
            std::cout << "Created a Node with value " << val << std::endl;
        }
        // delete copy constructor and assignment operator

        NodeTree(const NodeTree<T>& other) = delete;
        NodeTree<T>& operator=(const NodeTree<T>& other) = delete;
        // move constructor
        NodeTree(NodeTree<T>&& other) {
            left = std::move(other.left);
            right = std::move(other.right);
            parent = std::move(other.parent);
            value = std::move(other.value);
        }
        // move assignment operator
        NodeTree<T>& operator=(NodeTree<T>&& other) {
            if (this != &other) {
                left = std::move(other.left);
                right = std::move(other.right);
                parent = std::move(other.parent);
                value = std::move(other.value);
            }
            return *this;
        }
        std::shared_ptr<NodeTree<T>> operator=(std::shared_ptr<NodeTree<T>>&& other) {
            left = std::move(other->left);
            right = std::move(other->right);
            parent = std::move(other->parent);
            value = std::move(other->value);
            return *this;
        }
        

    };

    /**
     * @brief A class representing a binary search tree (BST).
     * 
     * @tparam T The type of the value stored in the tree nodes.
     */
    template <typename T>
    class BST {
    private:
        std::shared_ptr<NodeTree<T>> root;   ///< Pointer to the root of the tree.

        /**
         * @brief Helper function to insert a new value into the tree.
         * 
         * @param node The current node being evaluated.
         * @param value The value to be inserted.
         * @param parent The parent of the current node.
         * @return std::shared_ptr<NodeTree<T>> Pointer to the node after insertion.
         */
        std::shared_ptr<NodeTree<T>> insertHelper(std::shared_ptr<NodeTree<T>> node, T value, std::shared_ptr<NodeTree<T>> parent) {
            if (!node) {
                // Create a new node if the current node is nullptr.
                std::shared_ptr<NodeTree<T>> newNode = std::make_shared<NodeTree<T>>(value, parent);
                return newNode;
            }

            // Recursively insert into the left or right subtree.
            if (value < node->value) {
                node->left = insertHelper(node->left, value, node);
            }
            else if (value > node->value) {
                node->right = insertHelper(node->right, value, node);
            }
            return node;
        }

        /**
         * @brief Helper function to perform in-order traversal of the tree.
         * 
         * @param node The current node being evaluated.
         */
        void inOrderHelper(std::shared_ptr<NodeTree<T>> node) const {
            if (node) {
                // Traverse the left subtree, visit the current node, and traverse the right subtree.
                inOrderHelper(node->left);
                std::cout << node->value << " ";
                inOrderHelper(node->right);
            }
        }
        void preOrderHelper(std::shared_ptr<NodeTree<T>> node) const {
            if (node) {
                // Traverse the left subtree, visit the current node, and traverse the right subtree.
                std::cout << node->value << " ";
                preOrderHelper(node->left);
                preOrderHelper(node->right);
            }
        }
        void postOrderHelper(std::shared_ptr<NodeTree<T>> node) const {
            if (node) {
                // Traverse the left subtree, visit the current node, and traverse the right subtree.
                postOrderHelper(node->left);
                postOrderHelper(node->right);
                std::cout << node->value << " ";
            }
        }
        /*
         * @brief Helper function to search for a value in the tree.
         * @param node The current node being evaluated.
         */
        std::shared_ptr<NodeTree<T>> searchHelper(std::shared_ptr<NodeTree<T>> node,T val){
            if(!node){
                return nullptr;
            }
            if(val>node->value){
               return  searchHelper(node->right,val);
            }else if(val<node->value){
                return searchHelper(node->left, val);
            }else{
                return node;
            }
        }
        /*
         * @brief Helper function to get successor of a node
        */
        std::shared_ptr<NodeTree<T>> getSuccessor(std::shared_ptr<NodeTree<T>> node){
            node=node->right;
            while (node!=nullptr &&node->left!=nullptr) {
                node=node->left;
            }
            return node;
        }

    public:
        /**
         * @brief Construct a new empty BST object.
         */
        BST() : root(nullptr) {}
        /**
         * @brief Construct a new BST object with a given root value.
         * @param val The value to be stored in the root node.
         */
        BST(T val) : root(std::make_shared<NodeTree<T>>(val)) {}
        /**
         * @brief Construct a new BST object with a given initializer list of values.
         * @param values The list of values to be inserted into the tree.
         */
        BST(std::initializer_list<T> values) : root(nullptr) {
            for (T val : values) {
                insert(val);
            }
        }
        /**
         * @brief Destroy the BST object.
         */
        ~BST() {
            root.reset();
        }
        
        /**
         * @brief Insert a new value into the tree.
         * 
         * @param val The value to be inserted.
         */
        void insert(T val) {
            root = insertHelper(root, val, nullptr);
        }
        /**
         * @brief Search for a value if found returns a pointer to its node 
                    else it returns a nullptr 
                    Use a guard before accessing it
        * @param value The value to search for.
         */
        std::shared_ptr<NodeTree<T>> search(T value){
            return searchHelper(root, value);
        }

        /**
         * @brief Perform an in-order traversal of the tree and print the node values.
         */
        void inOrderTraversal() const {
            inOrderHelper(root);
        }
        /**
            * @brief Perform a pre-order traversal of the tree and print the node values.
         */
        void preOrderTraversal() const {
            preOrderHelper(root);
        }
        /**
            * @brief Perform a post-order traversal of the tree and print the node values.
         */
        void postOrderTraversal() const {
            postOrderHelper(root);
        }
       void remove(T val) {
    std::shared_ptr<NodeTree<T>> Successor;

    // Find the node to remove
    std::shared_ptr<NodeTree<T>> myNode = search(val);

    // Check if the node exists
    if (myNode == nullptr) {
        std::cout << "Element Doesn't Exist" << std::endl;
        return;
    }

    auto left = myNode->left;
    auto right = myNode->right;

    // Check if it is a leaf node (no children)
    if (left == nullptr && right == nullptr) {
        // If the node is a root node
        if (myNode == root) {
            root.reset();
        } else if (myNode->parent->left == myNode) {
            myNode->parent->left.reset();
        } else {
            myNode->parent->right.reset();
        }
        myNode.reset();  // Delete the node
        return;
    }

    // If the node has two children, find the successor
    if (left != nullptr && right != nullptr) {
        Successor = getSuccessor(myNode);
        T temp = Successor->value;
        remove(Successor->value);  // Remove the successor
        myNode->value = temp;      // Copy the successor's value to myNode
        return;
    }

    // If the node has only one child, move the child up
    if (left != nullptr && right == nullptr) {
        // If myNode is root, update the root pointer
        if (myNode == root) {
            root = myNode->left;
        } else if (myNode->parent->left == myNode) {
            myNode->parent->left = std::move(myNode->left);
        } else {
            myNode->parent->right = std::move(myNode->left);
        }
        myNode.reset();
        return;
    }

    if (left == nullptr && right != nullptr) {
        // If myNode is root, update the root pointer
        if (myNode == root) {
            root = myNode->right;
        } else if (myNode->parent->left == myNode) {
            myNode->parent->left = std::move(myNode->right);
        } else {
            myNode->parent->right = std::move(myNode->right);
        }
        myNode.reset();
        return;
    }
}
    int height (std::shared_ptr<NodeTree<T>> node){
        if(node==nullptr){
            return 0;
        }
        int leftHeight=height(node->left);
        int rightHeight=height(node->right);
        return std::max(leftHeight,rightHeight)+1;
    }
   std::shared_ptr<NodeTree<T>> getRoot(){
        return root;
    }
    };

}

#endif
