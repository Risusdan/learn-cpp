#include "pch.h"
#include "../cpp-dsa/DoublyLinkedList.h"
#include "../cpp-dsa/DoublyLinkedList.cpp"

namespace DoublyLinkedListTests {

TEST(DLL_Tests, CreateEmptyList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList();

    // Act & Assert
    ASSERT_EQ(list->getLength(), 0);
}

TEST(DLL_Tests, CreateListWithSingleNode) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList();
    list->append(1);

    // Act & Assert
    ASSERT_EQ(list->getLength(), 1);
    ASSERT_EQ(list->getHead(), 1);
    ASSERT_EQ(list->getTail(), 1);
}

TEST(DLL_AppendTests, AppendNodeToEmptyList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList();

    // Act
    list->append(9);

    // Assert
    ASSERT_EQ(list->getLength(), 1);
    ASSERT_EQ(list->getHead(), 9);
    ASSERT_EQ(list->getTail(), 9);
}

TEST(DLL_AppendTests, AppendNodeToExistingList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);

    // Act
    list->append(9);

    // Assert
    ASSERT_EQ(list->getLength(), 2);
    ASSERT_EQ(list->getHead(), 10);
    ASSERT_EQ(list->getTail(), 9);
}

TEST(DLL_PrependTests, PrependNodeToEmptyList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList();

    // Act
    list->prepend(9);

    // Assert
    ASSERT_EQ(list->getLength(), 1);
    ASSERT_EQ(list->getHead(), 9);
    ASSERT_EQ(list->getTail(), 9);
}

TEST(DLL_PrependTests, PrependNodeToExistingList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);

    // Act
    list->prepend(9);

    // Assert
    ASSERT_EQ(list->getLength(), 2);
    ASSERT_EQ(list->getHead(), 9);
    ASSERT_EQ(list->getTail(), 10);
}

TEST(DLL_DeleteLastTests, DeleteLastNodeFromEmptyList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList();

    // Act
    list->deleteLast();

    // Assert
    ASSERT_EQ(list->getLength(), 0);
    ASSERT_EQ(list->getHead(), -1);
    ASSERT_EQ(list->getTail(), -1);
}

TEST(DLL_DeleteLastTests, DeleteLastNodeFromListWithSingleNode) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);

    // Act
    list->deleteLast();

    // Assert
    ASSERT_EQ(list->getLength(), 0);
    ASSERT_EQ(list->getHead(), -1);
    ASSERT_EQ(list->getTail(), -1);
}

TEST(DLL_DeleteLastTests, DeleteLastNodeFromListWithMultipleNodes) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteLast();

    // Assert
    ASSERT_EQ(list->getLength(), 2);
    ASSERT_EQ(list->getHead(), 10);
    ASSERT_EQ(list->getTail(), 20);
}

TEST(DLL_DeleteFirstTests, DeleteFirstNodeFromEmptyList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList();

    // Act
    list->deleteFirst();

    // Assert
    ASSERT_EQ(list->getLength(), 0);
    ASSERT_EQ(list->getHead(), -1);
    ASSERT_EQ(list->getTail(), -1);
}

TEST(DLL_DeleteFirstTests, DeleteFirstNodeFromListWithSingleNode) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);

    // Act
    list->deleteFirst();

    // Assert
    ASSERT_EQ(list->getLength(), 0);
    ASSERT_EQ(list->getHead(), -1);
    ASSERT_EQ(list->getTail(), -1);
}

TEST(DLL_DeleteFirstTests, DeleteFirstNodeFromListWithMultipleNodes) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteFirst();

    // Assert
    ASSERT_EQ(list->getLength(), 2);
    ASSERT_EQ(list->getHead(), 20);
    ASSERT_EQ(list->getTail(), 30);
}

TEST(DLL_GetNodeTests, GetNodeFromEmptyList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList();

    // Act
    Node *node = list->getNode(0);

    // Assert
    ASSERT_EQ(node, nullptr);
}

TEST(DLL_GetNodeTests, GetNodeWhenIndexIsOutOfRange) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);

    // Act
    Node *node = list->getNode(5);

    // Assert
    ASSERT_EQ(node, nullptr);
}

TEST(DLL_GetNodeTests, GetNodeFromListWithSingleNode) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);

    // Act
    Node *node = list->getNode(0);

    // Assert
    ASSERT_EQ(node->value, 10);
    ASSERT_EQ(node->next, nullptr);
    ASSERT_EQ(node->prev, nullptr);
}

TEST(DLL_GetNodeTests, GetNodeFromListWithMultipleNodes) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    Node *node = list->getNode(1);

    // Assert
    ASSERT_EQ(node->value, 20);
    ASSERT_EQ(node->next->value, 30);
    ASSERT_EQ(node->prev->value, 10);
}

TEST(DLL_SetNodeTests, SetNodeToEmptyList) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList();

    // Act
    bool result = list->setNode(0, 10);

    // Assert
    ASSERT_EQ(result, false);
}

TEST(DLL_SetNodeTests, SetNodeWhenIndexIsOutOfRange) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);

    // Act
    bool result = list->setNode(5, 10);

    // Assert
    ASSERT_EQ(result, false);
}

TEST(DLL_SetNodeTests, SetNodeWhenIndexIsInRange) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->setNode(1, 15);

    // Assert
    ASSERT_EQ(result, true);
    ASSERT_EQ(list->getNode(1)->value, 15);
}

TEST(DLL_InsertTests, InsertNodeWhenIndexIsOutOfRange) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(5, 15);

    // Assert
    ASSERT_EQ(result, false);
}

TEST(DLL_InsertTests, InsertNodeWhenIndexIsZero) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(0, 15);

    // Assert
    ASSERT_EQ(result, true);
    ASSERT_EQ(list->getHead(), 15);
}

TEST(DLL_InsertTests, InsertNodeWhenIndexIsEqualToLength) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    bool result = list->insertNode(3, 15);

    // Assert
    ASSERT_EQ(result, true);
    ASSERT_EQ(list->getTail(), 15);
}

TEST(DLL_InsertTests, InsertNodeWhenIndexIsInRange) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // Act
    bool result = list->insertNode(1, 15);

    // Assert
    ASSERT_EQ(result, true);
    ASSERT_EQ(list->getNode(1)->value, 15);
    ASSERT_EQ(list->getNode(1)->prev->value, 10);
    ASSERT_EQ(list->getNode(1)->next->value, 20);
}

TEST(DLL_DeleteNodeTests, DeleteNodeWhenIndexIsOutOfRange) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(5);

    // Assert
    ASSERT_EQ(list->getHead(), 10);
    ASSERT_EQ(list->getTail(), 30);
    ASSERT_EQ(list->getLength(), 3);
}

TEST(DLL_DeleteNodeTests, DeleteNodeWhenIndexIsZero) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(0);

    // Assert
    ASSERT_EQ(list->getHead(), 20);
    ASSERT_EQ(list->getTail(), 30);
    ASSERT_EQ(list->getLength(), 2);
}

TEST(DLL_DeleteNodeTests, DeleteNodeWhenIndexIsEqualToLengthMinusOne) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);

    // Act
    list->deleteNode(2);

    // Assert
    ASSERT_EQ(list->getHead(), 10);
    ASSERT_EQ(list->getTail(), 20);
    ASSERT_EQ(list->getLength(), 2);
}

TEST(DLL_DeleteNodeTests, DeleteNodeWhenIndexIsInRange) {
    // Arrange
    DoublyLinkedList *list = new DoublyLinkedList(10);
    list->append(20);
    list->append(30);
    list->append(40);

    // Act
    list->deleteNode(1);

    // Assert
    ASSERT_EQ(list->getHead(), 10);
    ASSERT_EQ(list->getTail(), 40);
    ASSERT_EQ(list->getLength(), 3);
}

} // namespace DoublyLinkedListTests
