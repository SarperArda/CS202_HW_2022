//
// Created by Sarper Arda BAKIR on 3.12.2022.
//
/**
    * Title: INHERITANCE Trees
    * Author: Sarper Arda Bakır
    * ID: 21902781
    * Section: 1
    * Assignment: 3
    * Description: INHERİTANCE TREE HEADER
    */
#ifndef HW3_DICTIONARYSEARCHTREE_H
#define HW3_DICTIONARYSEARCHTREE_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class DictionarySearchTree {
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
//Constructor that constructs the dictionary from the input file
    DictionarySearchTree( string dictionaryFile );
    //Destructor
    virtual ~DictionarySearchTree();
    //Inserts the given word into the dictionary
    virtual void insert( string word );
    //Searches the given word in the dictionary, and returns the number
    //of comparisons made and whether the word is found or not
    virtual void search( string word, int& numComparisons, bool& found ) const;
    //Searches all words in the query file in the dictionary, and //summarizes the results in the output file
    virtual void search( string queryFile, string outputFile ) const;
    virtual void searchItem(TreeNode* treeptr, string word, int &numComparisons, bool &found) const;


};
#endif //HW3_DICTIONARYSEARCHTREE_H
