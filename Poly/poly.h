//
//  poly.h
// ------------------------------------------------ Poly---------------------------------------------------------------
// Galiya Shakenova CSS 343 A
// Creation Date: 10/04/2015
// Date of Last Modification: 10/09/15
// --------------------------------------------------------------------------------------------------------------------
// Constructs Polynomial, performs different math operations with polynomials
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// -- The Polynomial has only nonnegative exponents
// -- it is expected that a user enters one coefficient and an exponent repeatedly, Enters -1 for both when done;
// -- All entered data is valid (all integers)
// -- For the coefficient of a non-existent term, returns zero
// --------------------------------------------------------------------------------------------------------------------

//

#ifndef ____poly__
#define ____poly__

#include <stdio.h>

#include <iostream>

using namespace std;


class Poly
{
    // overloaded <<
    friend ostream& operator<<(ostream&, const Poly&);
    // overloaded >>
    friend istream& operator>>(istream&, Poly&);
    
public:
// ---------------------------------------------Constructor------------------------------------------------------------
    Poly(int = 0, int = 0);
    Poly(const Poly &p);
    
// ---------------------------------------------Destructor------------------------------------------------------------
    virtual ~Poly();
    
// --------------------------------------------------------------------------------------------------------------------
    int getCoeff(int) const;
    void setCoeff(int, int);
    
// ---------------------------------------------Math operators---------------------------------------------------------
    
    Poly operator+(const Poly &); //add polynomials
    Poly operator-(const Poly &); //subtract 2 polynomials
    Poly operator*(const Poly &); // multiply 3 polynomials
    
// ----------------------------------------Boolean comparison operators-------------------------------------------------
    
    bool operator==(const Poly &) const; // is object == parameter?
    bool operator!=(const Poly &) const; // is object != parameter?
    
// ----------------------------------------Assignment operators---------------------------------------------------------
    Poly& operator=(const Poly& ); // assign polynomial to the other
    Poly& operator+=(const Poly& ); // adds passed polynomial to this
    Poly& operator-=(const Poly& ); // subtructs passed polynomial from this
    Poly& operator*=(const Poly& ); // multiplies 2 polynomials
    
protected:
    
private:
    int size;
    int* polynom;
};


#endif /* defined(____poly__) */
