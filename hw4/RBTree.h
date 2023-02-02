/*
 * Title: Balanced Search Trees
 * Author: Sarper Arda Bakır
 * ID: 21902781
 * Section: 1
 * Assignment: 4
 * Description: This is header class
 */

#ifndef HW4_RBTREE_H
#define HW4_RBTREE_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
class RBTree{

public:
    struct RBNode{
        int color;
        int value;
        RBNode* left;
        RBNode* right;
        RBNode();
        RBNode( const int & item,const int& colour,RBNode *leftPtr = NULL,RBNode *rightPtr = NULL):value(item),left(leftPtr),right(rightPtr),color(colour){}
    };
    struct Node{
        int index;
        int smallItem, middleItem, largeItem;

        Node *leftChildPtr, *lMidChildPtr;
        Node *rMidChildPtr, *rightChildPtr;
        Node();
        Node( const int & small, const int & middle, const int & large,
              Node *leftChildPtr = NULL,Node *lMidChildPtr = NULL,Node *rMidChildPtr = NULL,Node *rightChildPtr = NULL):
              smallItem(small),middleItem(middle),largeItem(large),index(-1),
              leftChildPtr(leftChildPtr),lMidChildPtr(lMidChildPtr),rMidChildPtr(rMidChildPtr),rightChildPtr(rightChildPtr){}
    };
    RBNode* root;
    int checkIndex;
    int total;
    string filename;
    int TreeSize;
    Node* Ptr234;
    stringstream outputFormat;
    RBTree(string input,string output);
    void createNode(int value, RBNode*& ptr);
    void transform(RBNode* ptr,Node*& outPtr);
    void write234Tree(Node* ptr);
    void index(Node* ptr);
};
#endif //HW4_RBTREE_H
