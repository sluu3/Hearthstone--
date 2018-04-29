#include "animals.h"

string Cow::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|    Cow    |";
        case 2: return "|   ()__()  |";
        case 3: return "|   <@ @>   |";
        case 4: return "|   {o_o}   |";
        case 5: return "|    (|)    |";
        case 6: return "|  300/400  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

Cow::Cow(void):Card("Cow", 3, 300, 400){
    return;
}
