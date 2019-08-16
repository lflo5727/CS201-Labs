// Liam Floyd
// 9/21/17
// Section #3
// Lab #3
#include <cmath>
#include "Point.h"

Point::Point(){
    //Constructor to start coordinates at origin
    x = 0;
    y = 0;
    z = 0;
}

void Point::setCoordinates(int a, int b, int c){
    //Set the coordinates
    x = a;
    y = b;
    z = c;
}
int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}
int Point::getZ(){
    return z;
}
double Point::calcOriginDistance(){
    //Calculate the distance from (0,0,0)
    double xdiffSq = pow ((x - 0),2);
    double ydiffSq = pow ((y - 0),2);
    double zdiffSq = pow ((z - 0),2);

    return sqrt((xdiffSq + ydiffSq + zdiffSq));
}

double Point::calcDistance(Point p2){
    //Calculate the distance from second Point object
    double xdiffSq = pow ((x - p2.getX()),2);
    double ydiffSq = pow ((y - p2.getY()),2);
    double zdiffSq = pow ((z - p2.getZ()),2);

    return sqrt((xdiffSq + ydiffSq + zdiffSq));
}
