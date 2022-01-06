#include <string>
#include "lexicon.h"
#include "testing/SimpleTest.h"
#include "prototypes.h"

using namespace std;

bool isShrinkable(Lexicon& lex, string word) {
    /* TODO: Fill in isShrinkable function! */
    /* Base Case: Things must be words to be shrinkable words. */
    if (word.length() == 1 && lex.contains(word)) {
        return true;
    }
    /* Recursive Case: Try removing each letter. */
    for (int i = 0; i < word.length(); i++) {
        string reduced = word.substr(0, i) + word.substr(i + 1);
        if (lex.contains(reduced)) {
            if (isShrinkable(lex, reduced)) {
                return true;
            }
        }
    }

    /* Oh fiddlesticks. */
    return false;
}

void printAllLargeShrinkableWords() {
    Lexicon lex("res/EnglishWords.txt");

    for (string word: lex) {
        if (word.length() >= 9 && isShrinkable(lex, word)) {
            cout << word << endl;
        }
    }
}

PROVIDED_TEST("Example cases of isShrinkable function from slides"){
    Lexicon lex("res/EnglishWords.txt");
    EXPECT(isShrinkable(lex, "startling"));
    EXPECT(isShrinkable(lex, "cart"));
    EXPECT(!isShrinkable(lex, "cusp"));
}
