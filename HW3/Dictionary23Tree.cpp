//
// Created by Sarper Arda BAKIR on 3.12.2022.
//
/**
    * Title: 23 Trees
    * Author: Sarper Arda Bakır
    * ID: 21902781
    * Section: 1
    * Assignment: 3
    * Description: 23 TREE SOURCE CODE
    * I couldn't do the search and insert methods.
    */
#include "DictionarySearchTree.h"

#include "Dictionary23Tree.h"
Dictionary23Tree::Dictionary23Tree(string dictionaryFile) : DictionarySearchTree(dictionaryFile) {
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
Dictionary23Tree::~Dictionary23Tree() {
    return;
}

void Dictionary23Tree::insert(string word) {
    DictionarySearchTree::insert(word);
}

void Dictionary23Tree::search(string word, int &numComparisons, bool &found) const {
    DictionarySearchTree::search(word, numComparisons, found);
}

void Dictionary23Tree::search(string queryFile, string outputFile) const {
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