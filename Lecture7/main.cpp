#include "console.h"
#include "map.h"
#include <string>
#include "strlib.h"

using namespace std;

/* This function implements the counting sort algorithm to sort
 * the letters in a string. You can assume that the string consists
 * of all lowercase, alphabetical characters.
 */
string countingSort(string s) {
    /* Build a map of character frequencies in the word.
     * This code is almost identical to yesterday's code for building
     * a map of word frequencies from a text file.
     */
    Map<char, int> freqMap;
    for (char ch : s) {
        freqMap[ch] += 1
    }

    string sortedString;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        /* TODO: Write pseudocode that explains how you would use the information
         * in freqMap to correctly make progress towards building up to stored
         * string.
         */

        /* only want to add letter to sortedString if it exists as key in map
         *      extract axactly how many copies of character to add from map
         *      for loop for value extracted from map
         *          add a single copy of current character to sortedString
         */
        if (freqMap.containsKey(ch)) {
            int numCopies = freqMap[ch];
            for (int i = 0; i < numCopies; i++) {
                sortedString += charToString(ch);
            }
        }
    }
    return sortedString;
}



    }
    
} 
