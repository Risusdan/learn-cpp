#include "pch.h"
#include "../cpp-dsa/Stack.h"
#include "../cpp-dsa/Stack.cpp"

TEST(Stack_Tests, CreateStack) {
    // Arrange
    Stack* stack = new Stack(9);

    // Act & Assert
    ASSERT_EQ(stack->getTop(), 9);
    ASSERT_EQ(stack->getHeight(), 1);
}

TEST(StackPush_Tests, Push) {
    // Arrange
    Stack* stack = new Stack(9);

    // Act
    stack->push(10);

    // Assert
    ASSERT_EQ(stack->getTop(), 10);
    ASSERT_EQ(stack->getHeight(), 2);
}

TEST(StackPush_Tests, PushInEmptyStack) {
    // Arrange
    Stack* stack = new Stack(1);

    // Act
    stack->pop();
    int temp = stack->pop();

    // Assert
    ASSERT_EQ(temp, INT_MIN);
    ASSERT_EQ(stack->getTop(), INT_MIN);
    ASSERT_EQ(stack->getHeight(), 0);
}

TEST(Stack_PopTests, PopInNonEmptyStack) {
    // Arrange
    Stack* stack = new Stack(1);

    // Act
    stack->push(2);
    stack->push(3);
    stack->push(4);
    int temp = stack->pop();

    // Assert
    ASSERT_EQ(temp, 4);
    ASSERT_EQ(stack->getTop(), 3);
    ASSERT_EQ(stack->getHeight(), 3);
}
