/**
    * Title: INHERITANCE Trees
    * Author: Sarper Arda Bakır
    * ID: 21902781
    * Section: 1
    * Assignment: 3
    * Description: INHERİTANCE TREE SOURCE CODE
    */
#include "DictionarySearchTree.h"

//
// Created by Sarper Arda BAKIR on 3.12.2022.
//
#include "DictionaryBST.h"

DictionaryBST::DictionaryBST(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {
    root = NULL;
    fstream file;
    file.open(dictionaryFile, ios::in);
    if(file){
        string word;
        while(getline(file,word)){
            insert(word);

        }
    }
    file.close();
}

DictionaryBST::~DictionaryBST() {
    destroyTree(root);
}

void DictionaryBST::destroyTree(TreeNode *& treePtr) {

    if (treePtr != NULL){
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

void DictionaryBST::insert(string word) {
    insertItem(root,word);
}

void DictionaryBST::insertItem(TreeNode *& treePtr, const string &newItem) {
    // Position of insertion found; insert after leaf
    if (treePtr == NULL) {
        treePtr = new TreeNode(newItem, NULL, NULL);
        if (treePtr == NULL)
            return;
    }
    if(newItem == treePtr->item){
        return;
    }
    else if (newItem < treePtr->item)
        insertItem(treePtr->leftChildPtr, newItem);
    else
        insertItem(treePtr->rightChildPtr, newItem);
}

void DictionaryBST::search(string word, int &numComparisons, bool &found) const {
    searchItem(root,word,numComparisons,found);

}
void DictionaryBST::searchItem(TreeNode* treeptr, string word, int &numComparisons, bool &found) const{

    while(treeptr){
        if(treeptr->item == word){
            found = true;
            numComparisons++;
            break;
        }
        if(treeptr->item < word && treeptr->rightChildPtr == NULL){
            found = false;
            numComparisons++;
            break;
        }
        if(treeptr->item > word && treeptr->leftChildPtr == NULL){
            found = false;
            numComparisons++;
            break;
        }
        if(treeptr->item < word){
            numComparisons++;
            treeptr = treeptr->rightChildPtr;
        }
        if(treeptr->item > word){
            found = false;
            numComparisons++;
            treeptr = treeptr->leftChildPtr;
        }
    }

}
void DictionaryBST::search(string queryFile, string outputFile) const {

    fstream file;
    fstream out;
    file.open(queryFile, ios::in);
    out.open(outputFile,ios::out);
    if(file){
        string word;
        int i = 0;
        int sum = 0;
        int max = 0;
        while(getline(file,word)){
            i++;
            int comp = 0;
            bool found = false;
            int result = 0;
            search(word, comp, found);
            if(found){
                result = 1;
            }
            sum += comp;
            if(max < comp){
                max = comp;
            }
            out <<left<<setw(15)<< word + " " <<setw(5)<< result << " " << comp << endl;
        }
        double average = (double) sum / i;
        out << "# of queries: " << i << endl;
        out << "Maximum # of comparisons: " << max << endl;
        out << "Average # of comparisons: " << average << endl;
    }
    file.close();
    out.close();

}

/**
Inheritance methods didn't work. Therefore I couldn't use them. I didn't understand.
void DictionaryBST::search(string word, int &numComparisons, bool &found) const {
    searchItem(root,word,numComparisons,found);

}
void DictionaryBST::searchItem(TreeNode* treeptr, string word, int &numComparisons, bool &found) const{
    DictionarySearchTree::searchItem(reinterpret_cast<DictionarySearchTree::TreeNode *>(treeptr),  word, numComparisons, found);
}

void DictionaryBST::search(string queryFile, string outputFile) const {
    DictionarySearchTree::search(queryFile,outputFile);
}
 */
