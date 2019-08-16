// Liam Floyd
// 9/28/17
// Lab #4

#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H
#include <string>
using namespace std;

class LibraryBook{
    private:
        string title;
        string author;
        string ISBN;
        bool checkedOut;

    public:
        LibraryBook();
        LibraryBook(string, string, string);
        //Setters
        void setTitle(string);
        void setAuthor(string);
        void setISBN(string);
        void checkIn();
        void checkOut();
        //Getters
        string getTitle();
        string getAuthor();
        string getISBN();
        bool isCheckedOut();

};

#endif
