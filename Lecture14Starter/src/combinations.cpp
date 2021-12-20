#include <iostream>
#include "set.h"
#include "console.h"
using namespace std;


Set<Set<string>> combinationsRec(Set<string>& remaining, int k, Set<string>& chosen) {
    /* TODO: Fill me in! */
    return {};
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
