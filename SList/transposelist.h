//
//  transposelist.h
//  Assignment5
//
//  Created by Galiya Shakenova on 20.05.15.
//  Copyright (c) 2015 Galiya Shakenova. All rights reserved.
//

#ifndef __Assignment5__transposelist__
#define __Assignment5__transposelist__
#include <iostream>
#include "dlist.h"

using namespace std;

template<class Object>
class TransposeList : public DList<Object> {
public:
    int find( const Object &obj );
};

#include "transposelist.cpp.h"
#endif /* defined(__Assignment5__transposelist__) */
