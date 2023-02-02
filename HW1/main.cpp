/*
 * Title: Sorting and Algorithm Efficiency
 * Author: SARPER ARDA BAKIR
 * ID: 21902781
 * Section: 1
 * Assignment: 1
 * This is a main class which displays arrays as sorted.
 */

#include <iostream>
#include "sorting.h"
using namespace std;
int main() {
    cout<<endl<<"-----------------Testing Implementations---------------"<<endl;

    int compCount = 0;
    int moveCount = 0;
    int arrayBubble[16] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,33, 26};
    int arrayQuick[16] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,33, 26};
    int arrayMerge[16] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,33, 26};


    cout<<"-----------------Bubble Sort---------------"<<endl;
    displayArray(arrayBubble,16);
    bubbleSort(arrayBubble,16,compCount,moveCount);
    displayArray(arrayBubble,16);
    cout<<"Number of Comparison: " << compCount << endl;
    cout<<"Number of Move: " << moveCount << endl;

    cout<<"-----------------Quick Sort---------------"<<endl;
    compCount = 0;
    moveCount = 0;
    displayArray(arrayQuick,16);
    quickSort(arrayQuick,16,compCount,moveCount);
    displayArray(arrayQuick,16);
    cout<<"Number of Comparison: " << compCount << endl;
    cout<<"Number of Move: " << moveCount << endl;

    cout<<"-----------------Merge Sort---------------"<<endl;
    compCount = 0;
    moveCount = 0;
    displayArray(arrayMerge,16);
    mergeSort(arrayMerge,16,compCount,moveCount);
    displayArray(arrayMerge,16);
    cout<<"Number of Comparison: " << compCount << endl;
    cout<<"Number of Move: " << moveCount << endl;
    cout<< endl;

    performanceAnalysis();



}