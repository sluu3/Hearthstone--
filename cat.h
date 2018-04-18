#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "card.h"

using namespace std;

class Cat : public Card {
   // private:
    
    public:
    Cat(void);
    virtual string render(int);    
};

#endif
