/**
 * @file Queue.cpp
 * @brief Implementation of a queue data structure
 * @details This file contains the implementation of a queue class
 * that provides basic operations like enqueue/dequeue values
 *
 * @author Daniel Su
 * @date 2025-01-22
 *
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include "Queue.h"

using namespace std;

void Queue::printQueue() {
    Node* temp = first;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int Queue::getFirst() { return ((first != nullptr) ? first->value : INT_MIN); }

int Queue::getLast() { return ((last != nullptr) ? last->value : INT_MIN); }

int Queue::getLength() { return length; }

// borrow from the "append" function in the linked list
// why? because the complexity of the append function is O(1)
void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (length == 0U) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    length++;
}

// borrow from the "deleteFirst" function in the linked list
// why? because the complexity of the deleteFirst function is O(1)
int Queue::dequeue() {
    if (length == 0U) return INT_MIN;
    Node* temp = first;
    int dequeuedValue = temp->value;
    if (length == 1U) {
        first = nullptr;
        last = nullptr;
    } else {
        first = first->next;
    }
    delete temp;
    length--;
    return dequeuedValue;
}
