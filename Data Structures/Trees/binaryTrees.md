# Binary Search Trees

## Introduction

A Binary Search Tree (BST) is a binary tree in which all the nodes follow the below-mentioned properties −

- The left sub-tree of a node has a key less than or equal to its parent node's key.

- The right sub-tree of a node has a key greater than to its parent node's key.

Thus, the BST divides all its sub-trees into two segments; the left sub-tree and the right sub-tree and can be defined as −

```

BST = { LeftSubtree (all elements) + Root Node + RightSubtree (all elements) }

```

## Searching

To search a given key in Binary Search Tree, we first compare it with root, if the key is present at root, we return root. If key is greater than root’s key, we recur for right subtree of root node. Otherwise we recur for left subtree.

## Insertion

A new key is always inserted at leaf. We start searching a key from root till we hit a leaf node. Once a leaf node is found, the new node is added as a child of the leaf node.

## Deletion

To delete a node, there are three possible cases to consider −

- Node to be deleted is leaf: Simply remove from the tree.

- Node to be deleted has only one child: Copy the child to the node and delete the child

- Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used.

## Complexity Analysis

The worst-case time complexity of search, insert and delete operations is O(h) where h is the height of the BST.

