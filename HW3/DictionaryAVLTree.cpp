/**
    * Title: AVL Trees
    * Author: Sarper Arda Bakır
    * ID: 21902781
    * Section: 1
    * Assignment: 3
    * Description: AVL TREE SOURCE CODE
    */
#include "DictionarySearchTree.h"
#include "DictionaryAVLTree.h"
//
// Created by Sarper Arda BAKIR on 3.12.2022.
//
DictionaryAVLTree::DictionaryAVLTree(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {
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
DictionaryAVLTree::~DictionaryAVLTree() {
    destroyAll(root);
}

void DictionaryAVLTree::insert(string word) {
    insertItem(root,word);
}
void DictionaryAVLTree::insertItem(TreeNode *& treePtr,const string& newItem){
    if (treePtr == NULL) {
        treePtr = new TreeNode(newItem, NULL, NULL);
        if (treePtr == NULL)
            return;
    }
   if(treePtr->item > newItem){
       insertItem(treePtr->leftChildPtr,newItem);
       if(getHeight(treePtr->leftChildPtr)- getHeight(treePtr->rightChildPtr) > 1){
           if(treePtr->leftChildPtr->item > newItem){
               singleRightRotation(treePtr);
           }
           else{
               singleLeftRotation(treePtr->leftChildPtr);
               singleRightRotation(treePtr);
           }
       }
   }
   if(treePtr->item < newItem){
       insertItem(treePtr->rightChildPtr,newItem);
       if(getHeight(treePtr->leftChildPtr)- getHeight(treePtr->rightChildPtr) < -1){
           if(treePtr->rightChildPtr->item < newItem || treePtr->rightChildPtr->item  == newItem ){
               singleLeftRotation(treePtr);
           }
           else{
               singleRightRotation(treePtr->rightChildPtr);
               singleLeftRotation(treePtr);
           }
       }
   }
}



int DictionaryAVLTree::getHeight(TreeNode* treeptr){
    if(!treeptr){
        return 0;
    }
    return 1 + max(getHeight(treeptr->leftChildPtr),getHeight(treeptr->rightChildPtr));

}
void DictionaryAVLTree::search(string word, int &numComparisons, bool &found) const {
    searchItem(root,word,numComparisons,found);

}
void DictionaryAVLTree::searchItem(TreeNode* treeptr, string word, int &numComparisons, bool &found) const{
    DictionarySearchTree::searchItem(reinterpret_cast<DictionarySearchTree::TreeNode *>(treeptr),  word, numComparisons, found);
}

void DictionaryAVLTree::search(string queryFile, string outputFile) const {
    DictionarySearchTree::search(queryFile,outputFile);
}

void DictionaryAVLTree::destroyAll(DictionaryAVLTree::TreeNode *&ptr) {
    if(ptr){
        destroyAll(ptr->leftChildPtr);
        destroyAll(ptr->rightChildPtr);
        delete ptr;
        ptr = NULL;
    }
}

void DictionaryAVLTree::singleLeftRotation(TreeNode*& ptr){
    TreeNode* temp = ptr;
    ptr = ptr->rightChildPtr;
    temp->rightChildPtr = ptr->leftChildPtr;
    ptr->leftChildPtr = temp;
    temp->height = 1 + max(getHeight(temp->leftChildPtr), getHeight(temp->rightChildPtr));
    ptr->height = 1 + max(getHeight(ptr->leftChildPtr), getHeight(ptr->rightChildPtr));
}
void DictionaryAVLTree::singleRightRotation(TreeNode*& ptr){
    TreeNode* temp = ptr;
    ptr = ptr->leftChildPtr;
    temp->leftChildPtr = ptr->rightChildPtr;
    ptr->rightChildPtr = temp;
    temp->height = 1 + max(getHeight(temp->leftChildPtr), getHeight(temp->rightChildPtr));
    ptr->height = 1 + max(getHeight(ptr->leftChildPtr), getHeight(ptr->rightChildPtr));
}

/**
 inheritance codes work therefore I didn't use these methods
void DictionaryAVLTree::search(string word, int &numComparisons, bool &found) const {
    searchItem(root,word,numComparisons,found);

}
void DictionaryAVLTree::searchItem(TreeNode* treeptr, string word, int &numComparisons, bool &found) const{

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
void DictionaryAVLTree::search(string queryFile, string outputFile) const {

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
 */
