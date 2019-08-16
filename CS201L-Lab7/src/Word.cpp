///////////////////////////
//      Liam Floyd
//      CS201L - Lab 7
//      10/19/17
///////////////////////////
#include "Word.h"
#include <string>

Word::Word(){
    wordName = "";
    wordCnt = 0;
}
Word::Word(string name){
    wordName = name;
    wordCnt = 1;
}

void Word::increment(){
    wordCnt++;
}


void Word::setWordName(string a){
    wordName = a;
}
void Word::setWordCnt(int b){
    wordCnt = b;
}

string Word::getWordName(){
    return wordName;
}
int Word::getWordCnt(){
    return wordCnt;
}
