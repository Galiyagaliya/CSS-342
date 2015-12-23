//
//  main.cpp
//  complex
//
//  Created by Galiya Shakenova on 12.04.15.
//  Copyright (c) 2015 Galiya Shakenova. All rights reserved.
//

#include <iostream>
#include "complex.h"

using namespace std;
int main( ) {
    
    complex b1, b2(1, 0), b3(1, 1), b4(2, -1), b5(2), b6, b7(9, 8);
    
    cout << "type two doubles for b6: "; // check input function
    cin >> b6;
    
    cout << "b1 = " << b1 << endl; // output is 0
    cout << "b2 = " << b2 << endl; // output is 1
    cout << "b3 = " << b3 << endl; // output is 1+i (checks if output is i when imag is 1)
    cout << "b4 = " << b4 << endl; // output is 2-i (checks if output is -i when imag is -1)
    cout << "b5 = " << b5 << endl; // output is 2 (constructor receives 1 argum)
    cout << "b6 = " << b6 << endl; // output is input value
    cout << "b7 = " << b7 << endl; // output is 9+8i
    
    cout << "b1 + b2 + b3 = " << b1 + b2 + b3 << endl; // output of sum is 2+i
    cout << "b5 - b3 - b2= " << b5 - b3 - b2<< endl; // output of subtraction is -i
    cout << "b4 * 4 = " << b4 * 4 << endl; // output of multipl by scalar is 8-4i
    cout << "b2 * b4 = " << b2 * b4 << endl; // output of multipl by complex 2-i
    cout << "b2 / b1 = " << b2 / b1 << endl; // division by zero is complex infinity
    cout << "b4 / b5 = " << b4 / b5 << endl; // output of division by complex is 1- 0.5i
    
    
    cout << "b2 == b2 is " << ( ( b2 == b2 ) ? "true" : "false" ) << endl; // b2 is equal b2
    cout << "b4 != b4 is " << ( ( b4 != b4 ) ? "true" : "false" ) << endl; // b4 is equal b4 so it's false
    
    cout<< "Conjugate of " << b3 << " is " << b3.conjugate()<<endl; // conjugate is 1+i
    cout<< "Real of " << b3 << " is " << b3.getReal()<<endl; // real of b3 is 1
    cout<< "Imaginary of " << b7 << " is " << b7.getImaginary()<<endl; // imag is 8
    
    cout << "(b5 += b2) += b3 is " << ( (b5 += b2) += b3 ) << endl; // b5 is 4+i
    cout << "(b5 -= b7) is " << ( (b5 -= b7)) << endl; // b5 is -5-7i
    cout << "(b7 *= 5) *= 2 is " << ( (b7 *= 5) *= 2 ) << endl; // b7 is 90+80i
    cout << "(b5 *= b4) is " << ( (b5 *= b4)) << endl; // b5(-5-7i) * b4(2-i) = -17 - 9i (Wolfram alpha calcul)
    cout << "(b2 /= 2) " << (b2 /= 2) << endl; // b4(1, 0) / 2 = 0.5
    cout << "b4 is " << b4 << endl; // b4 is 2-i
    cout << "(b4 /= b1) = " << ((b4 /= b1 )) << endl; // b4 / b1(0.0, 0.0) is complex infinity
    cout << "b4 is " << b4 << endl; // b4 is infinity
}