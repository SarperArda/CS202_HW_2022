#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "DictionarySearchTree.h"
#include "DictionaryBST.h"
#include "DictionaryAVLTree.h"
#include "Dictionary23Tree.h"

int main() {
    DictionarySearchTree* myTrees[ 3 ];
    myTrees[ 0 ] = new DictionaryBST( "dictionary.txt" );
    myTrees[ 1 ] = new DictionaryAVLTree( "dictionary.txt" );
    myTrees[ 2 ] = new Dictionary23Tree( "dictionary.txt" );
    string outFiles[ 3 ] = { "outBST.txt", "outAVLTree.txt", "out23Tree.txt" };
    int i;
    for ( i = 0; i < 3; i++ ) {
        myTrees[ i ]->search( "query.txt", outFiles[ i ] );
    }
    for ( i = 0; i < 3; i++ ) {
        delete myTrees[ i ];
    }
    return 0;
}
