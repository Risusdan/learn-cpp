#pragma once

class Node {
  public:
    int value;
    Node *next;

    Node() {
        value = 0;
        next = nullptr;
    }

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
  private:
    Node *head;
    Node *tail;
    unsigned int length;

  public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    LinkedList(int value) {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node *temp = head;
        while (head != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    /**
     * @brief Print the linked list
     */
    void printList(void);

    /**
     * @brief Get the head of the linked list
     * @return The head node of the linked list
     */
    int getHead(void);

    /**
     * @brief Get the tail of the linked list
     * @return The tail node of the linked list
     */
    int getTail(void);

    /**
     * @brief Get the length of the linked list
     * @return The length of the linked list
     */
    unsigned int getLength(void);

    /**
     * @brief Append a node to the end of the linked list
     * @param value The value to append to the linked list
     */
    void append(int value);

    /**
     * @brief Prepend a node to the beginning of the linked list
     * @param value The value to prepend to the linked list
     */
      void prepend(int value);

    /**
     * @brief Delete the last node of the linked list
     */
    void deleteLast(void);

    /**
     * @brief Delete the first node of the linked list
     */
    void deleteFirst(void);

    /**
     * @brief Get a node at a specific index
     * @param index The index of the node to get
     * @return The node at the specified index
     */
    Node *getNode(unsigned int index);

    /**
     * @brief Set the value of a node at a specific index
     * @param index The index of the node to set
     * @param value The value to set the node to
     * @return True if the node was set, false otherwise
     */
    bool setNode(unsigned int index, int value);

    /**
     * @brief Insert a node at a specific index
     * @param index The index to insert the node at
     * @param value The value to insert
     * @return True if the node was inserted, false otherwise
     */
    bool insertNode(unsigned int index, int value);

    /**
     * @brief Delete a node at a specific index
     * @param index The index of the node to delete
     */
    void deleteNode(unsigned int index);

    /**
     * @brief Reverse the linked list
     */
    void reverse(void);
};
