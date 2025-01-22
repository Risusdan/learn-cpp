#pragma once

class Node {
  public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
  private:
    Node* head;
    Node* tail;
    unsigned int length;

  public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (head != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList(void);
    int getHead(void);
    int getTail(void);
    unsigned int getLength(void);
    void append(int value);
    void prepend(int value);
    void deleteLast(void);
    void deleteFirst(void);
    Node* getNode(unsigned int index);
    bool setNode(unsigned int index, int value);
    bool insertNode(unsigned int index, int value);
    void deleteNode(unsigned int index);
};
