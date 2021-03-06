// OurVector.cpp
// Implementation of OurVector class

#include "error.h"
#include "strlib.h"
#include "OurVector.h"
#include "testing/SimpleTest.h"

const int INITIAL_CAPACITY = 8;

// constructor
OurVector::OurVector(){
    /* TODO: Fill in this function! */
    allocatedCapacity = INITIAL_CAPACITY;
    numItems = 0;
    elements = new int[allocatedCapacity];
    cout << "Constructor!" << endl;
}

// destructor
OurVector::~OurVector(){
    /* TODO: Fill in this function! */
    delete[] elements;
    cout << "Destructor!" << endl;
}

// append value to the end of our array
void OurVector::add(int value){
    /* TODO: Fill in this function! */
    if (numItems == allocatedCapacity) {
        expand();
    }
    int nextEmptySlotIndex = numItems;
    elements[nextEmptySlotIndex] = value;
    numItems++;
}

// insert value at index
void OurVector::insert(int index, int value){
    /* TODO: Fill in this function! */
    if (index < 0 || index > numItems) {
        error("Invalid vector index! Should be in range [0 - "
             + integerToString(numItems - 1) + "]");
    }
    /* If we are out of space, we must first expand the
     * array's capacity. */
    if (numItems == allocatedCapacity) {
        expand();
    }
    for (int i = numItems; i > index; i--) {
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
    numItems++;
}

// return the element at index
int OurVector::get(int index){
    /* TODO: Fill in this function! */
    if (index < 0 || index >= numItems) {
        error("Out of bounds!")
    }
    return elements[index];
}

// remove value from index
void OurVector::remove(int index){
    /* TODO: Fill in this function! */
    if (index < 0 || index >= numItems) {
        error("Out of bounds!")
    }
    for (int i = index; i < numItems - 1; i++) {
        elements[i] = elements[i+1];
    }
    numItems--;
}

// returns the number of elements
int OurVector::size(){
    /* TODO: Fill in this function! */
    return numItems;
}

// returns true if there aren't any elements
bool OurVector::isEmpty(){
    return numItems == 0;
}

void OurVector::printDebugInfo(){
    /* TODO: Fill in this function! */
}

void OurVector::expand() {
    // 1. ask for new space for a new array
    int* newElements = new int[2 * allocatedCapacity];
    // 2. copy the values over
    for (int i = 0; i < numItems; i++) {
        newElements[i] = elements[i];
    }
    // 3. delete old array
    delete[] elements;
    // 4. point elements to new array
    elements = newElements;
    // 5. update capacity
    allocatedCapacity *= 2;
}
PROVIDED_TEST("Construct vector and see constructor/destructor be called."){
    OurVector vec;
}

PROVIDED_TEST("Check that newly created vector is empty"){
    OurVector vec;
    EXPECT_EQUAL(vec.isEmpty(), true);
}

PROVIDED_TEST("Add 5 elements to vector."){
    OurVector vec;
    for (int i = 0; i < 5; i++){
        vec.add(i);
    }

    EXPECT_EQUAL(vec.size(), 5);
    EXPECT_EQUAL(vec.isEmpty(), false);
    cout << endl;
    vec.printDebugInfo();
}

PROVIDED_TEST("Add 5 elements and then insert another element at index 3."){
    OurVector vec;
    for (int i = 0; i < 5; i++){
        vec.add(i);
    }

    vec.insert(3, 100);
    EXPECT_EQUAL(vec.size(), 6);
    EXPECT_EQUAL(vec.get(3), 100);

    cout << endl;
    vec.printDebugInfo();
}

PROVIDED_TEST("Add 5 elements and then remove element at index 3."){
    OurVector vec;
    for (int i = 0; i < 5; i++){
        vec.add(i);
    }

    vec.remove(3);
    EXPECT_EQUAL(vec.size(), 4);
    EXPECT_EQUAL(vec.get(3), 4);

    cout << endl;
    vec.printDebugInfo();
}

PROVIDED_TEST("Add 5 elements and then do an insertion at the very beginning and very end of vector."){
    OurVector vec;
    for (int i = 0; i < 5; i++){
        vec.add(i);
    }

    vec.insert(0, 200);
    EXPECT_EQUAL(vec.size(), 6);
    EXPECT_EQUAL(vec.get(0), 200);
    for (int i = 0; i < 5; i++){
        EXPECT_EQUAL(vec.get(i+1), i);
    }
    cout << endl;
    vec.printDebugInfo();

    vec.insert(6, 300);
    EXPECT_EQUAL(vec.size(), 7);
    EXPECT_EQUAL(vec.get(0), 200);
    for (int i = 0; i < 5; i++){
        EXPECT_EQUAL(vec.get(i+1), i);
    }
    EXPECT_EQUAL(vec.get(6), 300);
    vec.printDebugInfo();
}

PROVIDED_TEST("Add 50 elements. Tests expansion (twice)"){
    OurVector vec;
    for (int i = 0; i < 50; i++){
        vec.add(i);
    }

    EXPECT_EQUAL(vec.size(), 50);
    for (int i = 0; i < 50; i++){
        EXPECT_EQUAL(vec.get(i), i);
    }
    EXPECT_EQUAL(vec.isEmpty(), false);
    cout << endl;
    vec.printDebugInfo();
}
