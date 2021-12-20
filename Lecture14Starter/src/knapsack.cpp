#include <iostream>
#include "console.h"
#include "vector.h"
using namespace std;

struct BackpackItem {
    int survivalValue;  // You can assume this value will always >= 0
    int weight;         // You can assume this value will always >= 0
};

int fillBackpack(Vector<BackpackItem>& items, int targetWeight);
int fillBackpackHelper(Vector<BackpackItem>& items, int weight, int curValue, int index);

int fillBackpack(Vector<BackpackItem>& items, int targetWeight, Vector<BackpackItem>& bestBackpackArrangement);
int fillBackpackHelper(Vector<BackpackItem>& items, int weight, int curValue, int index, Vector<BackpackItem>& bestBackpackArrangement);


int fillBackpackHelper(Vector<BackpackItem>& items, int capacityRemaining, int curValue, int index){
    /* TODO: Fill me in! */
    return 0;
}

int fillBackpack(Vector<BackpackItem>& items, int targetWeight){
    return fillBackpackHelper(items, targetWeight, 0, 0);
}

int fillBackpackHelper(Vector<BackpackItem>& items, int capacityRemaining, int curValue, int index, Vector<BackpackItem>& bestBackpackArrangement){
    /* TODO: Fill me in! */
    return 0;
}

int fillBackpack(Vector<BackpackItem>& items, int targetWeight, Vector<BackpackItem>& bestBackpackArrangement){
    return fillBackpackHelper(items, targetWeight, 0, 0, bestBackpackArrangement);
}

void knapsackDemo() {
    // solution: 44
    int targetWeight = 18;
    Vector<BackpackItem> items = {
        {12, 4},
        {10,6},
        {8, 5},
        {11, 7},
        {14, 3},
        {7, 1},
        {9, 6}
    };

    // solution: 67
    //        int targetWeight = 25;
    //        Vector<BackpackItem> items = {
    //                                    {5, 6},
    //                                    {20, 15},
    //                                    {3, 11},
    //                                    {50, 12},
    //                                    {5, 6},
    //                                    {4, 11},
    //                                    {15, 13},
    //                                    {12, 7},
    //                                    {6, 17},
    //                                    {7, 13}
    //                                   };

    // solution : 7
    //        int targetWeight = 5;
    //        Vector<BackpackItem> items = {
    //                                    {3, 2},
    //                                    {4, 3},
    //                                    {5, 4},
    //                                    {6, 5}
    //                                   };

    Vector<BackpackItem> backpack;

    cout << "Best solution has a value of: "
         << fillBackpack(items, targetWeight, backpack) << endl;
    cout << endl;

    cout << "Original objects: " << endl;
    for (BackpackItem item : items) {
        cout << "Survival Value: " << item.survivalValue << endl;
        cout << "Weight: " << item.weight << endl;
        cout << endl;
    }

    cout << "Target weight: " << targetWeight << endl << endl;

    cout << "Best backpack: " << endl;
    for (BackpackItem item: backpack) {
        cout << "Survival Value: " << item.survivalValue << endl;
        cout << "Weight: " << item.weight << endl;
        cout << endl;
    }
}
