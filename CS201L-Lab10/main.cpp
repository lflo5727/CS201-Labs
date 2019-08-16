// Liam Floyd
// 11/9/17
// Lab 10

#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <map>
using namespace std;


// Starting point
int main()
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	map <string, int> wordMap;

	// Read in file
	string wordIn;
	// While there are more words
	while(fin >> wordIn){
		// It's not found by default
		bool found = false;

		// For each element in the array, if it exists, increment its count, and mark it as found
        for(map<string,int>::iterator iter = wordMap.begin(); iter != wordMap.end(); iter++)
        {
			if(iter->first == wordIn){
				iter->second++;
				found =true;
				// Quit for loop early
				break;
			}
		}
		// If not found, add it. If array is full, resize it first.
		if(!found){
		    wordMap.insert(pair <string, int> (wordIn, 1));
		}
	}

	// Print list of words and counts

	fout << "Words found: " << wordMap.size() << endl;

	// For each word, print it's word/count pair.
	for(map<string,int>::iterator iter = wordMap.begin(); iter != wordMap.end(); iter++){
		fout << iter->first << " - " << iter->second << endl;
	}
}
