#ifndef BST_HPP
#define BST_HPP 

#include <iostream>
#include <memory>

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

    public:
        /**
         * @brief Construct a new empty BST object.
         */
        BST() : root(nullptr) {}
        /**
         * @brief Construct a new BST object with a given root value.
         */
        BST(T val) : root(std::make_shared<NodeTree<T>>(val)) {}
        /**
         * @brief Construct a new BST object with a given initializer list of values.
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
    };

}

#endif
