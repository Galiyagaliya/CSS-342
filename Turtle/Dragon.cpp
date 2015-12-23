//
//  Dragon.cpp
//  Turtle
// Dragon class draws a complex fractal figure using recursive calls
// The Dragon curve, while not being exactly the same at all resolutions,
// still is constructed from previous iterations, and maintains the same
//  basic shape.
//  Created by Galiya Shakenova on 24.04.15.
//  Copyright (c) 2015 Galiya Shakenova. All rights reserved.
//

#include "Dragon.h"
//------------------------- Dragon -----------------------------------------
Dragon::Dragon( float initX, float initY, float initAngle )
: Turtle( initX, initY, initAngle ) {
}

//------------------------------ leftCurve ----------------------------------
// draw a level-k left curve with dist d
void Dragon::leftCurve( int level, float d ) {
    if ( level > 0 ) {
        leftCurve(level-1, d);
        turn(90);
        rightCurve(level-1, d);
        turn(90);
        
 
    }
    else
        draw( d );
}

//------------------------------ rightCurve ---------------------------------
// draw a level-k right curve with dist d
void Dragon::rightCurve( int level, float d ) {
    if ( level > 0 ) {
        turn(-90);
        leftCurve(level-1, d);
        turn(-90);
        rightCurve(level-1, d);
   
    }
    else
        draw( d );
}