#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "card.h"

using namespace std;

class Bear : public Card {
   // private:
    
    public:
    Bear(void);
    virtual string render(int);    
};

#endif