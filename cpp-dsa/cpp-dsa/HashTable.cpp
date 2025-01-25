/**
 * @file HashTable.cpp
 * @brief Implementation of a hash table data structure
 * @details This file contains the implementation of a hash table class
 *
 * There are two characteristics of hash function:
 * - Hash function is one-way function, it's not reversible
 * - Hash function is deterministic, it always returns the same output for the
 * same input
 *
 * A collision is when two different inputs produce the same output, there are
 * several ways to handle collisions:
 * - Separate chaining: each bucket has a linked list of key-value pairs
 * - Linear probing: if a collision occurs, the key is stored in the next
 * available bucket
 *
 * The bigO of set(insert) and get(lookup) by "key" in a HashTable is O(1) on
 * average, although the worst case scenario is O(n) when many collisions occur.
 * Note that looking up by "value" in a HashTable is O(n) because we need to
 * check all buckets since values are not hashed and could be stored anywhere in
 * the table.
 *
 * @author Daniel Su
 * @date 2025-01-25
 *
 * @copyright Copyright (c) 2025
 */

#include <iostream>
#include "HashTable.h"

using namespace std;

void HashTable::printTable() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << ":" << endl;
        if (dataMap[i] != nullptr) {
            Node* temp = dataMap[i];
            while (temp != nullptr) {
                cout << "   {" << temp->key << ", " << temp->value << "}"
                     << endl;
                temp = temp->next;
            }
        }
    }
}

int HashTable::hash(string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
        int asciiValue = int(key[i]);
        // here we use a prime number 23 to make the hash function result more
        // random, thus reducing the chance of collision
        // we also use the modulo operator to ensure the hash value is within
        // the range of the hash table size
        hash = (hash + asciiValue * 23) % SIZE;
    }
    return hash;
}

void HashTable::set(string key, int value) {
    Node* newNode = new Node(key, value);
    int index = hash(key);

    if (dataMap[index] == nullptr) {
        // if the bucket is empty, we directly assign the new node to the bucket
        dataMap[index] = newNode;
    } else {
        // if the bucket is not empty, we need to handle the collision( by
        // separate chaining)
        Node* temp = dataMap[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int HashTable::get(string key) {
    int index = hash(key);
    Node* temp = dataMap[index];
    while (temp != nullptr) {
        if (temp->key == key) return temp->value;
        temp = temp->next;
    }
    return 0;
}

vector<string> HashTable::keys() {
    vector<string> allKeys;
    for (int i = 0; i < SIZE; i++) {
        Node* temp = dataMap[i];
        while (temp != nullptr) {
            // append the key to the vector
            allKeys.push_back(temp->key);
            temp = temp->next;
        }
    }
    return allKeys;
}

bool HashTable::itemInCommon(vector<int> vect1, vector<int> vect2) {
    unordered_map<int, bool> myMap;

    for (int i : vect1) {
        myMap.insert({i, true});
    }

    for (int j : vect2) {
        if (myMap[j]) return true;
    }

    return false;
}
