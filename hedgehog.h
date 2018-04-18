#ifndef HEDGEHOG_H
#define HEDGEHOG_H

#include <iostream>
#include "card.h"

using namespace std;

class Hedgehog : public Card {
   // private:
    
    public:
    Hedgehog(void);
    virtual string render(int);    
};

#endif
