#include "animals.h"

string Rabbit::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|   Rabbit  |";
        case 2: return "|  /)   (\\  |";
        case 3: return "|  \\|   |/  |";
        case 4: return "|   ( ""''"" )  |";
        case 5: return "|      ^    |";
        case 6: return "|  200/125  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Rabbit::Rabbit(void):Card("Rabbit", 1, 200, 125){
	return;
}
