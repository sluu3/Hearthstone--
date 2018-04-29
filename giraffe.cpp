#include "giraffe.h"

string Giraffe::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|  Giraffe  |";
        case 2: return "|    /)/)   |";
        case 3: return "|   (. .\\   |";
        case 4: return "|   /'-._)  |";
        case 5: return "|  /#/      |";
        case 6: return "|   200/100 |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Giraffe::Giraffe(void):Card("Giraffe", 2, 200, 100){
	return;
}