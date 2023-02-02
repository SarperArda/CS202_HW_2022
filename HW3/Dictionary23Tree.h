//
// Created by Sarper Arda BAKIR on 3.12.2022.
//
/**
    * Title: 23 Trees
    * Author: Sarper Arda Bakır
    * ID: 21902781
    * Section: 1
    * Assignment: 3
    * Description: 23 TREE HEADER
    */
#ifndef HW3_DICTIONARY23TREE_H
#define HW3_DICTIONARY23TREE_H

#include "DictionarySearchTree.h"

class Dictionary23Tree : public DictionarySearchTree{

public:
    struct TreeNode{
        string item;
        TreeNode *leftChildPtr, *midChildPtr, *rightChildPtr;
    };
    TreeNode* root;
    Dictionary23Tree(string dictionaryFile);
    ~Dictionary23Tree() override;
    void insert(string word) override;
    void search(string word, int &numComparisons, bool &found) const override;
    void search(string queryFile, string outputFile) const override;
};
#endif //HW3_DICTIONARY23TREE_H
