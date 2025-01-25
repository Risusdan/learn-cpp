/**
 * @file Tree.cpp
 * @brief Implementation of a binary tree data structure
 * @details This file contains the implementation of a binary tree class
 * that provides basic operations like insert/delete values
 *
 * Terminology:
 * - Root node: the topmost node in the tree
 * - Parent node: a node that has at least one child
 * - Child node: a node that has at least one parent, a child node can also be a
 * parent node
 * - Leaf node: a node that has no children
 * - Full tree: every node has either 0 or 2 children
 * - Complete tree: every level is filled except the last level, and the last
 * level is filled from left to right
 * - Perfect tree: every node has 2 children, and all leaf nodes are at the same
 * level
 * - Binary search tree (BST): a binary tree where the left child is less than
 * the parent node, and the right child is greater than the parent node
 * - It is not allowed to have duplicate values in a BST
 *
 * @author Daniel Su
 * @date 2025-01-22
 *
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include "Tree.h"

using namespace std;

bool BinarySearchTree::insert(int value) {
    Node* newNode = new Node(value);

    // if the tree is empty, insert the new node as the root
    if (root == nullptr) {
        root = newNode;
        return true;
    }

    // if the tree is not empty, insert the new node in the correct position
    Node* temp = root;
    while (true) {
        // it is not allowed to have duplicate values in a BST
        if (newNode->value == temp->value) {
            return false;
        }
        // insert node to the left or right of the current node
        if (newNode->value < temp->value) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                return true;
            }
            temp = temp->left;
        } else {
            if (temp->right == nullptr) {
                temp->right = newNode;
                return true;
            }
            temp = temp->right;
        }
    }
}

bool BinarySearchTree::contains(int value) {
    // it's ok without this check (why?)
    // if (root == nullptr) {return false;}

    Node* temp = root;
    while (temp != nullptr) {
        if (value < temp->value) {
            temp = temp->left;
        } else if (value > temp->value) {
            temp = temp->right;
        } else {
            // if the value is found
            return true;
        }
    }
    // if the value is not found
    return false;
}
