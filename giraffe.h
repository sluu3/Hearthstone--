#ifndef GIRAFFE_H
#define GIRAFFE_H

#include <iostream>
#include "card.h"

using namespace std;

class Giraffe : public Card {
   // private:
    
    public:
    Giraffe(void);
    virtual string render(int);    
};

#endif