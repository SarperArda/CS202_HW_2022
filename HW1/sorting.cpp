/*
 * Title: Sorting and Algorithm Efficiency
 * Author: SARPER ARDA BAKIR
 * ID: 21902781
 * Section: 1
 * Assignment: 1
 * This is a source class which includes three sorting implementations, bubble-quick-merge. Also, in this class, there
 * are some methods which can create array random,ascending and descending. Also, performAnalysis() method examines sorting
 * functions.
 */

#include "sorting.h"
using namespace std;

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    bool sorted = false;

    for(int pass = 1;(pass < size) && !sorted;  ++pass){
        sorted = true;
        for(int index = 0; index < size - pass; ++index){
            int nextIndex = index + 1;
            if(arr[index] > arr[nextIndex]){
                swap(arr[index],arr[nextIndex]);
                moveCount = moveCount + 3;
                sorted = false;
            }
            compCount++;
        }

    }
}
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    mergeSortHelper(arr,0,size-1,compCount,moveCount);
}
void mergeSortHelper(int *arr, int first,int last, int &compCount, int &moveCount){
    if(first<last){
        int mid = (first + last)/2;
        mergeSortHelper(arr,first,mid,compCount,moveCount);
        mergeSortHelper(arr,mid+ 1,last,compCount,moveCount);
        merge(arr,first,mid,last,compCount,moveCount);
    }
}
void merge(int *arr, int first,int mid,int last, int &compCount, int &moveCount){
    int* tempArr = new int[last + first + 1];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    for(;(first1 <= last1) && (first2 <= last2); ++index){
        if(arr[first1] < arr[first2]){
            tempArr[index] = arr[first1];
            ++first1;
            moveCount++;
        }
        else {
            tempArr[index] = arr[first2];
            ++first2;
            moveCount++;
        }
        compCount++;
    }
    for (; first1 <= last1; ++first1, ++index) {
        tempArr[index] = arr[first1];
        moveCount++;
    }

    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        tempArr[index] = arr[first2];
        moveCount++;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index) {
        arr[index] = tempArr[index];
        moveCount++;
    }
    delete[] tempArr;
}
void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    quickSortHelper(arr,0,size-1,compCount,moveCount);
}
void quickSortHelper(int *arr, int first, int last, int &compCount, int &moveCount){
    int pivot;
    if(first<last){
        partition(arr,first,last,pivot,compCount,moveCount);
        quickSortHelper(arr,first,pivot - 1,compCount,moveCount);
        quickSortHelper(arr,pivot + 1,last,compCount,moveCount);
    }
}
void partition(int *arr, int first,int last,int& pivot, int &compCount, int &moveCount){
    pivot = arr[first];
    moveCount++;
    int lastS1 = first;
    int firstUnknown = first + 1;
    for (  ; firstUnknown <= last; ++firstUnknown) {
        if (arr[firstUnknown] < pivot) {
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount = moveCount + 3;
        }
        compCount++;
    }
    swap(arr[first], arr[lastS1]);
    moveCount = moveCount + 3;
    pivot = lastS1;
}
void displayArray(const int *arr, const int size){
    if(arr){
        cout << "Array's elements are: ";
        for(int i = 0; i < size; i++){
            cout << arr[i] << setw(5);
        }
        cout << "\n";
    }
    else{
        cout << "Array is empty.\n" ;
    }
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    srand((int) time(NULL));
    for(int i = 0; i < size; i++){
        int random = rand() % (size + 1); // random number can be from 0 to size
        arr1[i] = random;
        arr2[i] = random;
        arr3[i] = random;
    }
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    for(int i = 0; i < size; i++){
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
    }
}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    for(int i = 0; i < size; i++){
        arr1[i] = size - i;
        arr2[i] = size - i;
        arr3[i] = size - i;
    }
}

void performanceAnalysis(){
    int sizes [12]= {4000, 8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000, 40000, 44000, 48000};
    int** randomData = new int* [12];
    int** ascendingData = new int* [12];
    int** descendingData = new int* [12];
    for (int i = 0; i < 12; ++i) {
        randomData[i] = new int [9];
        ascendingData[i] = new int [9];
        descendingData[i] = new int [9];
    }
    randomPerform(randomData,sizes);
    ascendingPerform(ascendingData,sizes);
    descendingPerform(descendingData,sizes);

    cout<<"-----------------Random---------------"<<endl;
    analysisDisplay(randomData,sizes);
    cout<<"-----------------Ascending---------------"<<endl;
    analysisDisplay(ascendingData,sizes);
    cout<<"-----------------Descending---------------"<<endl;
    analysisDisplay(descendingData,sizes);

    for(int i = 0; i < 12;i++){
        delete randomData[i];
        delete ascendingData[i];
        delete descendingData[i];
    }
    delete [] randomData;
    delete [] ascendingData;
    delete [] descendingData;
}
void randomPerform(int**& randomData, int* sizes){
    for(int i = 0; i < 5;i++){
        int moveCount = 0;
        int compCount = 0;
        double duration;
        int* arr1 = new int [sizes[i]];
        int* arr2 = new int [sizes[i]];
        int* arr3 = new int [sizes[i]];
        createRandomArrays(arr1,arr2,arr3,sizes[i]);
        clock_t startTime = clock();
        bubbleSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        randomData[i][0] = duration;
        randomData[i][1] = compCount;
        randomData[i][2] = moveCount;

        moveCount = 0;
        compCount = 0;
        startTime = clock();
        mergeSort(arr2,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        randomData[i][3] = duration;
        randomData[i][4] = compCount;
        randomData[i][5] = moveCount;

        moveCount = 0;
        compCount = 0;
        startTime = clock();
        quickSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        randomData[i][6] = duration;
        randomData[i][7] = compCount;
        randomData[i][8] = moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

    }

}
void ascendingPerform(int**& ascendingData, int* sizes){
    for(int i = 0; i < 5;i++){
        int moveCount = 0;
        int compCount = 0;
        double duration;
        int* arr1 = new int [sizes[i]];
        int* arr2 = new int [sizes[i]];
        int* arr3 = new int [sizes[i]];
        createAscendingArrays(arr1,arr2,arr3,sizes[i]);
        clock_t startTime = clock();
        bubbleSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        ascendingData[i][0] = duration;
        ascendingData[i][1] = compCount;
        ascendingData[i][2] = moveCount;

        moveCount = 0;
        compCount = 0;
        startTime = clock();
        mergeSort(arr2,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        ascendingData[i][3] = duration;
        ascendingData[i][4] = compCount;
        ascendingData[i][5] = moveCount;

        moveCount = 0;
        compCount = 0;
        startTime = clock();
        quickSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        ascendingData[i][6] = duration;
        ascendingData[i][7] = compCount;
        ascendingData[i][8] = moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }
}
void descendingPerform(int**& descendingData, int* sizes){
    for(int i = 0; i < 5;i++){
        int moveCount = 0;
        int compCount = 0;
        double duration;
        int* arr1 = new int [sizes[i]];
        int* arr2 = new int [sizes[i]];
        int* arr3 = new int [sizes[i]];
        createDescendingArrays(arr1,arr2,arr3,sizes[i]);
        clock_t startTime = clock();
        bubbleSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        descendingData[i][0] = duration;
        descendingData[i][1] = compCount;
        descendingData[i][2] = moveCount;

        moveCount = 0;
        compCount = 0;
        startTime = clock();
        mergeSort(arr2,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        descendingData[i][3] = duration;
        descendingData[i][4] = compCount;
        descendingData[i][5] = moveCount;

        moveCount = 0;
        compCount = 0;
        startTime = clock();
        quickSort(arr1,sizes[i],compCount,moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        descendingData[i][6] = duration;
        descendingData[i][7] = compCount;
        descendingData[i][8] = moveCount;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

    }
}
void analysisDisplay(int** data,int* sizes){
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Analysis of Bubble Sort"<<endl;
    cout<<setw(15)<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
    for(int i = 0; i < 5;i++){
        cout<<left<<setw(15)<<sizes[i]<<setw(5)<<data[i][0]<<setw(10)<<"ms"<<setw(15)<<data[i][1]<<setw(15)<<data[i][2]<<endl;
    }
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Analysis of Merge Sort"<<endl;
    cout<<setw(15)<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
    for(int i = 0; i < 5;i++){
        cout<<left<<setw(15)<<sizes[i]<<setw(5)<<data[i][3]<<setw(10)<<"ms"<<setw(15)<<data[i][4]<<setw(15)<<data[i][5]<<endl;
    }
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Analysis of Quick Sort"<<endl;
    cout<<setw(15)<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
    for(int i = 0; i < 5;i++){
        cout<<left<<setw(15)<<sizes[i]<<setw(5)<<data[i][6]<<setw(10)<<"ms"<<setw(15)<<data[i][7]<<setw(15)<<data[i][8]<<endl;
    }
}