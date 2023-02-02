//
// Created by Sarper Arda BAKIR on 3.12.2022.
//
/**
    * Title: AVL Trees
    * Author: Sarper Arda Bakır
    * ID: 21902781
    * Section: 1
    * Assignment: 3
    * Description: AVL TREE HEADER
    */
#ifndef HW3_DICTIONARYAVLTREE_H
#define HW3_DICTIONARYAVLTREE_H

#include "DictionarySearchTree.h"

class DictionaryAVLTree : public DictionarySearchTree{

public:
    struct TreeNode{
        string item;       // data portion
        int height;
        TreeNode *leftChildPtr;  // pointer to left child
        TreeNode *rightChildPtr; // pointer to right child
        TreeNode();
        TreeNode( const string & nodeItem,TreeNode *left = NULL,TreeNode *right = NULL):item(nodeItem),leftChildPtr(left),rightChildPtr(right),height(1){}
    };
    TreeNode* root;
    DictionaryAVLTree(string dictionaryFile);
    ~DictionaryAVLTree() override;
    void destroyAll(TreeNode*& ptr);
    void insert(string word) override;
    void insertItem(TreeNode *& treePtr,const string& newItem);
    void search(string word, int &numComparisons, bool &found) const override;
    void searchItem(TreeNode* root, string word, int &numComparisons, bool &found) const;
    void search(string queryFile, string outputFile) const override;
    int getHeight(TreeNode* root);
    void singleLeftRotation(TreeNode*& ptr);
    void singleRightRotation(TreeNode*& ptr);
};
#endif //HW3_DICTIONARYAVLTREE_H
