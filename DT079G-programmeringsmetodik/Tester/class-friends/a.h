/*
Filename: a.h
Created by Linus Sjöbro on 2017-12-29.
*/

#ifndef a_h
#define a_h

#include <stdio.h>
#include "b.h"

class a {
public:
    a();
    ~a();
    friend class b;

private:
};

#endif
