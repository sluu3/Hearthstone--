#include "dog.h"

string Dog::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Dog    |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Dog::Dog(void):Card("Dog", 3, 400, 400){
    return;
}
