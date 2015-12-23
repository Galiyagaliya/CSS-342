
// a Complex object presents the complex number X+Yi, where X and Y are real numbers and
// i^2 is -1. Typically, X is called a real part and Y is an imaginary part of the complex number.
// (square root of -1)
//
//  Created by Galiya Shakenova on 12.04.15.
//  Copyright (c) 2015 Galiya Shakenova. All rights reserved.
//
#include <limits>
#include <iostream>
#include "complex.h"

// Complex
// Parameters are real and imaginary part respectively
// Takes zero, one, two parameters. Parameters have default values of 0.0, 0.0
complex::complex(double a, double b): x(a), y(b) { // create a new object with the given real
}                                                  // and imaginary parts

// return the real part
double complex::getReal() {
    return this->x;
}

// return imaginary part
double complex::getImaginary() {
    return this->y;
}

// overloaded <<: prints X+Yi, where X and Y are a Real and Imaginary value respectively.
// if either X or Y is 0, it is not displayed.
// if both X and Y are 0, the output is 0.
// if X is 1, it's printed out as 1, and that if Y is 1, its output is i
ostream& operator<<(ostream &output, const complex &r) {
    if (r.y == 0) {
        return output << r.x << "";
    }
    string real = "+";
    if (r.y < 0)
        real = "";
    
    if (r.x != 0)
        output << r.x << real;
    
    if (r.y == 1)
        output <<  "i";
    
    if (r.y == -1)
        output <<  "-i";
    
    if (r.y != 1 && r.y != -1)
        output << r.y << "i";
    
    return output;
}

// overloaded >>: take two values as a real and imaginary value
istream& operator>>(istream& input, complex & a) {
    input >> a.x >> a.y;
    return input;
}

// operator +
// overloaded +: sum of the two complex objects
// return a new Complex object whose value is (this + a)
complex complex::operator+(const complex & a) const{
    complex sum (a.x + this->x, a.y + this->y);
    return sum;
    
}

// The complex conjugate of the complex number z = x + yi is defined to be x − yi
// return a new conjugated complex object
complex complex::conjugate() {
    complex conj (this->x, -(this->y));
    return conj;
}

// operator -
// overloaded -: subtraction of two complex numbers, current object and parameter
// return a new Complex object whose value is (this - b)
complex complex::operator-(const complex & b) const {
    complex sub (this->x - b.x, this->y - b.y);
    return sub;
}

// operator *
// overloaded *: scalar multiplication of current complex number
// return a new object whose value is (this * alpha)
complex complex::operator*(const double & alpha) const {
    complex mult (alpha * this->x, alpha * this->y);
    return mult;
}

// operator *
// overloaded *: multiplication of two complex objects
// return a new Complex object whose value is (this * a)
complex complex::operator*(const complex & a) const {
    complex mult (this->x * a.x - this->y * a.y,
                  this->x * a.y + this->y * a.x);
    
    return mult;
}

// operator /
// overloaded /: division of current object by parameter
// division by zero returns complex infinity
// returns new complex object whose value (this / a)
complex complex::operator/(complex & a) const {
    complex div;
    double scalar = (a.x * a.x + a.y * a.y);
    
    if (scalar == 0.0) {
        div.x = numeric_limits<double>::infinity();
        div.y = 0.0;
    } else {
        div.x = (this->x * a.x + this->y * a.y) / scalar;
        div.y = (this->y * a.x - this->x * a.y) / scalar;
    }
    
    return div;
}

// operator ==
// overloaded ==: true if current object == parameter
// Two complex numbers are equal if and only if both
// their real and imaginary parts are equal
bool complex::operator==(const complex & c) const {
    return this->x == c.x && this->y == c.y;
}

// operator !=
// overloaded !=: true if current object != parameter
bool complex::operator!=(const complex & c) const {
    return this->x != c.x && this->y != c.y;
}

// operator +=
// overloaded +=: sum of the two complex objects
// return a current Complex object whose value is (this + a)
complex& complex::operator+=(const complex & c) {
    this->x += c.x;
    this->y += c.y;
    return *this;
}

// operator -=
// overloaded -=: subtraction of two complex numbers, current  object
// and parameter; return a current Complex object whose value is (this - c)
complex & complex::operator-=(const complex & c) {
    this->x -= c.x;
    this->y -= c.y;
    return *this;
}

// operator *=
// overloaded *=: multiplication of current object and scalar
// return a current Complex object whose value is (this * alpha)
complex & complex::operator*=(const double & alpha) {
    this->x *= alpha;
    this->y *= alpha;
    return *this;
}

// operator *=
// overloaded *: multiplication of two complex objects
// return a current Complex object whose value is (this * z)
complex & complex::operator*=(const complex & z) {
    double x = this->x;
    this->x = this->x * z.x - this->y * z.y;
    this->y = x * z.y + this->y * z.x;
    return *this;
}

// operator /=
// overloaded /=: division of current object by parameter
// division by zero returns complex infinity
// returns a current complex object whose value (this / c)
complex & complex::operator/=(const double & c) {
    if (c == 0.0) {
        this->x = numeric_limits<double>::infinity();
        this->y = 0.0;
    } else {
    this->x /= c;
    this->y /= c;
    }
    return *this;
}

// operator /=
// overloaded /=: division of current object by second object
// division by zero returns complex infinity
// returns a current complex object whose value (this / a)
complex & complex::operator/=(const complex & a) {
    double scalar = a.x * a.x + a.y * a.y;
    double x = this->x;
        if (scalar == 0.0) {
            this->x = numeric_limits<double>::infinity();
            this->y = 0.0;
        } else {
            this->x = (this->x * a.x + this->y * a.y) / scalar;
            this->y = (this->y * a.x - x * a.y) / scalar;
        }
    return *this;
}

