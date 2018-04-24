#include "card.h"

using namespace std;

string Card::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
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

Card::Card(string n, int mc, int atk, int def){
    name = n;
    manaCost = mc;
    attack = atk;
    defense = def;
    exhausted = true;
}

string Card::getName(){
    return name;   
}

int Card::getManaCost(){
    return manaCost;   
}

int Card::getAttack(){
    return attack;
}

int Card::getDefense(){
    return defense;
}

bool Card::isExhausted(){   //DOUBLE CHECK
    return exhausted;   
}

void Card::unExhaust(){      //DOUBLE CHECK
    exhausted = false;
}
