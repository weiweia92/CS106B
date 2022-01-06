#include <iostream>
#include "console.h"
#include "testing/SimpleTest.h"
#include "simpio.h"
#include "trees.h"

using namespace std;

int main() {
    if (runSimpleTests(NO_TESTS)){
        return 0;
    }

    TreeNode *tree = buildExampleTree();
    prettyPrint(tree);

    cout << endl;

    cout << "1) Pre-order" << endl;
    cout << "2) In-order" << endl;
    cout << "3) Post-order" << endl;
    int choice = -1;
    while (choice != 0) {
        choice = getInteger("Please choose 1-3 (0 to quit): ");
        switch (choice) {
            case 1: preorderPrintTree(tree); break;
            case 2: inorderPrintTree(tree); break;
            case 3: postorderPrintTree(tree); break;
        }
        cout << endl << endl;
    }
    cout << "All done, exiting!" << endl;
    return 0;
}




