// Liam Floyd
// 9/21/17
// Section #3
// Lab #3

#ifndef POINT_H
#define POINT_H

// Define your class here
class Point{
    private:
        int x;
        int y;
        int z;

    public:
        Point();
        void setCoordinates(int, int, int);
        double calcOriginDistance();
        double calcDistance(Point);

        int getX();
        int getY();
        int getZ();

};

#endif
