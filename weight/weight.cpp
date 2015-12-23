//
//  weight.cpp
//  weight
//
//  Created by Galiya Shakenova on 10.04.15.
//  Copyright (c) 2015 Galiya Shakenova. All rights reserved.
//

#include "weight.h"
//  Weight.cpp
//  Weight holds two values - in lbs and in ozs
//
//  Created by Galiya Shakenova on 08.04.15.
//  Copyright (c) 2015 Galiya Shakenova. All rights reserved.
//
// Weight has two parts - lb and ounces.
// Takes zero, one, two parameters. Parameters have default values of 0, 1.


// constructor receives various primitive types such as int,
// float and double, converts those arguments into int,

// and initializes its private data: lbs and ozs with them.

#include "weight.h"

Weight::Weight(int a, int b) {
    lbs = a;
    ozs = b;
    getTotal();
    
}
// returns the lbs data member of this weight number.

int Weight::getPounds() const{
    return lbs;
    
}
// returns the ozs data member of this weight number

int Weight::getOunces() const{
    return ozs;
    
}
// returns the total Weight in oz

void Weight::getTotal() {
    lbs = (lbs*16 + ozs) / 16;
    ozs = (lbs*16 + ozs) % 16;
    
    
}
// Unary nagation,
// Distinguish unary negation from subtraction that requires binary operands

Weight Weight::operator-() const {
    Weight uNegation;
    uNegation.lbs = -lbs;
    uNegation.ozs = -ozs;
    return uNegation;
}
// operator+
// overloaded +: addition of 2 Weight, current object and parameter
// Result is calculated to lb and oz (oz < 16)

Weight Weight::operator+(const Weight & a) const {
    Weight added;
    added.lbs = (a.lbs + this->lbs);
    added.ozs = (a.ozs + this->ozs);
    added.getTotal();
    return added;
}
// Subtract the 2nd object from the 1st one.
// if lbs and ozs has a different sign, they are converted to have the same sign.

Weight Weight::operator-(const Weight& a) const {
    Weight sub;
    sub.lbs = (a.lbs - this->lbs);
    sub.ozs = (a.ozs - this->ozs);
    sub.getTotal();
    return sub;
}
// operator*
// overloaded *: multiplication of 2 Weights, current object and parameter
// Result is calculated to lb and oz (oz < 16)
Weight Weight::operator *(const double & a) const{
    Weight mult;
    int total = (this->lbs * 16 + this->ozs) * a;
    
    mult.ozs = total;
    mult.getTotal();
    return mult;
}
// operator/
// overloaded /: division of Weight by double, current object and parameter
// Result is calculated to lb and oz (oz < 16). Returns Weight

Weight Weight::operator/(const double & a) const {
    Weight div;
    if (a == 0) {
        cout << "ZERO DIVISION";
    }
    int total = (this->lbs * 16 + this->ozs) / a;
    div.ozs = total;
    div.getTotal();
    return div;
}
// operator/
// overloaded /: division of Weight by double, current object and parameter,
// Returns ratio of two objects

double Weight::operator/(const Weight & a) const {
    double result;
    int totalA = (a.lbs * 16 + a.ozs);
    int totalB = (this->lbs * 16 + this->ozs);
    if (totalA == 0) {
        cout << "ZERO DIVISON IS NOT ALLOWED";
    }
    result = double (totalB / totalA);
    return result;
}

// operator>
// overloaded >: true if current object is > parameter, otherwise false

bool Weight::operator>(const Weight & b) const {
    int totalB = (b.lbs * 16 + b.ozs);
    int total = (this->lbs * 16 + this->ozs);
    return total>totalB;
}
// operator<
// overloaded <: true if current object is > parameter, otherwise false

bool Weight::operator<(const Weight & b) const {
    int totalB = (b.lbs * 16 + b.ozs);
    int total = (this->lbs * 16 + this->ozs);
    return total<totalB;
}
// operator>=
// overloaded >=: true if current object is >= parameter, otherwise false

bool Weight::operator>=(const Weight & b) const {
    int totalB = (b.lbs * 16 + b.ozs);
    int total = (this->lbs * 16 + this->ozs);
    return total>totalB || total==totalB;
}
// operator<=
// overloaded <=: true if current object is <= parameter, otherwise false

bool Weight::operator<=(const Weight & b) const {
    int totalB = (b.lbs * 16 + b.ozs);
    int total = (this->lbs * 16 + this->ozs);
    return total<totalB || total==totalB;
}
// operator==
// overloaded ==: true if current object is == parameter, otherwise false

bool Weight::operator==(const Weight & b) const {
    int totalB = (b.lbs * 16 + b.ozs);
    int total = (this->lbs * 16 + this->ozs);
    return total==totalB;
    
}
// operator!=
// overloaded !=: true if current object is != parameter, otherwise false

bool Weight::operator!=(const Weight & b) const {
    int totalB = (b.lbs * 16 + b.ozs);
    int total = (this->lbs * 16 + this->ozs);
    return total!=totalB;
}
// operator+=
// overloaded +=: current object = current object + parameter

Weight& Weight::operator+=(const Weight & b) {
    int totalB = (b.lbs * 16 + b.ozs);
    int total = (this->lbs * 16 + this->ozs);
    this->lbs = (total + totalB) / 16;
    this->ozs = (total + totalB) % 16;
    
    return *this;
}

// operator-=
// overloaded +=: current object -= current object - parameter

Weight& Weight::operator-=(const Weight& b) {
    int totalB = (b.lbs * 16 + b.ozs);
    int total = (this->lbs * 16 + this->ozs);
    this->ozs = (total - totalB);
    getTotal();
    return *this;
}
//// operator*=
// overloaded *=: current object = current object * parameter

Weight& Weight::operator*=(const double & b) {
    int total = (this->lbs * 16 + this->ozs) * b;
    
    ozs = (total);
    getTotal();
    return *this;
}
Weight& Weight::operator==(const int & b) {
    this->lbs = b;
    this->ozs = 0;
    
    return *this;
}
// operator/=
// overloaded /=: current object = current object / parameter(double)

Weight &Weight::operator/=(const double &s) {
    double totalA = double (this->lbs * 16 + this->ozs) / s;
    this->lbs = int (totalA) / 16;
    this->ozs =int (totalA) % 16;
    
    return *this;
}
//The format is X lbs Y ozs, where X and Y are a lbs and ozs value respectively

ostream& operator<<(ostream &output, const Weight &r) {
    string l =  " lbs ";
    string o = " ozs";
    
    if (r.lbs == 0 && r.ozs == 0) {
        output << "0 oz";
        return output;
    }
    
    if (r.lbs == 1 || r.lbs == -1)
        l = " lb ";
    
    if (r.ozs == 1 || r.ozs == -1)
        o = " oz";
    
    if (r.lbs != 0)
        output << r.lbs << l;
    
    if (r.ozs != 0)
        output << r.ozs << o;
    
    return output;
}
//Take two values as a lbs and an ozs value. If input values are doubles or floats,
//convert them into ints

istream& operator>>(istream &input, Weight &w) {
    input >> w.lbs >> w.ozs;
    w.getTotal();
    return input;
    
}






