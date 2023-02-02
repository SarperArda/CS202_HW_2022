/**
* Title: Binary Search Trees
* Author: SARPER ARDA BAKIR
* ID: 21902781
* Section: 1
* Assignment: 2
* Description: This is main cpp */

#include "analysis.h"
#include <iostream>

using namespace std;;
int main() {

    BST tree;
    // insertions

    tree.insert(30);
    tree.insert(40);
    tree.insert(35);
    tree.insert(20);
    tree.insert(50);
    tree.insert(45);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);

    //display height
    cout<<endl<< "BST's Height is : " << tree.getHeight() << endl;

    //deletions
    tree.deleteKey(35);
    tree.deleteKey(40);

    //display median
    cout<<endl<< "BST's Median is : " << tree.medianOfBST() << endl << endl;

    //display values between a and b
    tree.rangeSearch(5,43);

    //height analysis results
    heightAnalysis();

    tree.destroyTree(tree.root);
    return 0;
}
