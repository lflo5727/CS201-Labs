///////////////////////////
//      Liam Floyd
//      CS201L - Lab 7
//      10/19/17
///////////////////////////
#include <iostream>
#include "Word.h"
#include <fstream>


using namespace std;

void resizeArray(Word* &arrayToUse, int &sizeOfArray){
    //Creates new array that is bigger and copies to it
    Word* newArray = new Word[sizeOfArray];
    for(int p = 0; p < sizeOfArray/2; p++){
        newArray[p] = arrayToUse[p];
    }
    arrayToUse = newArray;
}

int main(){
    ifstream fileIn("input.txt");
    ofstream fileOut("output.txt");
    int arraySize = 10;
    int wordsTotal = 0;
    Word* wordArray = new Word[arraySize];
    //Create dynamic array

    while(fileIn.good()){
        string currentWord;
        bool inArray = false;
        fileIn >> currentWord;

        for(int i = 0; i < wordsTotal; i++){
            //Search array and return true if the word exists
            if(wordArray[i].getWordName() == currentWord){
                wordArray[i].increment();
                inArray = true;
                break;
            }
        }
        if(!inArray){
            //Create a new word object if it doesn't already exist
            wordsTotal++;
            if(wordsTotal == arraySize){
                arraySize *= 2;
                resizeArray(wordArray, arraySize);
            }
            Word tempWord(currentWord);
            wordArray[wordsTotal] = tempWord;
        }
    }

    fileOut << "Words Found: " << wordsTotal << "\nMax Array Size: " << arraySize << "\n\n";
    for(int j = 0; j < wordsTotal; j++){
        fileOut << wordArray[j].getWordName() << " - " << wordArray[j].getWordCnt() << endl;
    }
    fileIn.close();
    fileOut.close();
    return 0;
}
