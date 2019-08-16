// Liam Floyd
// 9/21/17
// Section #3
// Lab #3
#include <iostream>
#include <fstream>
#include "Point.h"
using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt"); // Create this file in Visual Studio (Remove comment when done)

  // Check that input file can be read
	if(!fin) {
		cout << "Input file could not be opened. Exiting." << endl;
		return 0;
	}
	int i;
	//Declare i to use it for later for loops
    Point pointList[20];
    for(i = 0; fin.good(); i++){
        //Read the points and assign them to coordinates of Point objects
        int x, y, z;
        fin >> x >> y >> z;
        Point tempPoint;
        tempPoint.setCoordinates(x, y, z);
        pointList[i] = tempPoint;

    }

    fout << "Distances from the Origin:\n";
    for(int p = 0; p < i; p+=2){
        //Print the distances from origin for all points (2 at a time since there are 2 on each line in example)
        fout << pointList[p].calcOriginDistance() << " " << pointList[p+1].calcOriginDistance() << endl;
    }

    fout << "\nDistances from each other:\n";
    for(int q = 0; q < i; q+=2){
        //Print the distances between each pair of points
        fout << pointList[q].calcDistance(pointList[q+1]) << endl;
    }


	return 0;
}


