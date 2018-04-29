#include "dog.h"

string Dog::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Dog    |";
        case 2: return "|   /^ ^\\   |";
        case 3: return "|  / 0 0 \\  |";
        case 4: return "|  V\\ Y /V  |";
        case 5: return "|   / - \\   |";
        case 6: return "|  350/250  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Dog::Dog(void):Card("Dog", 2, 350, 250){
    return;
}
