#ifndef PIG_H
#define PIG_H

#include <iostream>
#include "card.h"

using namespace std;

class Pig : public Card {
   // private:
    
    public:
    Pig(void);
    virtual string render(int);    
};

#endif
