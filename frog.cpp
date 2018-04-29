#include "animals.h"

string Frog::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Frog   |";
        case 2: return "|  (1)-(1)  |";
        case 3: return "|  /_____\\  |";
        case 4: return "|  \\_____/  |";
        case 5: return "|           |";
        case 6: return "|  200/150  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Frog::Frog(void):Card("Frog", 2, 200, 150){
	return;
}
