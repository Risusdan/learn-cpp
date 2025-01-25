#pragma once

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {
    public:
        Node* root;

        BinarySearchTree() {
            root = nullptr;
        }

        BinarySearchTree(int value) {
            Node* newNode = new Node(value);
            root = newNode;
        }

        ~BinarySearchTree();
        bool insert(int value);
        bool contains(int value);
};
