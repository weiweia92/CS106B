#include "swap.h"
using namespace std;

void swap::run() {
    int temp;
    temp = _a;
    _a = _b;
    _b = temp;
}

void swap::printInfo() {
    cout << "_a = " << _a << endl;
    cout << "_b = " << _b << endl;
}