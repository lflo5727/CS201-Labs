// Liam Floyd
// 10/05/17
// Lab 5
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class Fraction {

// Add the variables and functions you need to.
// getGCD and reduce are provided for you.

private:
	int getGCD( int num1, int num2 );
	int numerator;
	int denominator;

public:
    Fraction();
    Fraction(int, int);
	void reduce();

	const Fraction operator+(Fraction rhs);
	const Fraction operator-(Fraction rhs);
	const Fraction operator*(Fraction rhs);
	const Fraction operator/(Fraction rhs);
	bool operator==(Fraction rhs);

	friend ostream& operator<< (ostream& output, const Fraction& fract);
    friend istream& operator>> (istream& input, Fraction& fract);
};


#endif // FRACTION_H
