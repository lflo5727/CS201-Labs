///////////////////////////
//      Liam Floyd
//      CS201L - Lab 7
//      10/19/17
///////////////////////////
#ifndef WORD_H
#define WORD_H
#include <string>
using namespace std;

class Word{
    private:
        string wordName;
        int wordCnt;

    public:
        Word();
        Word(string);

        void increment();

        void setWordName(string);
        void setWordCnt(int);

        string getWordName();
        int getWordCnt();



};

#endif // WORD_H
