
//  complex.h
//  a Complex object presents the complex number X+Yi, where X and Y are real numbers and
// i^2 is -1. Typically, X is called a real part and Y is an imaginary part of the complex number.
// (square root of -1)
//
//  Created by Galiya Shakenova on 12.04.15.
//  Copyright (c) 2015 Galiya Shakenova. All rights reserved.

#ifndef __complex__complex__
#define __complex__complex__

#include <stdio.h>
#include <iostream>
using namespace std;

// A complex number is a number of the form x + iy, where x and y are
// real numbers and i is the square root of -1.
// The number x is known as the real part of the complex number, and
// iy is known as the imaginary part.
// The basic operations on complex numbers are to add and multiply them
// by applying the commutative, associative, and distributive laws
// of algebra (along with the identity i^2 - 1)
// Examples include a = 3 + 4i, and b = -2 + 3i

// Implementation and assumption:
// -- Complex are stored as a pair of real numbers: a real part, and an imaginary part
// -- The complex conjugate of the complex number z = x + yi is defined to be x − yi
// -- Two complex numbers are equal if and only if both their real and imaginary parts are equal
// -- Complex numbers are added by adding the real and imaginary parts of the summands

class complex {
    
    // overloaded <<: prints X+Yi, where X and Y are a Real and Imaginary value respectively.
    // if either X or Y is 0, it is not displayed.
    // if both X and Y are 0, the output is 0.
    // if X is 1, it's printed out as 1, and that if Y is 1, its output is i
    friend ostream& operator<<(ostream&, const complex &);
    
    // overloaded >>: take two values as a real and imaginary value
    friend istream& operator>>(istream&, complex &);
    
public:
    // default constructor: parameters are real and imaginary parts resp.
    complex (double = 0.0, double = 0.0);
    
    double getReal(); // returns real part of complex
    double getImaginary(); // returns an imaginary part
    complex  conjugate(); // conjugate complex
    
    // arithmetic operators
    complex operator+(const complex &) const; //add 2 complex
    complex operator-(const complex &) const; //subtract 2 complex
    complex operator*(const double &) const; // multiply complex  by passed argument
    complex operator*(const complex &) const; // multiply complex by a real value
    complex operator/(complex &) const; // divide current complex by passed complex
    
    // boolean comparison operators
    bool operator==(const complex &) const; // is object == parameter?
    bool operator!=(const complex &) const; // is object != parameter?
    
    //assignment operators
    complex & operator+=(const complex &); //current object += parameter
    complex & operator-=(const complex &); //current object -= parameter
    complex & operator*=(const double &); //current object *= parameter
    complex & operator*=(const complex &); //current object *= parameter
    complex & operator/=(const double &); //current object /= parameter
    complex & operator/=(const complex &); //current object /= parameter
    
private:
    double x; // the real part
    double y; // the imaginary part
};




#endif /* defined(__complex__complex__) */
