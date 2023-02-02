
/**
* Title: Binary Search Trees
* Author: SARPER ARDA BAKIR
* ID: 21902781
* Section: 1
* Assignment: 2
* Description: This is BST header */

#include "TreeNode.h"
#include <iostream>


class BST{
public:
    TreeNode * root;

    BST();
    BST(const int& rootItem);
    BST(const int& rootItem,BST& leftTree, BST& rightTree);
    BST(const BST& tree);
    ~BST();
    bool isEmpty() const;

    void attachLeftSubtree(BST& leftTree);
    void attachRightSubtree(BST& rightTree);
    BST& operator=(const BST& rhs);
    int getHeight();
    void rangeSearch(int a, int b);
    void insert(int key);
    void deleteKey(int key);
    double medianOfBST();
    void destroyTree(TreeNode *& treePtr);
    void copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const;

    void inorderTraversal(TreeNode* node, int*& arr, int& i);
    void insertItem(TreeNode * &treePtr,const int& item);
    void deleteItem(TreeNode * &treePtr, int searchKey);
    void deleteNodeItem(TreeNode * &nodePtr);
    void processLeftmost(TreeNode * &nodePtr, int& item);
    int getHeightHelper(TreeNode * &root);

};
#ifndef HW2_BST_H
#define HW2_BST_H

#endif //HW2_BST_H
