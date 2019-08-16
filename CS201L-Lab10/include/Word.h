// Liam Floyd
// 11/9/17
// Lab 10
#ifndef WORD_H
#define WORD_H
#include <string>
using namespace std;

// Class to store a Word object
class Word{
    private:
        // Word that was found
        string word;
        // Number of times a word has been found
        int count;

    public:
        // Default constructor; needed for array creation
        Word();
        // Constructor to store the word with it
        Word(string theWord);

        // Returns the word stored
        string getWord();
        // Returns the count stored
        int getCount();
        // Increments the counter
        void increment();

        // Sets a new word to the object
        void setWord(string theWord);
        // Sets the count to a value
        void setCount(int theCount);
};

#endif // WORD_H
