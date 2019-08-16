//////////////////////////////
//      Liam Floyd
//      11/30/17
//      CS201 Lab 12
//////////////////////////////
#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

void fillList(list<char>& listToUse, string item){
    for(int i = 0;i < item.size(); i++){
        listToUse.push_back(item[i]);
    }
}

void printList(list<char> listToPrint, ostream& fout){
    for(list<char>::iterator itm = listToPrint.begin(); itm != listToPrint.end(); itm++){
        fout << "[" << *itm << "] -> ";
    }
    fout << "[0]\n\n";
}

void removeChar(list<char>& listToUse, char remv){
    for(list<char>::iterator itm = listToUse.begin(); itm != listToUse.end();){
        if(*itm == remv){
            itm = listToUse.erase(itm);
        }else{
            itm++;
        }
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

    string read;
    while(getline(fin, read)){
        list<char> myList;
        fin >> read;
        fillList(myList, read);
        for(int p = 0; p < 10; p++){
            removeChar(myList, vowels[p]);
        }

        printList(myList, fout);
    }

    fin.close();
    fout.close();
    return 0;
}
