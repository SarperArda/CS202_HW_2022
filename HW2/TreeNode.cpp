
/**
* Title: Binary Search Trees
* Author: SARPER ARDA BAKIR
* ID: 21902781
* Section: 1
* Assignment: 2
* Description: This is node cpp */

#include "TreeNode.h"

//Empty constructor
TreeNode::TreeNode(){}
// constructor
TreeNode::TreeNode(const int& nodeItem,TreeNode *left,TreeNode *right){
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}


