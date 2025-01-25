#include "pch.h"
#include "../cpp-dsa/Tree.h"
#include "../cpp-dsa/Tree.cpp"

/*
 *    47
 *  /    \
 * 21     76
 * / \    / \
 * 18 27 52 82
 */
TEST(Tree_InsertTests, Insert) {
    // Arrange
    BinarySearchTree* bst = new BinarySearchTree();

    // Act
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(52);
    bst->insert(82);
    bst->insert(27);

    // Assert
    ASSERT_EQ(bst->root->value, 47);
    ASSERT_EQ(bst->root->left->value, 21);
    ASSERT_EQ(bst->root->right->value, 76);
    ASSERT_EQ(bst->root->left->left->value, 18);
    ASSERT_EQ(bst->root->left->right->value, 27);
    ASSERT_EQ(bst->root->right->left->value, 52);
    ASSERT_EQ(bst->root->right->right->value, 82);
}

/*
 *    47
 *  /    \
 * 21     76
 * / \    / \
 * 18 27 52 82
 */
TEST(Tree_ContainsTests, Contains) {
    // Arrange
    BinarySearchTree* bst = new BinarySearchTree();

    // Act
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(52);
    bst->insert(82);
    bst->insert(27);

    // Assert
    ASSERT_TRUE(bst->contains(52));
    ASSERT_FALSE(bst->contains(100));
}

TEST(Tree_ContainsTests, ContainsInEmptyTree) {
    // Arrange
    BinarySearchTree* bst = new BinarySearchTree();

    // Act
    ASSERT_FALSE(bst->contains(100));
}
