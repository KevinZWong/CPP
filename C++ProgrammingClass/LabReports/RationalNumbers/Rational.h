/*
Rational Numbers
Kevin Wong
7/7/2021
Version 1
*/
#ifndef RATIONAL_H	// if this compiler macro is not defined
#define RATIONAL_H	//	 then define it so this file will not be processed again

#include <iostream>
using namespace std;

class Rational
{
    // Friend functions are actually declared outside the scope of the
    // class but have the right to access public and private data and
    // member function members that belong to the class. The friend
    // function below gives the << operator for ostreams (including cout)
    // the ability to output a Rational object by accessing its member data.
    friend ostream &operator<< (ostream &out, Rational const &r);

public:
	Rational (int num=0, int denom=1);  // also provides default constructor

    Rational add (const Rational right);
	Rational operator+  (const Rational right);    // + addition operator
	Rational operator+= (const Rational right);   // += addition assignment operator
	Rational operator-  (const Rational right);    // + addition operator
	Rational operator-= (const Rational right);   // += addition assignment operator
    Rational operator* (const Rational right);
    Rational operator*= (const Rational right);
    Rational operator/ (const Rational right);
    Rational operator/= (const Rational right);
    Rational operator== (const Rational right);


	void display();
    operator double() const; // convert Rational to double

private:
	int numerator;
	int denominator;
    // helper functions are private and not accessible by the main program
    int LCD(const int v1, const int v2);
    Rational setRational (const int n, const int d);
};

#endif
