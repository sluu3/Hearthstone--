#include "giraffe.h"

string Giraffe::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|  Giraffe  |";
        case 2: return "|   ^_^     |";
        case 3: return "|   \  \    |";
        case 4: return "|    ----   |";
        case 5: return "|     | |   |"
        case 7: return "|   200/100 |";
        case 6: return "|___________|";
        default:
            return " ";
    }
}

Giraffe::Giraffe(void):Card("Giraffe", 1, 200, 100){
	return;
}