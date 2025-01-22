/**
 * @file Stack.cpp
 * @brief Implementation of a stack data structure
 * @details This file contains the implementation of a stack class
 * that provides basic operations like pushing/popping values
 *
 * @author Daniel Su
 * @date 2025-01-22
 *
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include "Stack.h"

using namespace std;

void Stack::printStack(void) {
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int Stack::getTop(void) { return ((top != nullptr) ? top->value : INT_MIN); }

int Stack::getHeight(void) { return height; }

// borrow from the "prepend" function in the linked list
void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height++;
}

// borrow from the "deleteFirst" function in the linked list
int Stack::pop(void) {
    if (height == 0U) return INT_MIN;
    Node* temp = top;
    top = top->next;
    height--;
    return temp->value;
}
