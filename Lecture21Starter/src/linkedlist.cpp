/*************************************************
 * File: LinkedLists.cpp
 *
 * Lots of fucntions that show off the many different ways
 * to do linked list operations!
 */

#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

/* Given a linked list, returns the length of that list. */
int lengthOf(Node* list) {
    /* TODO: Implement this function! */
    int numNodes = 0;
    while (list != nullptr) {
        numNodes++;
        list = list->next;
    }
    return numNodes;
}

/* Prints the contents of a linked list, in order. */
void printList(Node* list) {
    /* TODO: Implement this function! */
    while (list != nullptr) {
        cout << list->data << endl;
        list = list->next;
    }
}

/* Frees all the memory used by a linked list. */
void freeList(Node* list) {
    /* TODO: Implement this function! */
    while (list != nullptr) {
        Node* next = list->next;
        delete list;
        list = next;
    }

}

/* Reads a linked list from the user one element at a time, stopping when
 * the user enters an empty list. This returns the list, constructed in
 * reverse order.
 */
Node* readList() {
    Node* result = nullptr;
    while (true) {
        string line = getLine("Next item: ");
        if (line == "") break;

        Node* newNode = new Node;
        newNode->data = line;

        newNode->next = result;
        result = newNode;
    }
    return result;
}

/* Given a linked list, returns the length of that list. Operates recursively. */
int lengthOfRec(Node* list) {
    /* TODO: Implement this function! */
    return 0;
}

/* Prints the contents of a linked list, in order. Operates recursively. */
void printListRec(Node* list) {
    /* TODO: Implement this function! */
}

/* Frees all the memory used by a linked list. Operates recursively. */
void freeListRec(Node* list) {
    /* TODO: Implement this function! */
    if (list == nullptr) {
        return;
    } else {
        freeListRec(list->next);
        delete list;
    }
}

/* Question to ponder: Why do we take this list parameter by reference? */
void prependTo(Node*& list, string data) {
    /* TODO: Implement this function! */
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = list;
    
    list = newNode;
}

/* Appends to a linked list represented as a pair of a head and tail pointer. */
void appendTo(Node*& list, string data) {
    /* TODO: Implement this function! */
    /* Step 1: Create the new node with specified data and nullptr for next pointer. */
    Node* newNode = new Node(data, nullptr);

    /* Step 2: Find the node at the end of the current list. */
    Node* end = list;
    while (end != nullptr && end->next != nullptr) {
        end = end->next;
    }

    /* Step 3: Complete the insertion. Need special case for inserting at end of empty list. */
    if (end == nullptr) {
        list = newNode;
    } else {
        end->next = newNode;
    }
}
