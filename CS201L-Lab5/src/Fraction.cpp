// Liam Floyd
// 10/05/17
// Lab 5
#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

Fraction::Fraction(){
    //Default Constructor
    numerator = 0;
    denominator = 0;
}
Fraction::Fraction(int top, int bottom){
    //Constructor
    numerator = top;
    denominator = bottom;
}
// Find the greatest common denominator (GCD) for reducing
int Fraction::getGCD( int num1, int num2 ) {
	int remainder = num2 % num1;
	if ( remainder != 0 )
		return getGCD( remainder, num1 );
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce() {
    // Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	if(denominator <0){
        numerator *= -1;
        denominator *= -1;;
	}

}

ostream& operator<< (ostream& output, const Fraction& fract){
    output << fract.numerator << "/" << fract.denominator;
    return output;
}
istream& operator>> (istream& input, Fraction& fract){
    string slash;
    input >> fract.numerator >> slash >> fract.denominator;
    return input;
}

const Fraction Fraction::operator+(Fraction rhs){
    int newNume = 0;
    int newDeno = 0;
    //Function to add two fractions
    int tempD = denominator;
    numerator *= rhs.denominator;
    denominator *= rhs.denominator;
    rhs.denominator *= tempD;
    rhs.numerator *= tempD;

    newDeno = rhs.denominator;
    newNume = numerator + rhs.numerator;
    Fraction result(newNume, newDeno);
    result.reduce();
    return result;

}
const Fraction Fraction::operator-(Fraction rhs){
    int newNume = 0;
    int newDeno = 0;
    //Function to subtract two fractions
    int tempD = denominator;
    numerator *= rhs.denominator;
    denominator *= rhs.denominator;
    rhs.denominator *= tempD;
    rhs.numerator *= tempD;

    newDeno = rhs.denominator;
    newNume = numerator - rhs.numerator;
    Fraction result(newNume, newDeno);
    result.reduce();
    return result;
}
const Fraction Fraction::operator*(Fraction rhs){
    //Function to multiply fractions
    int newNume = 0;
    int newDeno = 0;
    newDeno = denominator * rhs.denominator;
    newNume = numerator * rhs.numerator;
    Fraction result(newNume, newDeno);
    result.reduce();
    return result;
}
const Fraction Fraction::operator/(Fraction rhs){
    //Function to divide fractions
    int newNume = 0;
    int newDeno = 0;
    int tempN = rhs.numerator;
    rhs.numerator = rhs.denominator;
    rhs.denominator = tempN;
    newDeno = denominator * rhs.denominator;
    newNume = numerator * rhs.numerator;
    Fraction result(newNume, newDeno);
    result.reduce();
    return result;

}
bool Fraction::operator==(Fraction rhs){
    //Tell if two fractions are equal to each other by reducing
    reduce();
    rhs.reduce();
    if((numerator == rhs.numerator)&&(denominator == rhs.denominator))
        return true;
    else
        return false;
}
