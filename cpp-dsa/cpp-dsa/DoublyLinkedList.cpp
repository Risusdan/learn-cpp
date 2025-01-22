/**
 * @file DoublyLinkedList.cpp
 * @brief Implementation of a doubly linked list data structure
 * @details This file contains the implementation of a doubly linked list class
 * that provides basic operations like inserting/deleting nodes and accessing
 * head/tail values
 *
 * @author Daniel Su
 * @date 2025-01-06
 *
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void DoublyLinkedList::printList(void) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int DoublyLinkedList::getHead(void) {
    if (head == nullptr) {
        return INT_MIN;
    }
    return head->value;
}

int DoublyLinkedList::getTail(void) {
    if (tail == nullptr) {
        return INT_MIN;
    }
    return tail->value;
}

unsigned int DoublyLinkedList::getLength(void) { return length; }

void DoublyLinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

void DoublyLinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

void DoublyLinkedList::deleteLast(void) {
    if (length == 0) {
        return;
    }

    Node* temp = tail;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

void DoublyLinkedList::deleteFirst(void) {
    if (length == 0) {
        return;
    }

    Node* temp = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    length--;
}

Node* DoublyLinkedList::getNode(unsigned int index) {
    if (length == 0U || index >= length) {
        return nullptr;
    }

    Node* temp = head;
    if (index < length / 2) {
        for (unsigned int i = 0; i < index; i++) {
            temp = temp->next;
        }
    } else {
        temp = tail;
        for (unsigned int i = length - 1; i > index; i--) {
            temp = temp->prev;
        }
    }
    return temp;
}

bool DoublyLinkedList::setNode(unsigned int index, int value) {
    Node* temp = getNode(index);
    if (temp == nullptr) {
        return false;
    }
    temp->value = value;
    return true;
}

bool DoublyLinkedList::insertNode(unsigned int index, int value) {
    if (index > length) {
        return false;
    }
    if (index == 0) {
        prepend(value);
        return true;
    }
    if (index == length) {
        append(value);
        return true;
    }

    Node* newNode = new Node(value);
    Node* before = getNode(index - 1);
    Node* after = before->next;

    newNode->prev = before;
    newNode->next = after;
    before->next = newNode;
    after->prev = newNode;

    length++;
    return true;
}

void DoublyLinkedList::deleteNode(unsigned int index) {
    if (index >= length) {
        return;
    }
    if (index == 0) {
        deleteFirst();
        return;
    }
    if (index == length - 1) {
        deleteLast();
        return;
    }

    Node* temp = getNode(index);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    length--;
}
