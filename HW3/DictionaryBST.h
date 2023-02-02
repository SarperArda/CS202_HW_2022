//
// Created by Sarper Arda BAKIR on 3.12.2022.
//
/**
    * Title: BST Trees
    * Author: Sarper Arda Bakır
    * ID: 21902781
    * Section: 1
    * Assignment: 3
    * Description: BST HEADER
    */
#ifndef HW3_DICTIONARYBST_H
#define HW3_DICTIONARYBST_H

#include "DictionarySearchTree.h"

class DictionaryBST : public DictionarySearchTree{


public:
    struct TreeNode{
        int height;
        string item;       // data portion
        TreeNode *leftChildPtr;  // pointer to left child
        TreeNode *rightChildPtr; // pointer to right child
        TreeNode();
        TreeNode( const string & nodeItem,TreeNode *left = NULL,TreeNode *right = NULL):item(nodeItem),leftChildPtr(left),rightChildPtr(right),height(1){}
    };
    TreeNode* root;
    DictionaryBST( string dictionaryFile);
    ~DictionaryBST() override;
    void destroyTree(TreeNode *& treePtr);
    void insert(string word) override;
    void insertItem(TreeNode *& treePtr, const string & newItem);
    void searchItem(TreeNode* root, string word, int &numComparisons, bool &found) const;
    void search(string word, int &numComparisons, bool &found) const override;
    void search(string queryFile, string outputFile) const override;

};
#endif //HW3_DICTIONARYBST_H
