// Liam Floyd
// 9/28/17
// Lab #4

#include "LibraryBook.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	// File stream variables
    ifstream finBooks("books.txt");
	ifstream finISBN("isbns.txt");
	ofstream fout("checkedout.txt");
	string bookName, bookAuthor, bookNum;
    vector <LibraryBook> books;

	// Check for file errors first
	if(!finBooks || !finISBN)
	{
		cout << "Error opening input files!\n";
		return 1;
	}

    //While loop to read in each line and create book objects for them
    while(finBooks.good()){
        getline(finBooks, bookName);
        getline(finBooks, bookAuthor);
        getline(finBooks, bookNum);
        LibraryBook tempBook(bookName, bookAuthor, bookNum);
        books.push_back(tempBook);
    }
    //While loop through the ISBNs passed through scanner
    while(finISBN.good()){
        string tempISBN;
        finISBN >> tempISBN;
        for(int p = 0; p < books.size(); p++){
            //For loop through each book object that will set the check out status if the book exists in the ISBN file
            if((tempISBN == books[p].getISBN()) && (books[p].isCheckedOut())){
                books[p].checkIn();
            }else if((tempISBN == books[p].getISBN()) && (!books[p].isCheckedOut())){
                books[p].checkOut();
            }
        }
    }

    //Output to the file
    fout << "Books checked out:\n------------------\n\nTitle    Author    ISBN \n";
    for(int q = 0;q < books.size();q++){
        if(books[q].isCheckedOut()){
            fout << books[q].getTitle() << "    " << books[q].getAuthor() << "    " << books[q].getISBN() << endl;
        }
    }

	// Close the files at the end
	finBooks.close();
	finISBN.close();
	fout.close();

    // End program
	return 0;
}
