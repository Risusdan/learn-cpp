#include "pch.h"
#include "../cpp-dsa/Queue.h"
#include "../cpp-dsa/Queue.cpp"

TEST(Queue_Tests, CreateQueue) {
    // Arrange
    Queue* queue = new Queue(9);

    // Act & Assert
    ASSERT_EQ(queue->getFirst(), 9);
    ASSERT_EQ(queue->getLast(), 9);
    ASSERT_EQ(queue->getLength(), 1);
}

TEST(Queue_EnqueueTests, Enqueue) {
    // Arrange
    Queue* queue = new Queue(9);

    // Act
    queue->enqueue(10);

    // Assert
    ASSERT_EQ(queue->getFirst(), 9);
    ASSERT_EQ(queue->getLast(), 10);
    ASSERT_EQ(queue->getLength(), 2);
}

TEST(Queue_DequeueTests, DequeueInEmptyQueue) {
    // Arrange
    Queue* queue = new Queue(9);

    // Act
    queue->dequeue();
    int temp = queue->dequeue();

    // Assert
    ASSERT_EQ(temp, INT_MIN);
    ASSERT_EQ(queue->getFirst(), INT_MIN);
    ASSERT_EQ(queue->getLast(), INT_MIN);
    ASSERT_EQ(queue->getLength(), 0);
}

TEST(Queue_DequeueTests, DequeueInNonEmptyQueue) {
    // Arrange
    Queue* queue = new Queue(9);
    queue->enqueue(10);
    queue->enqueue(11);

    // Act
    int temp = queue->dequeue();

    // Assert
    ASSERT_EQ(temp, 9);
    ASSERT_EQ(queue->getFirst(), 10);
    ASSERT_EQ(queue->getLast(), 11);
    ASSERT_EQ(queue->getLength(), 2);
}
