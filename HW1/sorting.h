/*
 * Title: Sorting and Algorithm Efficiency
 * Author: SARPER ARDA BAKIR
 * ID: 21902781
 * Section: 1
 * Assignment: 1
 * This is header class of Sorting
 */

#ifndef HW1_SORTING_H
#define HW1_SORTING_H

#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSortHelper(int *arr, int first,int last, int &compCount, int &moveCount);
void merge(int *arr, int first,int mid,int last, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSortHelper(int *arr, int first, int last, int &compCount, int &moveCount);
void partition(int *arr, int first,int last,int& pivot, int &compCount, int &moveCount);
void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
void swap(int& a, int& b);
void performanceAnalysis();
void randomPerform(int**& randomData, int* sizes);
void ascendingPerform(int**& ascendingData, int* sizes);
void descendingPerform(int**& descendingData, int* sizes);
void analysisDisplay(int** data,int* sizes);

#endif //HW1_SORTING_H
