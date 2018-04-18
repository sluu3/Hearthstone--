#ifndef FROG_H
#define FROG_H

#include <iostream>
#include "card.h"

using namespace std;

class Frog : public Card {
   // private:
    
    public:
    Frog(void);
    virtual string render(int);    
};

#endif
