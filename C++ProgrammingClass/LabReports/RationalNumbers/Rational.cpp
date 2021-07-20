/*
Rational Numbers
Kevin Wong
7/7/2021
Version 1
*/
#include <iostream>
#include "Rational.h"
using namespace std;

// By using the default parameter settings in Rational.h, this
// constructor also provides the default constructor Rational()
Rational::Rational (int num, int denom)
{ 
    setRational(num,denom);   // set numerator and denominator, reduce fraction, fix the sign 
}

// Helper function to fix a zero denominator and fix the sign if denominator is negative
// setRational uses the LCD function to reduce the fraction to the lowest common denominator
Rational Rational::setRational (int n, int d) // helper function
{
    numerator = n;
    denominator = d;

    // if denominator == 0 then set it = 1
    if (denominator == 0)
        denominator = 1;

    if ( denominator < 0 ) // if denominator is neg, multiply num and denom by -1
    {
        numerator = -numerator;     // fix sign of numerator +/-
        denominator = -denominator; // denominator always +
    }

    int lcd = LCD(numerator, denominator);
    if (denominator != 0)
    {
        numerator /= lcd;
        denominator /= lcd;
    }
    return *this;   // return a pointer to the current object
}

// find the lowest common divisor using a recursive function
int Rational::LCD(int v1, int v2)
{
    if (v2==0) return v1;
    else return LCD (v2, v1%v2);
}

// operator+ method
Rational Rational::operator+ (Rational right)
{
	// create local (temporary) variables
    int newNumerator;
	int newDenominator;

    // compute the result and save in the local variables
    // the current object's numerator and denominator are not changed
	newNumerator = numerator*right.denominator + right.numerator*denominator;
	newDenominator = denominator * right.denominator;

    // create a new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}

// operator+= method
Rational Rational::operator+= (Rational right)
{
    // the current object is updated with the result of the += 
    numerator = numerator*right.denominator + right.numerator*denominator;
	denominator = denominator * right.denominator;

    // fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}

// the operator- method does the same thing as the add method
Rational Rational::operator- (Rational right)
{
	// create local (temporary) variables
	int newNumerator;
	int newDenominator;

    // compute the result and save in the local variables
    // the current object's numerator and denominator are not changed
	newNumerator = numerator*right.denominator - right.numerator*denominator;
	newDenominator = denominator * right.denominator;

    // create a new Rational object with the result and return it
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator-= (Rational right)
{
    // the current object is updated with the result of the -= 
	numerator = numerator*right.denominator - right.numerator*denominator;
	denominator = denominator * right.denominator;

    // fix the sign, reduce the fraction and return the current object
    return setRational(numerator, denominator);
}

//############################################################################

Rational Rational::operator* (Rational right)
{	
    int newNumerator;
	int newDenominator;
	newNumerator = numerator * right.numerator;
	newDenominator = denominator * right.denominator;

    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator*= (Rational right)
{	

	numerator = numerator * right.numerator;
	denominator = denominator * right.denominator;


    return setRational(numerator, denominator);
}

 Rational Rational::operator/ (Rational right)
{	
    int newNumerator;
	int newDenominator;
	newNumerator = numerator * right.denominator;
	newDenominator = denominator * right.numerator;

    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator/= (Rational right)
{	

	numerator = numerator * right.denominator;
	denominator = denominator * right.numerator;

    return setRational(numerator, denominator);
}
Rational Rational::operator== (Rational right)
{	
    bool bool1;

    if (numerator == right.numerator && denominator == right.denominator)
        bool1 = true;
    else
        bool1 = false;
    return bool1;
}


Rational::operator double() const // convert Rational to double and return
{
    return double(numerator) / double(denominator);
}

// Display a Rational number using the display() member method
void Rational::display()
{
	cout << numerator << '/' << denominator;
}

// Display a Rational number using << and a friend function.
// Friend functions are not part of the class and their code must be
// declared outside of the class with no :: Scope Resolution Operator.
// All function arguments must have their class defined 
ostream &operator<< (ostream &out, Rational const &r)
{ 
    out << r.numerator << '/' << r.denominator; 
    return out; // This is to keep the stream flowing
}
