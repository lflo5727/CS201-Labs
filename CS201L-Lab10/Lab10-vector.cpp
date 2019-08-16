// Liam Floyd
// 11/9/17
// Lab 10

#include "Word.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;


// Starting point
int main()
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int vecsize = 0;
	vector <Word> wordVec;

	// Read in file
	string wordIn;
	// While there are more words
	while(fin >> wordIn){
		// It's not found by default
		bool found = false;

		// For each element in the array, if it exists, increment its count, and mark it as found
		for(vector <Word>::iterator iter = wordVec.begin(); iter!= wordVec.end(); iter++){
			if(iter->getWord() == wordIn){
				iter->increment();
				found = true;
				// Quit for loop early
				break;
			}
		}
		// If not found, add it. If array is full, resize it first.
		if(!found){
            Word temp;
            temp.setWord(wordIn);
            wordVec.push_back(temp);
			wordVec[vecsize].increment();
			vecsize++;
		}
	}

	// Print list of words and counts

	fout << "Words found: " << wordVec.size() << endl;

	// For each word, print it's word/count pair.
	for(vector<Word>::iterator iter = wordVec.begin(); iter != wordVec.end(); iter++){
		fout << iter->getWord() << " - " << iter->getCount() << endl;
	}
}
