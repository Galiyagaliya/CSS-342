// A Weight object holds weight in lbs and ozs.
//  Weight.h
//  Weight
//
//  Created by Galiya Shakenova on 08.04.15.
//  Copyright (c) 2015 Galiya Shakenova. All rights reserved.
// Implementations and assumptions:
// --Weight is stored as integers lbs and ozs
// --If lbs and ozs has a different sign, they must be converted to have the same sign
// --If ozs >= 16, it's converted into lb, and the remainder is ozs
// -- Print out an error message upon a zero division

#ifndef __weight__weight__
#define __weight__weight__

#include <stdio.h>
#include <iostream>
using namespace std;


class Weight {
    
    // overloaded <<:  prints lb and oz if both presented, if not, prints only either oz or lb
    friend ostream& operator<<(ostream&, const Weight&);
    // overloaded >>: Take two values as a lbs and an ozs value. If input values are doubles or floats, convert them into ints.
    friend istream& operator>>(istream&, Weight&);
public:
    //default constructor: paramteres are lbs and ozs resp;
    Weight(int = 0, int = 0);
    //
    int getPounds() const;
    int getOunces() const;
    //math operators
    Weight operator+(const Weight &) const; //add 2 Weights
    Weight operator-(const Weight &) const; //subtract 2 Weights
    Weight operator*(const double &) const; // multiply Weight by passed argument
    Weight operator/(const double &) const; // divide Weight by passed argument
    double operator/(const Weight &) const; // calculates the proportion between two objects
    Weight operator-() const; // Unary negation
    
    // boolean comparison operators
    bool operator>(const Weight &) const; // is object > parameter?
    bool operator<(const Weight &) const; // is object < parameter?
    bool operator>=(const Weight &) const; // is object >= parameter?
    bool operator<=(const Weight &) const; // is object <= parameter?
    bool operator==(const Weight &) const; // is object == parameter?
    bool operator!=(const Weight &) const; // is object != parameter?
    
    //assignment operators
    Weight& operator+=(const Weight &); //current object += parameter
    Weight& operator-=(const Weight &); //current object -= parameter
    Weight& operator*=(const double &); //current object *= parameter
    Weight& operator/=(const double &); //current object /= parameter
    Weight& operator==(const int &); //current object /= parameter
    
private:
    int lbs; // amount of pounds in Weight
    int ozs; // amount of ounces in Weight
    void getTotal(); // calculate total Weight in ounces
    
    
    
};

#endif /* defined(__Weight__Weight__) */


