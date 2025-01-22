/**
 * @file LinkedList.cpp
 * @brief Implementation of a singly linked list data structure
 * @details This file contains the implementation of a singly linked list class
 * that provides basic operations like inserting/deleting nodes and accessing
 * head/tail values
 *
 * @author Daniel Su
 * @date 2025-01-06
 *
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include "Linkedlist.h"

using namespace std;

void LinkedList::printList(void) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int LinkedList::getHead(void) { return ((head != nullptr) ? head->value : INT_MIN); }

int LinkedList::getTail(void) { return ((tail != nullptr) ? tail->value : INT_MIN); }

unsigned int LinkedList::getLength(void) { return length; }

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (length == 0U) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    if (length == 0U) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void LinkedList::deleteLast(void) {
    if (length == 0U) {
        return;
    }

    Node* last = nullptr;

    if (length == 1U) {
        last = tail;
        head = nullptr;
        tail = nullptr;
    } else {
        Node* pre = head;
        while (pre->next != tail) {
            pre = pre->next;
        }
        last = tail;
        tail = pre;
        tail->next = nullptr;
    }
    delete last;
    length--;
}

void LinkedList::deleteFirst(void) {
    if (length == 0U) {
        return;
    }

    Node* temp = head;
    head = head->next;
    if (length == 1U) {
        tail = nullptr;
    }
    delete temp;
    length--;
}

Node* LinkedList::getNode(unsigned int index) {
    if (length == 0U || index >= length) {
        return nullptr;
    }

    Node* temp = head;
    for (unsigned int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

bool LinkedList::setNode(unsigned int index, int value) {
    Node* temp = getNode(index);
    if (temp == nullptr) {
        return false;
    }
    temp->value = value;
    return true;
}

bool LinkedList::insertNode(unsigned int index, int value) {
    if (index > length) {
        return false;
    } else if (index == 0U) {
        prepend(value);
        return true;
    } else if (index == length) {
        append(value);
        return true;
    } else {
        Node* newNode = new Node(value);
        Node* pre = getNode(index - 1);
        newNode->next = pre->next;
        pre->next = newNode;
        length++;
        return true;
    }
}

void LinkedList::deleteNode(unsigned int index) {
    if (index >= length) {
        return;
    }

    if (index == 0U) {
        return deleteFirst();
    }

    if (index == length - 1U) {
        return deleteLast();
    }

    Node* pre = getNode(index - 1);
    Node* nodeToDelete = pre->next;
    pre->next = nodeToDelete->next;
    delete nodeToDelete;
    length--;
}

void LinkedList::reverse(void) {
    if (length <= 1U) {
        return;
    }

    // Swap head and tail
    Node* temp = head;
    head = tail;
    tail = temp;

    // Initialize before and after
    Node* after = temp->next;
    Node* before = nullptr;

    // Loop through list and swap next and before
    for (unsigned int i = 0; i < length; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
}
