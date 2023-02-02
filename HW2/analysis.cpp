/**
* Title: Binary Search Trees
* Author: SARPER ARDA BAKIR
* ID: 21902781
* Section: 1
* Assignment: 2
* Description: This is analysis cpp */

#include <iomanip>
#include "analysis.h"
using namespace std;

/**
 * Global function which checks height of tree step by step by insertions and deletions.
 */

void heightAnalysis(){
    BST tree;
    int size = 30000;
    int* arr = new int[size];
    cout<<endl<<"Part f - Analysis of BST height - part 1"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Tree Size"<<setw(20)<<"Tree Height"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i = 0; i < 29999; i++){
        int random = rand();
        arr[i] = random;
        tree.insert(arr[i]);
        if(i % 1500 == 0 && i != 0){
            cout << left <<setw(20)<< i << tree.getHeight() << endl;
        }
    }

    cout<<endl<<"Part f - Analysis of BST height - part 2"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<setw(20)<<"Tree Size"<<"Tree Height"<<endl;
    cout<<"-----------------------------------------"<<endl;

    for (int i = 0; i < size; i++) {

        int index = rand() % size;
        int temp = arr[index];
        arr[index] = arr[29999-index];
        arr[29999-index] = temp;
    }

    for(int i = 29999; i > 0; i--){
        tree.deleteKey(arr[i]);
        if(i % 1500 == 0){
            cout << left <<setw(20)<< i << tree.getHeight() << endl;
        }
    }
    delete[] arr;
    tree.destroyTree(tree.root);


}
