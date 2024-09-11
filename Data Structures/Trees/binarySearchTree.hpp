#ifndef BST_HPP
#define BST_HPP 

#include <iostream>
#include <memory>

namespace myDataStructures {
    template<typename T>
    class NodeTree{
        public:
            std::shared_ptr<NodeTree<T>> left;
            std::shared_ptr<NodeTree<T>> right;
            std::shared_ptr<NodeTree<T>> parent;
            T value;
            NodeTree(T val,std::shared_ptr<NodeTree<T>> parent=nullptr):left(nullptr),right(nullptr),parent(parent),value(val){
                std::cout<<"Created a Node with value "<<val<<std::endl;
            }
    };
    template <typename T>
    class BST{
        private:
        std::shared_ptr<NodeTree<T>> root;
        //helper function to insert
        std::shared_ptr<NodeTree<T>> insertHelper(std::shared_ptr<NodeTree<T>> node,T value,std::shared_ptr<NodeTree<T>> parent){
            if(!node){
                std::shared_ptr<NodeTree<T>> newNode = std::make_shared<NodeTree<T>>(value,parent);
            }
            if(value<node->value){
                node->left=insertHelper(node->left,value,node);
            }
            else if(value>node->value){
                node->right=insertHelper(node->right,value,node);
            }
            return node;
        }
        public:
       
        BST():root(nullptr) {}
        void insert(T val){
        root = insertHelper(root,val,nullptr);
        
        }
        void inOrderHelper(std::shared_ptr<NodeTree<T>> node){
            if(node){
                inOrderHelper(node->left);
                std::cout<<node->value<<" ";
                inOrderHelper(node->right);
            }
        }
        void inOrderTraversal() const;

    };
}


#endif

