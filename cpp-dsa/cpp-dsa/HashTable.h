#pragma once
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;

    public:
        Node* dataMap[SIZE];
        void printTable();
        int hash(string key);
        /**
         * @brief Set the value of the key in the hash table
         * @param key The key to set the value for
         * @param value The value to set for the key
         */
        void set(string key, int value);
        /**
         * @brief Get the value of the key in the hash table
         * @param key The key to get the value for
         * @return The value associated with the key
         */
        int get(string key);
        /**
         * @brief Get all the keys in the hash table
         * @return A vector of strings containing all the keys in the hash table
         */
        vector<string> keys();
        /**
         * @brief Check if there is an item in common between two vectors
         * @param vect1 The first vector
         * @param vect2 The second vector
         * @return True if there is an item in common, false otherwise
         */
        bool itemInCommon(vector<int> vect1, vector<int> vect2);
};
