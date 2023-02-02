/*
 * Title: Balanced Search Trees
 * Author: Sarper Arda Bakır
 * ID: 21902781
 * Section: 1
 * Assignment: 4
 * Description: This is main class
 */
#include <iostream>
#include "RBTree.h"
int main(int argc, char** argv) {
   /**
    if(argc != 3){
        cout << "Enter your command line like this ./converter <inputFileName> <outputFileName " << endl;
        return 1;
    }
    */
    RBTree* rb = new RBTree(argv[1],argv[2]);
    return 0;
}
