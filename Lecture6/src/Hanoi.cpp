#include "console.h"
#include "stack.h"
#include "reverse.h

using namespace std;

void towersOfHanoiThreeDisks(Stack<int>& destination) {
    Stack<int> source = {3, 2, 1}; // defines a stack with 1 on top, 2 in the middle, 3 on the bottom
    Stack<int> auxiliary;

    /* FILL ME IN OUR BREAKOUT ROOMS */
    destination.push(source.pop());
    auxiliary.push(source.pop());
    auxiliary.push(destination.pop());
    destination.push(source.pop());
    source.push(auxiliary.pop());
    destination.push(auxiliary.pop());
    destination.push(source.pop());
}

void towersOfHanoiGeneral(Stack<int>& destination, int numDisks) {
    // Populate source stack with numDisks initial disks
    Stack<int> source;
    for (int i = numDisks; i > 0; i--) {
        source.push(i);
    }
    Stack<int> auxiliary;
    /* CHALLENGE PROBLEM: FILL ME IN */

}

int main() {

    Stack<int> result; //The final peg

    towersOfHanoiThreeDisks(result);

    // Challenge problem: Write a general towersOfHanoi function
    // result = {};
    // towersOfHanoiGeneral(result, 5);

    cout << result << endl; // Show the final peg

    // Additional ordered ADT examples
    // sentenceReverseStack();
    return 0;
}
