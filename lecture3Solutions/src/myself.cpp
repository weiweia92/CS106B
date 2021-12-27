#include <string>
using namespace std;

void pollOne() {
    string word = "hello";
    word[1] = 'a';
    cout << word << endl;
}

int main() {
    pollOne();
}