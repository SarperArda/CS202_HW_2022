/**
* Title: Binary Search Trees
* Author: SARPER ARDA BAKIR
* ID: 21902781
* Section: 1
* Assignment: 2
* Description: This is BST cpp. Many of codes is taken from slides */

#include "TreeNode.h"
#include "BST.h"

using namespace std;

// Default constructor
/**
 * These are constructors
 * taken by slides
 */
BST::BST() : root(NULL) {

}
// Constructor
BST::BST(const int& rootItem) {
    root = new TreeNode(rootItem, NULL, NULL);
}

BST::BST(const int& rootItem,BST& leftTree, BST& rightTree) {
    root = new TreeNode(rootItem, NULL, NULL);
    attachLeftSubtree(leftTree);
    attachRightSubtree(rightTree);
}

void BST::attachLeftSubtree(BST& leftTree) {
    // Assertion: nonempty tree; no left child
    if (!isEmpty() && (root->leftChildPtr == NULL)) {
        root->leftChildPtr = leftTree.root;
        leftTree.root = NULL;
    }
}

void BST::attachRightSubtree(BST& rightTree) {
    if (!isEmpty() && (root->rightChildPtr == NULL)) {
        root->rightChildPtr = rightTree.root;
        rightTree.root = NULL;
    }
}
// Copy constructor
BST::BST(const BST& tree) {
    copyTree(tree.root, root);
}


// Uses preorder traversal for the copy operation
// (Visits first the node and then the left and right children)
void BST::copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const {

    if (treePtr != NULL) {		// copy node
        newTreePtr = new TreeNode(treePtr->item, NULL, NULL);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
    else
        newTreePtr = NULL;	// copy empty tree
}

// Destructor
BST::~BST() {
    destroyTree(root);
}

bool BST::isEmpty() const {
    if (root){
        return false;
    }
    return true;
}

// Uses postorder traversal for the destroy operation
// (Visits first the left and right children and then the node)
void BST::destroyTree(TreeNode *& treePtr) {

    if (treePtr != NULL){
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}
/*
 * Insert method is arranged to hw2
 */
void BST::insert(int key){
    insertItem(root,key);
}
// taken from slides
void BST::insertItem(TreeNode *& treePtr,const int& newItem) {

    // Position of insertion found; insert after leaf
    if (treePtr == NULL) {
        treePtr = new TreeNode(newItem, NULL, NULL);
        if (treePtr == NULL)
            cout<<"TreeException: insert failed";
    }
        // Else search for the insertion position
    else if (newItem < treePtr->item)
        insertItem(treePtr->leftChildPtr, newItem);
    else
        insertItem(treePtr->rightChildPtr, newItem);
}
/*
 * Delete method is arranged to hw2
 */
void BST::deleteKey(int key){
    deleteItem(root,key);
}
// taken from slides
void BST::deleteItem(TreeNode * &treePtr, int searchKey) {

    if (!treePtr) {
        return;
    }

    else if (searchKey == treePtr->item)
        deleteNodeItem(treePtr);

        // Else search for the deletion position
    else if (searchKey < treePtr->item)
        deleteItem(treePtr->leftChildPtr, searchKey);
    else
        deleteItem(treePtr->rightChildPtr, searchKey);
}
void BST::deleteNodeItem(TreeNode * &nodePtr) {
    TreeNode *delPtr;
    int replacementItem;


    // (1)  Test for a leaf
    if ( (nodePtr->leftChildPtr == NULL) &&
         (nodePtr->rightChildPtr == NULL) ) {
        delete nodePtr;
        nodePtr = NULL;
    }


        // (2)  Test for no left child
    else if (nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }

        // (3)  Test for no right child
    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete  delPtr  ;
    }


        // (4)  There are two children:
        //      Retrieve and delete the inorder successor
    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }

}
void BST::processLeftmost(TreeNode *&nodePtr,int& treeItem){

    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->item;
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, treeItem);
}
/**
 * Inorder Traversal Method. It is arranged by Inorder method in slides. It takes also arr and integer value
 * and return tree's sorted array and array's length.
 * @param node
 * @param arr
 * @param i
 */
void BST:: inorderTraversal(TreeNode* node, int*& arr, int& i){
    if(node == NULL){
        return;
    }
    inorderTraversal(node->leftChildPtr,arr, i);
    arr[i++] = node->item;
    inorderTraversal(node->rightChildPtr,arr, i);
}
/**
 * Height method
 * @return
 */
int BST::getHeight(){
    return getHeightHelper( root );
}
/**
 * Helper Height method
 * @return
 */
int BST::getHeightHelper(TreeNode *&root){
    if(!root){
        return 0;
    }
    return 1+ max(getHeightHelper(root->rightChildPtr),getHeightHelper(root->leftChildPtr));
}
/**
 * This method finds the median of tree. It creates sorted array of tree by inordertraversal. After finds median of
 * sorted arrays and return it.
 * @return
 */
 double BST::medianOfBST(){
    int length = 0;
    int* inorderTree = new int;
    inorderTraversal(root,inorderTree,length);
    if(!inorderTree){
        return 0;
    }
    if(length % 2 == 0){
        double m =  (double) (inorderTree[length/2 - 1] + inorderTree[length/2 ])/2;
        delete[] inorderTree;
        return m;
    }
     double m = (double) inorderTree[((length - 1)/2 - 1) + 1];
     delete[] inorderTree;
     return m;
}
/**
 * This method display values from tree between a and b. It creates sorted array of tree by inordertraversal. After
 * values between a and b.
 * @param a
 * @param b
 */
void BST::rangeSearch(int a, int b){
    int length = 0;
    int* inorderTree = new int;
    inorderTraversal(root,inorderTree,length);
    int indexA = 0;
    int indexB = 0;
    for(int i = 0; i < length; i++){
        if(inorderTree[i] == a){
            indexA = i;
        }
        if(inorderTree[i] < a){
            indexA = i + 1;
        }
        if(inorderTree[i] == b){
            indexB = i + 1;
            break;
        }
        if(inorderTree[i] >= b){
            indexB = i;
            break;
        }
    }
    if(indexA > indexB){
        cout<< "Unvalid condition" << endl;
        return;
    }

    cout<< "Range between "<< a << " and " << b << " : ";
    for(int m = indexA; m < indexB; m++){
        cout<<inorderTree[m]<< " ";
    }
    cout<<endl;
    delete[] inorderTree;
}

