// Liam Floyd
// 9/7/2017
// Lab #1

#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2){
    //Get the distance between the two points
    double xdiffSq = pow ((x1 - x2),2);
    double ydiffSq = pow ((y1 - y2),2);
    double zdiffSq = pow ((z1 - z2),2);
    //Get the difference of each coordinate pair and square it

    return sqrt((xdiffSq + ydiffSq + zdiffSq));
}

int main()
{
    double x1[20],y1[20],z1[20],x2[20],y2[20],z2[20];
	// Create two variables for reading input and output files
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	// Write the remainder of your code here
    for (int i = 0; fin.good(); i++){
        //Go through each line and perform the distance function on each set of coordinates
        fin >> x1[i] >> y1[i] >> z1[i];
        fin >> x2[i] >> y2[i] >> z2[i];
        fout << calcDistance(x1[i],y1[i],z1[i],x2[i],y2[i],z2[i])<< endl;
    }

	return 0;
}
