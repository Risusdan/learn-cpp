#include "pch.h"
#include "../cpp-dsa/HashTable.h"
#include "../cpp-dsa/HashTable.cpp"

TEST(HashTable_HashTests, Hash) {
    // Arrange
    HashTable* hashTable = new HashTable();

    // Act
    int hash1 = hashTable->hash("nails");
    int hash2 = hashTable->hash("screws");
    int hash3 = hashTable->hash("bolts");

    // Assert
    EXPECT_EQ(hash1, 6);
    EXPECT_EQ(hash2, 3);
    EXPECT_EQ(hash3, 4);
}

TEST(HashTable_SetTests, Set) {
    // Arrange
    HashTable* hashTable = new HashTable();

    // Act
    hashTable->set("nails", 100);
    hashTable->set("tile", 50);
    hashTable->set("lumber", 80);
    hashTable->set("bolts", 200);
    hashTable->set("screws", 140);

    // Assert
    EXPECT_EQ(hashTable->dataMap[3]->key, "screws");
    EXPECT_EQ(hashTable->dataMap[3]->value, 140);
    EXPECT_EQ(hashTable->dataMap[4]->key, "bolts");
    EXPECT_EQ(hashTable->dataMap[4]->value, 200);
    EXPECT_EQ(hashTable->dataMap[6]->key, "nails");
    EXPECT_EQ(hashTable->dataMap[6]->value, 100);
    EXPECT_EQ(hashTable->dataMap[6]->next->key, "tile");
    EXPECT_EQ(hashTable->dataMap[6]->next->value, 50);
    EXPECT_EQ(hashTable->dataMap[6]->next->next->key, "lumber");
    EXPECT_EQ(hashTable->dataMap[6]->next->next->value, 80);
}

TEST(HashTable_GetTests, IndexAlreadyHasKeyValuePair) {
    // Arrange
    HashTable* hashTable = new HashTable();

    // Act
    hashTable->set("nails", 100);
    hashTable->set("tile", 50);
    hashTable->set("lumber", 80);

    // Assert
    EXPECT_EQ(hashTable->get("nails"), 100);
    EXPECT_EQ(hashTable->get("tile"), 50);
    EXPECT_EQ(hashTable->get("lumber"), 80);
}

TEST(HashTable_GetTests, IndexDoesNotHaveKeyValuePair) {
    // Arrange
    HashTable* hashTable = new HashTable();

    // Act
    hashTable->set("nails", 100);
    hashTable->set("tile", 50);
    hashTable->set("lumber", 80);

    // Assert
    EXPECT_EQ(hashTable->get("bolts"), 0);  
}

TEST(HashTable_KeysTests, Keys) {
    // Arrange
    HashTable* hashTable = new HashTable();

    // Act
    hashTable->set("paint", 20);
    hashTable->set("bolts", 40);
    hashTable->set("nails", 100);
    hashTable->set("tile", 50);
    hashTable->set("lumber", 80);

    // Assert
    vector<string> keys = hashTable->keys();
    EXPECT_EQ(keys.size(), 5);
    EXPECT_EQ(keys[0], "paint");
    EXPECT_EQ(keys[1], "bolts");
    EXPECT_EQ(keys[2], "nails");
    EXPECT_EQ(keys[3], "tile");
    EXPECT_EQ(keys[4], "lumber");
}

TEST(HashTable_ItemInCommonTests, ItemInCommon) {
    // Arrange
    HashTable* hashTable = new HashTable();

    // Act
    vector<int> vect1 = {1, 3, 5};
    vector<int> vect2 = {2, 4, 5};

    // Assert
    EXPECT_TRUE(hashTable->itemInCommon(vect1, vect2));
}

TEST(HashTable_ItemInCommonTests, ItemNotInCommon) {
    // Arrange
    HashTable* hashTable = new HashTable();

    // Act
    vector<int> vect1 = {1, 3, 5};
    vector<int> vect2 = {2, 4, 6};

    // Assert
    EXPECT_FALSE(hashTable->itemInCommon(vect1, vect2));
}
