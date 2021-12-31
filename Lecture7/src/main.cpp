#include <iostream>
#include "console.h"
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include <fstream>
#include "stack.h"
#include "queue.h"
#include "set.h"

using namespace std;

void populateDictionary(Set<string>& dictionary, string filename);
void wordLadderProgram();
Stack<string> findWordLadder(string startingWord, string destinationWord, Set<string>& dictionary);
Set<string> generateNeighboringWords(string currentWord, Set<string>& dictionary);



int main() 
{
    wordLadderProgram();

    cout << "All done!" << endl;
    return 0;
}

void wordLadderProgram(){
    cout << "Welcome to the Word Ladder Finder!" << endl;
    cout << "A powerful computer program that leverages many different" << endl;
    cout << "ADTs to solve a fun children's puzzle." << endl;
    cout << "Up, up, and away!" << endl << endl;

    Set<string> dictionary;
    populateDictionary(dictionary, "res/EnglishWords.txt");

    while (true) {
        string userInput = getLine("Please enter two words that you want to find "
                                   "a word ladder between, separated by a space: ");
        if (userInput == "") break;

        Vector<string> words = stringSplit(userInput, " ");
        Stack<string> wordLadder = findWordLadder(words[0], words[1], dictionary);

        if (wordLadder.isEmpty()){
            cout << "Coudn't find a word ladder between those two words!" << endl;
            continue;
        }

        cout << "Here is the word ladder from " << words[1] << " to " << words[0] << endl;
        while(!wordLadder.isEmpty()){
            cout << wordLadder.pop() << endl;
        }
        cout << endl;

    }

}

void populateDictionary(Set<string>& dictionary, string filename){
    ifstream in;
    openFile(in, filename);
    Vector<string> lines;
    readEntireFile(in, lines);
    for (string word: lines){
        dictionary.add(word);
    }
    cout << "Found " << dictionary.size() << " words in the dictionary file." << endl << endl;
}

Set<string> generateNeighboringWords(string currentWord, Set<string>& dictionary){
    Set<string> neighboringWords;
    for (int i = 0; i < currentWord.length(); i++){
        for (char ch = 'a'; ch <= 'z'; ch++){
            string newWord = currentWord;
            newWord[i] = ch;
            if (dictionary.contains(newWord)){
                neighboringWords.add(newWord);
            }
        }
    }
    return neighboringWords;
}

Stack<string> findWordLadder(string startingWord, string destinationWord, Set<string>& dictionary){
    /* TODO: Implement breadth-first search to find a word ladder. */

    // Create an empty queue and an empty set of visited locations
    Queue<Stack<string>> allLadders;
    Set<string> visitedWords;

    // Create an initial word ladder containing the starting word and add it to the queue
    Stack<string> initialLadder = {startingWord};
    allLadders.enqueue(initialLadder);

    // While the queue is not empty
    while (!allLadders.isEmpty()) {
        // Remove the next partial ladder from the queue
        Stack<string> currentLadder = allLadders.dequeue();
        // Set the current search word to be the word at the top of the ladder
        string currentWord = currentLadder.peek();
        // If the current word is the destination, then return the current ladder
        if (currentWord == destination) {
            return currentLadder;
        }
        // Generate all "neighboring" words that are valid English words and one letter away from the currentWord
        Set<string> neighbors = generateNeighboringWords(currentWord, dictionary);
        // Loop over all neighbor words
        for (string neighbor : neighbors) {
            /* If the neighbor hasn't yet been visited
            Create a copy of the current ladder
            Add the neighbor to the top of the new ladder and mark it visited
            Add the new ladder to the back of the queue of partial ladders
            */
            if (!visitedWords.contains(neighbor)) {
                Stack<string> newLadder = currentLadder;
                newLadder.push(neighbor);
                visitedWords.add(neighbor);
                allLadders.enqueue(newLadder);
            }

        }

    }
    return {};
}
