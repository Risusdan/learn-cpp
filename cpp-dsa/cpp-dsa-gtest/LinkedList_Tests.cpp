#include "pch.h"
#include "../cpp-dsa/LinkedList.h"
#include "../cpp-dsa/LinkedList.cpp"

TEST(LL_Tests, CreateListWithSingleNode) {
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act & Assert
    EXPECT_EQ(list->getHead(), 10);
    EXPECT_EQ(list->getTail(), 10);
    EXPECT_EQ(list->getLength(), 1);
}

TEST(LL_AppendTests, AppendNodeToEmptyList) {
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->append(10);

    // Assert
    EXPECT_EQ(list->getTail(), 10);
    EXPECT_EQ(list->getLength(), 1);
}

TEST(LL_AppendTests, AppendNodeToExistingList) {
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    list->append(20);

    // Assert
    EXPECT_EQ(list->getTail(), 20);
    EXPECT_EQ(list->getLength(), 2);
}

TEST(LL_PrependTests, PrependNodeToEmptyList) {
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->prepend(10);

    // Assert
    EXPECT_EQ(list->getHead(), 10);
    EXPECT_EQ(list->getTail(), 10);
    EXPECT_EQ(list->getLength(), 1);
}

TEST(LL_PrependTests, PrependNodeToExistingList) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->prepend(40);

    // Assert
    EXPECT_EQ(list->getHead(), 40);
    EXPECT_EQ(list->getTail(), 30);
}

TEST(LL_DeleteLastTests, DeleteLastNodeFromEmptyList) {
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->deleteLast();

    // Assert
    EXPECT_EQ(list->getHead(), INT_MIN);
    EXPECT_EQ(list->getTail(), INT_MIN);
    EXPECT_EQ(list->getLength(), 0);
}

TEST(LL_DeleteLastTests, DeleteLastNodeFromListWithSingleNode) {
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    list->deleteLast();

    // Assert
    EXPECT_EQ(list->getHead(), INT_MIN);
    EXPECT_EQ(list->getTail(), INT_MIN);
    EXPECT_EQ(list->getLength(), 0);
}

TEST(LL_DeleteLastTests, DeleteLastNodeFromListWithMultipleNodes) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // Act
    list->deleteLast();

    // Assert
    EXPECT_EQ(list->getHead(), 10);
    EXPECT_EQ(list->getTail(), 30);
    EXPECT_EQ(list->getLength(), 3);
}

TEST(LL_DeleteFirstTests, DeleteFirstNodeFromEmptyList) {
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->deleteFirst();

    // Assert
    EXPECT_EQ(list->getHead(), INT_MIN);
    EXPECT_EQ(list->getTail(), INT_MIN);
    EXPECT_EQ(list->getLength(), 0);
}

TEST(LL_DeleteFirstTests, DeleteFirstNodeFromListWithSingleNode) {
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    list->deleteFirst();

    // Assert
    EXPECT_EQ(list->getHead(), INT_MIN);
    EXPECT_EQ(list->getTail(), INT_MIN);
    EXPECT_EQ(list->getLength(), 0);
}

TEST(LL_DeleteFirstTests, DeleteFirstNodeFromListWithMultipleNodes) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteFirst();

    // Assert
    EXPECT_EQ(list->getHead(), 20);
    EXPECT_EQ(list->getTail(), 30);
    EXPECT_EQ(list->getLength(), 2);
}

TEST(LL_GetNodeTests, GetNodeFromEmptyList) {
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    Node* node = list->getNode(0);

    // Assert
    EXPECT_EQ(node, nullptr);
}

TEST(LL_GetNodeTests, GetNodeWhenIndexIsOutOfRange) {
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    Node* node = list->getNode(5);

    // Assert
    EXPECT_EQ(node, nullptr);
}

TEST(LL_GetNodeTests, GetNodeFromListWithSingleNode) {
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    Node* node = list->getNode(0);

    // Assert
    EXPECT_EQ(node->value, 10);
}

TEST(LL_GetNodeTests, GetNodeFromListWithMultipleNodes) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    Node* node = list->getNode(1);

    // Assert
    EXPECT_EQ(node->value, 20);
}

TEST(LL_SetNodeTests, SetNodeToEmptyList) {
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    bool result = list->setNode(0, 10);

    // Assert
    EXPECT_EQ(result, false);
}

TEST(LL_SetNodeTests, SetNodeWhenIndexIsOutOfRange) {
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    bool result = list->setNode(5, 20);

    // Assert
    EXPECT_EQ(result, false);
}

TEST(LL_SetNodeTests, SetNodeWhenIndexIsInRange) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->setNode(1, 15);

    // Assert
    EXPECT_EQ(true, result);
    EXPECT_EQ(list->getNode(1)->value, 15);
}

TEST(LL_InsertTests, InsertNodeWhenIndexIsOutOfRange) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(5, 15);

    // Assert
    EXPECT_EQ(result, false);
}

TEST(LL_InsertTests, InsertNodeWhenIndexIsZero) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(0, 15);

    // Assert
    EXPECT_EQ(true, result);
    EXPECT_EQ(list->getHead(), 15);
}

TEST(LL_InsertTests, InsertNodeWhenIndexIsEqualToLength) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(3, 15);

    // Assert
    EXPECT_EQ(true, result);
    EXPECT_EQ(list->getTail(), 15);
}

TEST(LL_InsertTests, InsertNodeWhenIndexIsInRange) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(1, 15);

    // Assert
    EXPECT_EQ(true, result);
    EXPECT_EQ(list->getNode(1)->value, 15);
}

TEST(LL_DeleteNodeTests, DeleteNodeWhenIndexIsOutOfRange) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(5);

    // Assert
    EXPECT_EQ(list->getHead(), 10);
    EXPECT_EQ(list->getTail(), 30);
    EXPECT_EQ(list->getLength(), 3);
}

TEST(LL_DeleteNodeTests, DeleteNodeWhenIndexIsZero) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(0);

    // Assert
    EXPECT_EQ(list->getHead(), 20);
    EXPECT_EQ(list->getTail(), 30);
    EXPECT_EQ(list->getLength(), 2);
}

TEST(LL_DeleteNodeTests, DeleteNodeWhenIndexIsEqualToLengthMinusOne) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(2);

    // Assert
    EXPECT_EQ(list->getHead(), 10);
    EXPECT_EQ(list->getTail(), 20);
    EXPECT_EQ(list->getLength(), 2);
}

TEST(LL_DeleteNodeTests, DeleteNodeWhenIndexIsInRange) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // Act
    list->deleteNode(2);

    // Assert
    EXPECT_EQ(list->getHead(), 10);
    EXPECT_EQ(list->getTail(), 40);
    EXPECT_EQ(list->getLength(), 3);
}

TEST(LL_ReverseTests, ReverseEmptyList) {
    // Arrange
    LinkedList* list = new LinkedList();

    // Act
    list->reverse();

    // Assert
    EXPECT_EQ(list->getHead(), INT_MIN);
    EXPECT_EQ(list->getTail(), INT_MIN);
    EXPECT_EQ(list->getLength(), 0);
}

TEST(LL_ReverseTests, ReverseListWithSingleNode) {
    // Arrange
    LinkedList* list = new LinkedList(10);

    // Act
    list->reverse();

    // Assert
    EXPECT_EQ(list->getHead(), 10);
    EXPECT_EQ(list->getTail(), 10);
    EXPECT_EQ(list->getLength(), 1);
}

TEST(LL_ReverseTests, ReverseListWithMultipleNodes) {
    // Arrange
    LinkedList* list = new LinkedList(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // Act
    list->reverse();

    // Assert
    EXPECT_EQ(list->getHead(), 40);
    EXPECT_EQ(list->getNode(1)->value, 30);
    EXPECT_EQ(list->getNode(2)->value, 20);
    EXPECT_EQ(list->getTail(), 10);
    EXPECT_EQ(list->getLength(), 4);
}
