
/**
* Title: Binary Search Trees
* Author: SARPER ARDA BAKIR
* ID: 21902781
* Section: 1
* Assignment: 2
* Description: This is node header */
#ifndef HW2_TREENODE_H
#define HW2_TREENODE_H
#include <iostream>

class TreeNode {            // node in the tree
private:
    int item;       // data portion
    TreeNode *leftChildPtr;  // pointer to left child
    TreeNode *rightChildPtr; // pointer to right child
    TreeNode();
    TreeNode(const int& nodeItem,TreeNode *left = NULL,TreeNode *right = NULL);
    friend class BST;

};
#endif //HW2_TREENODE_H
