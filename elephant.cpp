#include "elephant.h"

string Elephant::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|  Elephant |";
        case 2: return "|  _ __ _   |";
        case 3: return "| / |..| \  |";
        case 4: return "| \/ || \/  |";
        case 5: return "|  |_''_|   |";
        case 6: return "|  800/800  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Elephant::Elephant(void):Card("Elephant", 8, 800, 800){
    return;
}
