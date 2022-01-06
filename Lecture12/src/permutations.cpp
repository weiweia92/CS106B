#include "vector.h"
#include "testing/SimpleTest.h"
#include "random.h"

using namespace std;

void listPermutationsHelper(string remaining, string soFar);

/* Given a string of letters we haven't yet considered, along with the partial
 * string built up so far, prints out all permutations that can be made from
 * those characters.
 */
void listPermutations(string str) {
    /* TODO: Fill in this function! */
    listPermutationsHelper(str, "");
}

void listPermutationsHelper(string remaining, string soFar) {
    /* Base case: If we've already committed to every character, then print out
     * the permutation we made.
     */
    if (remaining == "") {
        cout << soFar << endl;
    } else {
        /* Recursive case: Some character must come next in the ordering. Try all
        * possible choices of what it can be.
        */
        for (int i = 0; i < remaining.length(); i++) {
            /* Form a new string by dropping out the character at this index.
             * Note that getting a substring from an index that's equal to the
             * length of the string is perfectly legal; it just gives back the
             * empty string.
             */
            char currentLetter = remaining[i];
            string rest = remaining.substr(0, i) + remaining.substr(i + 1);
            listPermutationsHelper(rest, soFar + currentLetter);
        }
    }
}



