/*
 * Title: Balanced Search Trees
 * Author: Sarper Arda Bakır
 * ID: 21902781
 * Section: 1
 * Assignment: 4
 * Description: This is cpp class
 */
#include "RBTree.h"
RBTree::RBTree(string input,string outputFile){
  filename = input;
  root = NULL;
  fstream file;
  file.open(filename, ios::in);
  string line;
  if(getline(file,line)){
      stringstream ss;
      string size;
      string value;
      ss << line;
      ss >> size;
      ss >> value;
      TreeSize = stoi(size);
      int rootValue = stoi(value);
      createNode(rootValue,root);
      transform(root,Ptr234);
      Ptr234->index = 0;
      checkIndex = 0;
      total = 1;
      index(Ptr234);
      string output = outputFile;
      fstream out;
      out.open(output,ios::out);
      outputFormat <<left<<setw(5)<< total << " " << Ptr234->index << endl;
      write234Tree(Ptr234);
      out << outputFormat.str();
      out.close();



  }

}
void RBTree::createNode(int value,RBNode*& ptr){
    fstream file;
    file.open(filename, ios::in);
    string line;
    getline(file,line);
    for (;getline(file,line);){
        stringstream ss;
        ss << line;
        string first;
        ss >> first;
        string left;
        ss >> left;
        string right;
        ss >> right;
        string color;
        ss >> color;
        if(value == stoi(first)){
            RBNode* temp = new RBNode(stoi(first), stoi(color));
            ptr = temp;
            createNode(stoi(left),ptr->left);
            createNode(stoi(right),ptr->right);
            return;
        }
    }
}

void RBTree::transform(RBNode* ptr,Node*& outPtr){
    if(!ptr) {
        return;
    }

    outPtr = new Node(-1,-1,-1);
    outPtr->leftChildPtr = new Node(-1,-1,-1);
    outPtr->lMidChildPtr = new Node(-1,-1,-1);
    outPtr->rMidChildPtr = new Node(-1,-1,-1);
    outPtr->rightChildPtr = new Node(-1,-1,-1);
    if(ptr->color == 1 && ptr->right && ptr->left){
        if(ptr->left->color == 0 && ptr->right->color == 0){

            outPtr->smallItem = ptr->left->value;
            outPtr->middleItem = ptr->value;
            outPtr->largeItem = ptr->right->value;

            transform(ptr->left->left,outPtr->leftChildPtr);
            transform(ptr->left->right,outPtr->lMidChildPtr);
            transform(ptr->right->left,outPtr->rMidChildPtr);
            transform(ptr->right->right,outPtr->rightChildPtr);
            return;
        }
        if(ptr->left->color == 0 && ptr->right->color != 0){

            outPtr->smallItem = ptr->left->value;
            outPtr->middleItem = ptr->value;
            outPtr->largeItem = -1;

            transform(ptr->left->left,outPtr->leftChildPtr);
            transform(ptr->left->right,outPtr->lMidChildPtr);
            transform(ptr->right,outPtr->rMidChildPtr);
            return;
        }
        if(ptr->left->color != 0 && ptr->right->color == 0){

            outPtr->smallItem = ptr->value;
            outPtr->middleItem = ptr->right->value;
            outPtr->largeItem = -1;

            transform(ptr->left,outPtr->leftChildPtr);
            transform(ptr->right->left,outPtr->lMidChildPtr);
            transform(ptr->right->right,outPtr->rMidChildPtr);
            return;
        }
        if(ptr->left->color != 0 && ptr->right->color != 0){

            outPtr->smallItem = ptr->value;
            outPtr->middleItem = -1;
            outPtr->largeItem = -1;


            transform(ptr->left,outPtr->leftChildPtr);
            transform(ptr->right,outPtr->lMidChildPtr);
            return;
        }
    }

    if(ptr->color == 1 && ptr->right && ptr->left == NULL){
        if( ptr->right->color == 0){

            outPtr->smallItem = ptr->value;
            outPtr->middleItem = ptr->right->value;
            outPtr->largeItem = -1;

            transform(ptr->right->left,outPtr->lMidChildPtr);
            transform(ptr->right->right,outPtr->rMidChildPtr);
            return;
        }
        if( ptr->right->color == 1){

            outPtr->smallItem = ptr->value;
            outPtr->middleItem = -1;
            outPtr->largeItem = -1;

            transform(ptr->right,outPtr->lMidChildPtr);
            return;
        }

    }
    if(ptr->color == 1 &&  ptr->left && ptr->right == NULL){
        if( ptr->left->color == 0){
           outPtr->smallItem = ptr->left->value;
           outPtr->middleItem = ptr->value;
           outPtr->largeItem = -1;

            transform(ptr->left->left,outPtr->leftChildPtr);
            transform(ptr->left->right,outPtr->lMidChildPtr);
            return;
        }
        if( ptr->left->color == 1){
            outPtr->smallItem = ptr->value;
            outPtr->middleItem = -1;
            outPtr->largeItem = -1;

            transform(ptr->left,outPtr->leftChildPtr);
            return;
        }
    }
    if(ptr->color == 1 &&  ptr->left == NULL && ptr->right == NULL){
        outPtr->smallItem = ptr->value;
        return;
    }

}

void RBTree::write234Tree(Node* ptr){

    if(ptr && ptr->smallItem != -1){
        outputFormat << left<<setw(5)<< ptr->index << " " <<setw(5)<< ptr->smallItem << " " <<setw(5)<< ptr->middleItem << " " << setw(5)<<ptr->largeItem << " " <<
        setw(5)<< ptr->leftChildPtr->index << " " <<setw(5)<< ptr->lMidChildPtr->index << " " <<setw(5)<< ptr->rMidChildPtr->index << " "
        <<setw(5)<< ptr->rightChildPtr->index << endl;
        write234Tree(ptr->leftChildPtr);
        write234Tree(ptr->lMidChildPtr);
        write234Tree(ptr->rMidChildPtr);
        write234Tree(ptr->rightChildPtr);
    }


}
void RBTree::index(Node* ptr){
    if(ptr && ptr->smallItem != -1) {
        int m = ptr->index;
        int f = checkIndex;
        if (ptr->leftChildPtr->smallItem != -1) {
            f++;
            total++;
            ptr->leftChildPtr->index = m + f;
        }
        if (ptr->lMidChildPtr->smallItem != -1) {
            f++;
            total++;
            ptr->lMidChildPtr->index = m + f;
        }
        if (ptr->rMidChildPtr->smallItem != -1) {
            f++;
            total++;
            ptr->rMidChildPtr->index = m + f;
        }
        if (ptr->rightChildPtr->smallItem != -1) {
            f++;
            total++;
            ptr->rightChildPtr->index = m + f;
        }
        checkIndex = f - 1;
        if (f == 0) {
            return;
        }
        if(f == 1){
            index(ptr->leftChildPtr);
        }
        if(f == 2){
            index(ptr->leftChildPtr);
            index(ptr->lMidChildPtr);
        }
        if(f == 3){
            index(ptr->leftChildPtr);
            index(ptr->lMidChildPtr);
            index(ptr->rMidChildPtr);
        }
        if(f == 4){
            index(ptr->leftChildPtr);
            index(ptr->lMidChildPtr);
            index(ptr->rMidChildPtr);
            index(ptr->rightChildPtr);
        }

    }
}
