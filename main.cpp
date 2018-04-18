#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "goblin.h"
#include "bear.h"
#include "frog.h"
#include "giraffe.h"
#include "hedgehog.h"
#include "rabbit.h"
#include "cow.h"
#include "dog.h"
#include "elephant.h"
#include "cat.h"
#include "pig.h"
#include "card.h"

using namespace std;

void getOpponentAction(Board&, Board&);
void renderBoard(Board&, Board&);

int main(int argc, char * arv[]){
    int turn, c;
    srand(time(0));
    
    // Set up Player board
    Board pb;  
    // Create player deck and draw initial hand here:
     
    for (int i = 0; i < 20; i++){
        c = rand() % 11;
        Card* cards;
        switch(c){
            case 0: cards = new Goblin();
                break;
            case 1: cards = new Bear();
                break;
            case 2: cards = new Frog();
                break;
            case 3: cards = new Giraffe();
                break;
            case 4: cards = new Hedgehog();
                break;
            case 5: cards = new Rabbit();
                break;
            case 6: cards = new Elephant();
                break;
            case 7: cards = new Cat();
                break;
            case 8: cards = new Dog();
                break;
            case 9: cards = new Pig();
                break;
            case 10: cards = new Cow();
                break;
            default: cards = new Goblin();
                break;
        }
        pb.addToDeckList(cards); 
    }
    
    pb.draw(2);
    pb.renderHand();
      
    
    // Set up opponent board
    Board ob;
    // Create opponent deck and draw initial hand here:
    /*
    while(pb.getHP() > 0 && ob.getHP() > 0){
        // Take turns here:

        turn++;
    }
    */
    
    return 0;
}


void renderBoard(Board & pb, Board & ob){
    // Render opponent field
    ob.renderField();
    cout << endl;
    // Render player field
    pb.renderField();
    pb.renderHand();
    
    pb.renderMana();
    cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;
    
    //clearScreen(1);
}

void getOpponentAction(Board & playerBoard, Board & opponentBoard){
    // Go through hand and play cards that the opponent can afford to play
    for(int i = 0; i < opponentBoard.getHandSize(); i++){
        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana()){
            //opponentBoard.playCardFromHand(opponentBoard/*,i */);
            opponentBoard.playCardFromHand(i);
        }
        renderBoard(playerBoard, opponentBoard);
    }
   
    // Attack with all creatures not exhausted
    for(int i = 0; i < opponentBoard.getFieldSize(); i++){
        if(!opponentBoard.getCardOnField(i)->isExhausted()){
            // get target for attack
            // look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() > opponentBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destory creature
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " destoryed your " << playerBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
                playerBoard.discardCardFromField(targetIndex);
                renderBoard(playerBoard, opponentBoard);
            } else {
                // opponent's creature attacks player directly
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " attacks you directly for " << opponentBoard.getCardOnField(i)->getAttack() << " damage!" << endl;
                playerBoard.setHP(playerBoard.getHP() - opponentBoard.getCardOnField(i)->getAttack());
            }
        }
                
    }
}
