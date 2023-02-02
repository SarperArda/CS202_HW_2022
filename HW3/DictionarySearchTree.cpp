//
// Created by Sarper Arda BAKIR on 3.12.2022.
//
#include "DictionarySearchTree.h"


DictionarySearchTree::DictionarySearchTree( string dictionaryFile ){

}
DictionarySearchTree::~DictionarySearchTree(){
    return;
}
void DictionarySearchTree::insert( string word ){
    return;
}
void DictionarySearchTree::search(string word, int &numComparisons, bool &found) const {
    searchItem(root,word,numComparisons,found);

}
void DictionarySearchTree::searchItem(TreeNode* treeptr, string word, int &numComparisons, bool &found) const{

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

void DictionarySearchTree::search(string queryFile, string outputFile) const {
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
