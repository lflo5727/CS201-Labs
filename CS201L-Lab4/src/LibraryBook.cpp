// Liam Floyd
// 9/28/17
// Lab #4
#include "LibraryBook.h"
#include <string>
using namespace std;

LibraryBook::LibraryBook(){
    //Default constructor
    title = "";
    author = "";
    ISBN = "";
    checkedOut = false;
}
LibraryBook::LibraryBook(string a, string b, string c){
    //constructor
    title = a;
    author = b;
    ISBN = c;
    checkedOut = false;
}
//Setters
void LibraryBook::setTitle(string name){
    title = name;
}
void LibraryBook::setAuthor(string name){
    author = name;
}
void LibraryBook::setISBN(string num){
    ISBN = num;
}
void LibraryBook::checkIn(){
    checkedOut = false;
}
void LibraryBook::checkOut(){
    checkedOut = true;
}

//Getters
string LibraryBook::getTitle(){
    return title;
}
string LibraryBook::getAuthor(){
    return author;
}
string LibraryBook::getISBN(){
    return ISBN;
}
bool LibraryBook::isCheckedOut(){
    return checkedOut;
}
