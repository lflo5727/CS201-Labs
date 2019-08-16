////////////////////////
//      Liam Floyd
//      11/16/17
//      CS201L Lab 11
////////////////////////
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class swapT>
void mySwap(swapT arrayUse[], int pos1, int pos2){
    swapT temp = arrayUse[pos1];
    arrayUse[pos1] = arrayUse[pos2];
    arrayUse[pos2] = temp;
}

template <class minT>
minT myMin(minT arrayUse[]){
    minT minTemp = arrayUse[0];
    for(int i = 1; i < 100; i++){
        if(arrayUse[i] < minTemp){
            minTemp = arrayUse[i];
        }
    }
    return minTemp;
}

template <class maxT>
maxT myMax(maxT arrayUse[]){
    maxT maxTemp = arrayUse[0];
    for(int i = 1; i < 100; i++){
        if(arrayUse[i] > maxTemp){
            maxTemp = arrayUse[i];
        }
    }
    return maxTemp;

}

template <class searchT>
int mySearch(searchT arrayUse[], searchT item){
    for(int i = 0; i < 100; i++){
        if(arrayUse[i] == item)
            return i;
    }
    return -1;
}

int main(){
    int intArray[100];
    double doubleArray[100];
    string stringArray[100];
    //Declare all the arrays

    ifstream intFile("integers.txt");
    ifstream doubleFile("doubles.txt");
    ifstream stringFile("strings.txt");
    //Open the files
    int cnt = 0;
    while(intFile.good()){
        intFile >> intArray[cnt];
        cnt++;
    }
    cnt = 0;
    while(doubleFile.good()){
        doubleFile >> doubleArray[cnt];
        cnt++;
    }
    cnt = 0;
    while(stringFile.good()){
        stringFile >> stringArray[cnt];
        cnt++;
    }
    //Read through all the files


    //Integer output
    cout << "Integers:\nSwapped items at positions 10 and 20\nBefore: [10] " << intArray[10] << " [20] " << intArray[20] << endl;
    mySwap(intArray, 10, 20);
    cout << "After: [10] " << intArray[10] << " [20] " << intArray[20] << "\nMin: " << myMin(intArray) << "\nMax: " << myMax(intArray) << endl;
    cout << "The number 1 is at position " << mySearch(intArray, 1) << "\nThe number 5 is at position " << mySearch(intArray, 5) << "\n\n";
    //Double output
    cout << "Doubles:\nSwapped items at positions 10 and 20\nBefore: [10] " << doubleArray[10] << " [20] " << doubleArray[20] << endl;
    mySwap(doubleArray, 10, 20);
    cout << "After: [10] " << doubleArray[10] << " [20] " << doubleArray[20] << "\nMin: " << myMin(doubleArray) << "\nMax: " << myMax(doubleArray) << endl;
    cout << "The number 4.62557 is at position " << mySearch(doubleArray, 4.62557) << "\nThe number 1.23456 is at position " << mySearch(doubleArray, 1.23456) << "\n\n";
    //String output
    cout << "Strings:\nSwapped items at positions 10 and 20\nBefore: [10] " << stringArray[10] << " [20] " << stringArray[20] << endl;
    mySwap<string>(stringArray, 10, 20);
    cout << "After: [10] " << stringArray[10] << " [20] " << stringArray[20];
    cout << "\nMin: " << myMin<string>(stringArray) << "\nMax: " << myMax<string>(stringArray) << endl;
    cout << "The word Shoes is at position " << mySearch<string>(stringArray, "Shoes") << "\nThe word Pumpkin is at position " << mySearch<string>(stringArray, "Pumpkin") << "\n\n";

    intFile.close();
    doubleFile.close();
    stringFile.close();
    //Close the files
    return 0;
}
