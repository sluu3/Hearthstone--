#include "animals.h"

string Cat::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Cat    |";
        case 2: return "|   |\\_/|   |";
        case 3: return "|   'o.o'   |";
        case 4: return "|   =(_)=   |";
        case 5: return "|     U     |";
        case 6: return "|  300/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Cat::Cat(void):Card("Cat", 2, 300, 100){
    return;
}
