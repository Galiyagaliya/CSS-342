//  Created by Galiya Shakenova on 24.04.15.
//  Dragon.h
//  Turtle
// Dragon class draws a complex fractal figure using recursive calls
// That can be described folloqing way :
// -- Starting from a base segment, replace each segment by 2 segments
//  with a right angle and with a rotation of 45° alternatively to the
// right and to the left

// Assumptions:
//   -- all parameters and data members are float.
//   -- functions take two arguments: the depth of level and the length
//        of each line segment.
//   -- Outputs are in postscript format.


#ifndef __Turtle__Dragon__
#define __Turtle__Dragon__

#include <stdio.h>
#include "turtle.h"
#include <iostream>
#include <math.h>

using namespace std;

class Dragon : Turtle {
public:
   
    Dragon( float initX=0.0, float initY=0.0, float initAngle=0.0 );
    void leftCurve( int l, float d );  //draw a level-l left curve with dist d
    void rightCurve( int l, float d ); //draw a level-l right curve with dist d
};

#endif /* defined(__Turtle__Dragon__) */
