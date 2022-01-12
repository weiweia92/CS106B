#include <iostream>
#include "set.h"
#include "console.h"
using namespace std;


Set<Set<string>> combinationsRec(Set<string>& remaining, int k, Set<string>& chosen) {
    /* TODO: Fill me in! */
    /* Base case: If we have filled up all the spots in our combination, then return a 
       set containing the combination we've built up.
    */
    if (k == 0) {
        return {chosen};
    }
    /* Base case: If we have less items to choose from than spots to fill, then we 
       can't create any combinations. */
    if (remaining.size() < k) {
        return {};
    }
    /* Recursive Case: Select one item out of those that are remaining, and generate all
       possible combinations both including and excluding that item. Then, the final return
       value we produce is the union of those two sets of combinations.
    */   
    string elem = remaining.first();
    remaining = remaining - elem;

    /* Exclude */
    Set<Set<string>> combinationsWithout = combinationsRec(remaining, k, chosen);
    /* Include */
    chosen.add(elem);
    Set<Set<string>> combinationsWith = combinationsRec(remaining, k - 1, chosen);
    
    /* Unchoose */
    remaining += elem;
    chosen -= elem;
    return combinationsWithout + combinationsWith;
}


Set<Set<string>> combinationsOf(Set<string>& elems, int k) {
    Set<string> combinationTracker;
    return combinationsRec(elems, k, combinationTracker);
}

void combinationsDemo() {
    Set<string> usSupremeCourt = {
        "Thomas",
        "Ginsburg",
        "Breyer",
        "Roberts",
        "Alito",
        "Sotomayor",
        "Kagan",
        "Gorsuch",
        "Kavanaugh"
    };

    Set<Set<string>> combinations = combinationsOf(usSupremeCourt, 5);
    cout << "There are " << combinations.size() << " combinations. They are: " << endl;
    for (Set<string> combination: combinations) {
        cout << combination << endl;
    }
}
