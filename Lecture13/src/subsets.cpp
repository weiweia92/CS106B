#include <iostream>
#include "set.h"

using namespace std;

void listSubsetsHelper(Set<string>& remaining, Set<string>& chosen);

/* Code to list all subsets of a set. The first parameter
 * represents the elements we haven't yet considered. The second
 * parameter represents which integers we have already chosen.
 */
void listSubsetsHelper(Set<string>& remaining, Set<string>& chosen) {
    /* Base case: When we don't have any choices left, stop. */
    if (remaining.isEmpty()) {
        cout << chosen << endl;
    }
    /* Recursive case: Pick an element. Then we either include that element
     * or exclude that element.
     */
    else {
        /* Choose: Select someone to make a decision about. */
        string elem = remaining.first();
        remaining = remaining - elem;

        /* Explore: Make two recursive calls, one with the person and one without them. */
        /* Case 1: Not include the selected person. */
        listSubsetsHelper(remaining, chosen);

        /* Case 2: Include the selected person in the subset that we're building. */
        chosen = chosen + elem;
        listSubsetsHelper(remaining, chosen);

        /* Unchoose: Make sure recursive parameters are restored to their original state. */
        
        /* We must explicitly undo the changes we made to the data structures
         * so that we don't impact the state of the variables in other stack
         * frames.
         */
        
        chosen.remove(elem);
        remaining = remaining + elem;
    }
}

void listSubsets(Set<string>& choices) {
    /* TODO: Fill me in! */
    Set<string> subsetTracker;
    listSubsetsHelper(choices, subsetTracker);
}

