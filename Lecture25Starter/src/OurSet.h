// OurSet.h
// Header file for our Set of ints Class

#pragma once

#include <ostream>
#include "treenode.h"
using namespace std;

class OurSet {
public:
    // constructor
    OurSet();

    // destructor
    ~OurSet();

    // put value into set
    void add(string value);

    // remove value from set
    void remove(string value);

    // check if set contains the value
    bool contains(string value);

    // removes all elements from the set
    void clear();

    // return the number of elements in the array
    int size();

    // true if zero elements
    bool isEmpty();

    void printSetContents();

private:
    /* FILL ME IN */
    TreeNode* root;
    int numItems;
    void freeTree(TreeNode* tree);
    void inorderPrintTree(treeNode* tree);
    bool containsHelper(string value, TreeNode* node);
    void addHelper(string value, TreeNode*& node);

    void removeHelper(TreeNode*& node, string value);
    string removeLargestFrom(TreeNode*& root);
    void performDeletion(TreeNode*& toRemove);
};
