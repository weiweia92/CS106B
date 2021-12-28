#include <iostream>
#include "console.h"
#include "vector.h"
#include "grid.h"
using namespace std;

/* Fun fact: Saki is the name of Kylie's dog! */
Vector<int> saki(Vector<int> v){
    while (v.size() > 0){
        v.remove(0);
    }
    return v;
}

/* Fun fact: Buster is the name of Trip's dog! */
void buster(Vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        v[i] = -1 * v[i]
    }
}

/* Fun fact: Lola is the name of Nick's cat! */
void lola(Vector<int> a, Vector<int>& b){
    Vector<int> temp = a;
    a = b;
    b = temp;
    b.add(18);
}

int main(){
    Vector<int> a = {1, 0, 6};
    Vector<int> b = {-5, 4, -1, 7};

    saki(a);
    cout << a << endl;
    cout << b << endl; 

    //TODO: What are the contents of a and b at this point in the code?
    // a: { ... fill me in ...}
    // b: { ... fill me in ...}

    buster(b);
    cout << a << endl;
    cout << b << endl; 
    //TODO: What are the contents of a and b at this point in the code?
    // a: { ... fill me in ...}
    // b: { ... fill me in ...}

    lola(a, b);
    cout << a << endl;
    cout << b << endl; 
    //TODO: What are the contents of a and b at this point in the code?
    // a: { ... fill me in ...}
    // b: { ... fill me in ...}

    return 0;
}