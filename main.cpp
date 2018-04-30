#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "board.h"
#include "card.h"
#include "animals.h"

using namespace std;

void getOpponentAction(Board&, Board&);
void renderBoard(Board&, Board&);
void randomCards(Card*&, int);
void getPlayerAction(Board&, Board&);

int main(int argc, char * arv[]){
    int c, r, coin, maxMana = 1, turnNum = 0;
	bool turn;
    srand(time(0));

    // Set up Player board
    Board pb;
    // Create player deck and draw initial hand here:

    for (int i = 0; i < 20; i++){
        c = rand() % 11;
        Card* cards;
        randomCards(cards, c);
        pb.addToDeckList(cards);
    }
    pb.draw(5);

    // Set up opponent board
    Board ob;
    // Create opponent deck and draw initial hand here:

	for (int i = 0; i < 20; i++){
		r = rand() % 11;
		Card* obCards;
		randomCards(obCards, r);
		ob.addToDeckList(obCards);
	}
	ob.draw(5);

	bool pbFirst = false;

	coin = (rand() % 2);
	if (coin == 0){
		turn = true;
		pbFirst = true;
		cout << "You will go first!" << endl;
	}else{
		turn = false;
		cout << "The computer will go first!" << endl;
	}


    while(pb.getHP() > 0 && ob.getHP() > 0){
	    pb.setMaxMana(maxMana);
	    ob.setMaxMana(maxMana);
	    if(turn){
            cout << "Your turn!" << endl;
            pb.draw(5 - pb.getHandSize());
            renderBoard(pb, ob);
            pb.setMana(pb.getMana() + 1);
            pb.renderMana();
            cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;
            getPlayerAction(pb, ob);
            turn = false;
            pb.setMana(maxMana++);

        }else{
            ob.setMana(ob.getMana() + 1);
            ob.draw(5 - ob.getHandSize());
            cout << "Opponents turn!" << endl;
            getOpponentAction(pb, ob);
            turn = true;
            turnNum++;

        }


    }

}

void getPlayerAction(Board& pb, Board& ob){
	int i, j, attack = 0;
	cout << endl;
	while(i != 2) {
        cout << "0: Play card from hand" << endl << "1: Attack with Creature" << endl << "2: End Turn" << endl;
        cin >> i;

        if (i == 0) {
            pb.showHand();
            cout << "What card to play (100 to go back)? ";
            cin >> j;
            while (j >= pb.getHandSize() && j != 100){
                cout << "Invalid choice. Choose again: ";
                cin >> j;
            }
            if (j != 100){
                if (pb.getCardInHand(j)->getManaCost() <= pb.getMana()) {
                    pb.playCardFromHand(j);
                }else {
                    cout << "You don't have enough mana" << endl;
                }
            }

            renderBoard(pb, ob);
            pb.renderMana();
            cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;

        } else if (i == 1) {
            if (pb.getFieldSize() > 0){
                cout << "Card to attack opponent's creature: ";
                pb.showField();
                cin >> j;
                while(j >= pb.getFieldSize()){
                    cout << "Invalid choice. Choose again." << endl;
                    cin >> j;
                }
                if (!pb.getCardOnField(j)->isExhausted()) {
                    cout << "Who/what to attack: ";
                    ob.showField();
                    cout << "100: Attack opponent directly.";
                    cin >> attack;
                    while(attack >= ob.getFieldSize() && attack != 100){
                        cout << "Invalid choice. Choose again." << endl;
                        cin >> attack;
                    }

                    if (attack != 100 && pb.getCardOnField(j)->getAttack() > ob.getCardOnField(attack)->getDefense()) {
                        cout << "Your " << pb.getCardOnField(j)->getName() << " destroyed the enemies " << ob.getCardOnField(attack)->getName()
                             << endl;
                        ob.discardCardFromField(attack);
			pb.getCardOnField(j)->reExhaust;
                    }
                    else if(attack == 100){
                        cout << "You attack the opponent directly." << endl;
			pb.getCardOnField(j)->reExhaust();
                        ob.setHP(ob.getHP() - pb.getCardOnField(j)->getAttack());
                        cout << "The opponent's HP is now: " << ob.getHP() << endl;
			    if(ob.getHP() <= 0){
				    cout << "Congratulations, you won!" << endl;
				    break;
			    }
                    }
                    pb.attacked(j); //Decreases the mana
                    renderBoard(pb, ob);
                    pb.renderMana();
                    cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;
                } else {
                    cout << "This creature is exhausted, pick again." << endl;
                }
            }else{
                cout << "You do not have any cards in your hand." << endl;
            }
        } else if (i != 0 && i != 1 && i != 2) {
            cout << "Invalid choice. Choose again." << endl;
        }
    }
    for (int i = 0; i < pb.getFieldSize(); i++){
	    pb.getCardOnField(i)->unExhaust();
	}
}

void randomCards(Card* &cards, int c){
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
}

void renderBoard(Board & pb, Board & ob){
    // Render opponent field
    ob.renderHand();
    ob.renderField();

    cout << endl;
    // Render player field
    pb.renderField();
    pb.renderHand();


    //clearScreen(1);
}

void getOpponentAction(Board & playerBoard, Board & opponentBoard){

// Go through hand and play cards that the opponent can afford to play

    for(int i = 0; i < opponentBoard.getHandSize(); i++){
        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana()){
            opponentBoard.playCardFromHand(i);
        }

    }
    renderBoard(playerBoard, opponentBoard);
    opponentBoard.renderMana();
    cout << "HP: " << playerBoard.getHP() << " Opponent's HP: " << opponentBoard.getHP() << endl;
// Attack with all creatures not exhausted
    for(int i = 0; i < opponentBoard.getFieldSize(); i++){
        if(!opponentBoard.getCardOnField(i)->isExhausted()){
// get target for attack
// look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() >
                   opponentBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
// destory creature
                cout << "Opponent's " <<
                     opponentBoard.getCardOnField(i)->getName() << " destoryed your " <<
                     playerBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
                playerBoard.discardCardFromField(targetIndex);
                renderBoard(playerBoard, opponentBoard);
                opponentBoard.renderMana();
                cout << "HP: " << playerBoard.getHP() << " Opponent's HP: " << opponentBoard.getHP() << endl;
            } else {
// opponent's creature attacks player directly
                cout << "Opponent's " <<
                     opponentBoard.getCardOnField(i)->getName() << " attacks you directly for "
                     << opponentBoard.getCardOnField(i)->getAttack() << " damage!" << endl;
                playerBoard.setHP(playerBoard.getHP() -
                                  opponentBoard.getCardOnField(i)->getAttack());
            }
        }

    }
}
