
// ------------------------------------------------ Poly--------------------------------------------------------
// Galiya Shakenova CSS 343 A
// Creation Date: 10/04/2015
// Date of Last Modification: 10/09/15
// --------------------------------------------------------------------------------------------------------------
// Constructs Polynomial, performs different math operations with polynomials
// --------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// -- The Polynomial has only nonnegative exponents
// -- it is expected that a user enters one coefficient and an exponent repeatedly, Enters -1 for both when done;
// -- All entered data is valid (all integers)
// -- For the coefficient of a non-existent term, returns zero
// ---------------------------------------------------------------------------------------------------------------

#include "poly.h"
#include <stdio.h>
#include <iostream>

// ------------------------------------Constructor--------------------------------------------------
// Constructs a polynomial
// Parameters are an exponent and a coefficient respectively
// Takes zero, one, two parameters. Parameters have default values of 0, 0
// if exponent is negative, or parameters are missing assigns values to 0^0
// -------------------------------------------------------------------------------------------------


Poly::Poly(int coeff, int expon)
{
    if( expon < 0 )
    {
        coeff = expon = 0;
    }
    
    size = expon + 1; // the size is the largest exponent + 1
    polynom = new int[size]();
    for (int i = 0; i < size; i++)
    {
        polynom[i] = 0;
    }
    polynom[expon] = coeff; // set the coefficient to the value
}

// ------------------------------------Constructor---------------------------------------------------
// Constructs the exact copy of the given polynomial
// --------------------------------------------------------------------------------------------------
Poly::Poly(const Poly &p)
{
    polynom = new int[p.size];
    size = p.size;
    
    for (int i = 0; i < size; i++)
        polynom[i] = p.polynom[i];
}

// ------------------------------------Destructor---------------------------------------------------
// Deletes the polynomial pointer, freeing the memory.
// -------------------------------------------------------------------------------------------------
Poly::~Poly()
{
    delete [] polynom;
    polynom = NULL;
}

// ------------------------------------Overload >>--------------------------------------------------
// Overload >>: input all coefficient (sets all terms of one Poly, in a loop)
// Expected that user enters one coefficient and an exponent repeatedly, enters -1 for both
// when done
// -------------------------------------------------------------------------------------------------

istream& operator>>( istream& in, Poly& rhs ) {
    int term;
    int exp;
    bool positive = true;
    
    while(positive) { // stops adding terms once they are -1
        in >> term;
        in >> exp;
        
        if (term == -1 && exp == -1)
        {
            positive = false;
        }
        
        else
        {
            rhs.setCoeff(term, exp);
        }
    }
    
    return in;
}

// ------------------------------------Overload <<--------------------------------------------------
// overloaded <<:
// -- prints " +coeff x^pow" or " -coeff x^pow" (with one blank before sign) for nonzero coeff
// -- A power of 1 is not displayed
// -- x is not shown for all power of 0
// -- Doesn't output a term if the coeff is 0, unless all coeff are 0, then prints "0"
// -------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& os, const Poly& rhs)
{
    bool zeros = true;
    
    for (int i = 0; i < rhs.size; i++) // check whether all coefficients are not zero
    {
        if (rhs.polynom[i] != 0)
        {
            zeros= false;
        }
    }
    
    // outputs one "0" if all coeff are zero
    if (zeros)
    {
        os <<  "0";
        return os;
    }
    
    // starts to print from the largest exponent
    for (int i = rhs.size - 1; i >= 0; i--)
    {
        if(rhs.polynom[i] != 0)
        {
            if(i > 1) // power > 1 is dispayed
            {
                
                os << ((rhs.polynom[i] > 0) ? " +":" "); // check whether a coeff > 0, prints +
                os << rhs.polynom[i] << "x^" << i;
                
            }
            
            else if (i == 1) //outputs no power of 1
            {
                if(rhs.size >= 1)
                    os << ((rhs.polynom[i] > 0) ? " +":" ");
                os << rhs.polynom[i] << "x";
                
            }
            
            else if (i == 0) // if pow is 0, outputs only coeff
            {
                os << ((rhs.polynom[i] > 0)? " +":" ");
                os << rhs.polynom[i];
                
            }
        }
    }
    return os;
}

// --------------------------------------setCoeff--------------------------------------------------
// -- Assigns the coefficient of the passed parameter.
// -- First parameter is the new coefficient to be set.
// -- Second parameter is the exponent of the parameter to be replaced.
// -------------------------------------------------------------------------------------------------
void Poly::setCoeff(int coef, int exp)
{
    if (exp >= 0)
    {
        if ((exp +1) > size)
        {
            int *temp = new int[exp + 1];
            
            for (int i = 0; i < size; i++)
            {
                temp[i] = polynom[i];
            }
            
            for (int j = size; j < (exp + 1); j++)
            {
                temp[j] = 0;
            }
            
            temp[exp] = coef; //set coeff value in specified location
            
            delete [] polynom;
            polynom = NULL;
            polynom = temp;
            temp = NULL;
            size = exp + 1; //set new size
        }
        else
        {
            polynom[exp] = coef;
        }//set coeff value in specified location
    }
}

// --------------------------------------getCoeff--------------------------------------------------
// Returns the coefficient of the given power
// ------------------------------------------------------------------------------------------------
int Poly::getCoeff(int power) const
{
    if (power < 0 || power >= size)
    {
        return 0;
    }
    return polynom[power];
    
}

// ---------------------------------------Operator+ ------------------------------------------------
// Add two Polynomials, and return new Polynomial object of the sum
// -------------------------------------------------------------------------------------------------
Poly Poly::operator+(const Poly& p) 
{
    
    int sizePoly = (this->size >= p.size) ? this->size:p.size;
    
    Poly newP(0, sizePoly - 1);
    newP.size = sizePoly;
    
    for(int i = 0; i < size; i++)
    {
        newP.polynom[i] = 0;
    }
    
    for (int i = 0; i < this->size; i++)
    {
        newP.polynom[i] = this->polynom[i];
    }
    
    for (int j = 0; j < p.size; j++) {
        newP.polynom[j] = newP.polynom[j] + p.polynom[j];
    }
    
    return newP;
}

// ---------------------------------------Operator- ------------------------------------------------
// Subtructing two Polynomials, and return new Polynomial object of the subtraction
// -------------------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly & p)
{
    
    int sizePoly = (this->size >= p.size) ? this->size:p.size;
    Poly newP(0, sizePoly - 1);
    
    for(int i = 0; i < size; i++)
    {
        newP.polynom[i] = 0;
    }
    
    for (int i = 0; i < this->size; i++)
    {
        newP.polynom[i] = this->polynom[i];
    }
    for (int j = 0; j < p.size; j++) {
        newP.polynom[j] = newP.polynom[j] - p.polynom[j];
    }
    return newP;
}

// ---------------------------------------Operator* ------------------------------------------------
// Multiplying two polynomials, return result as a Polynomial
// -------------------------------------------------------------------------------------------------
Poly Poly::operator*(const Poly & p)
{
 
        int largest_lhs = size - 1;
        int largest_rhs = p.size - 1;
        int temp_size = largest_lhs + largest_rhs + 1;
        
        Poly temp(0, temp_size-1);
        
        for(int i = 0; i < temp.size; i++)
        {
            temp.polynom[i] = 0;
        }
    
        for(int i = 0; i < size; i++)
        {
            
            for(int j = 0; j < p.size; j++)
            {
                temp.polynom[i + j] += (polynom[i] * p.polynom[j]);
            }
            
        }
    
        return temp;
}

// ---------------------------------------Operator= ------------------------------------------------
// Set the polynomial to the passed parameter, returns *this
// -------------------------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& p) {
    if (this == &p)
    {
        return *this;
    }
    
    delete [] polynom;
    polynom = NULL;
    polynom = new int[p.size];
    size = p.size;
    
    for (int i = 0; i < size; i++)
    {
        polynom[i] = p.polynom[i];
    }
    
    return *this;
    
}

// ---------------------------------------Operator==------------------------------------------------
// returns true if this polynomial equals to the passed polynomial
// -------------------------------------------------------------------------------------------------
bool Poly::operator==(const Poly & p) const {
    if (this->size != p.size)
    {
        return false;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (polynom[i] !=p.polynom[i])
        {
            return false;
        }
        
    }
    
    return true;
}

// ---------------------------------------Operator!=------------------------------------------------
// Returns false if this polynomial equals to the passed polynomial
// -------------------------------------------------------------------------------------------------
bool Poly::operator!=(const Poly & p) const {
    return !(*this == p);
}

// ---------------------------------------Operator+=------------------------------------------------
// Adds this polynomial to the passed parameter
// -------------------------------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly& p) {
    
    *this = *this + p;
    return *this;
}

// ---------------------------------------Operator-=------------------------------------------------
// Subtructing from this polynomial a passed parameter
//--------------------------------------------------------------------------------------------------

Poly& Poly::operator-=(const Poly& p) {
    *this = *this - p;
    return *this;
}

// ---------------------------------------Operator*=------------------------------------------------
// Multiplying this polynomial to the passed polynomial
//--------------------------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly& p) {
    
    *this = *this * p;
    
    return *this;
}


