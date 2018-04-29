#include "animals.h"

string Pig::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Pig    |";
        case 2: return "| '..'____  |";
        case 3: return "| (@@)    |@|";
        case 4: return "|     |- -| |";
        case 5: return "|           |";
        case 6: return "|  350/300  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Pig::Pig(void):Card("Pig", 3, 350, 300){
    return;
}
