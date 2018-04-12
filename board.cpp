#include <iostream>
#include <vector>
#include "board.h"

using namespace std;

Board::Board(){
    hp = 2000;
}

void Board::addToDeckList(Card* c){
    if(deck.size() <= 21){
        deck.push_back(c);   
    }
}

void Board::draw(int num){
    Card* temp; 
    int j = 20;
    for(int i = 0; i < num; i++){
        temp = deck[j];
        j--;
        deck.pop_back();
        hand.push_back(temp);       
    }
}

void Board::playCardFromHand(int indx){
    Card* temp = hand[indx];
    field.push_back(hand[indx]);
    mana -= temp->getManaCost();
}

Card* Board::getCardOnField(int indx){
    return field[indx];
}

Card* Board::getCardInHand(int indx){
    return hand[indx];
}

int Board::getHP(){
    return hp;   
}

int Board::getHandSize(){
    return hand.size();   
}

int Board::getFieldSize(){
    return field.size();   
}

int Board::getMana(){
    return mana;   
}

void Board::setMana(int m){
    mana = m;
}

void Board::discardCardFromField(int indx){
    Card* temp = field[indx];
    discard.push_back(temp);
    field.erase(field.begin() + indx);  //SHOULD ERASE CARD AT INDEX... DOUBLE CHECK
}

void Board::unExhaustField(){
    
}

void Board::shuffleDeck(void){
    Card * temp;
    int numOfShuffles = 100;
    int idx1, idx2;
    for(int i = 0; i < numOfShuffles; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        temp = deck[idx1];
        deck[idx1] = deck[idx2];
        deck[idx2] = temp;
    }
}


void Board::renderMana(void){
    cout << "MANA: ";
    for(int i = 1; i <= maxMana; i++){
        if(i <= mana)
            cout << "@ ";
        else
            cout << "O ";
    }
        
    cout << endl;
}

void Board::renderHand(void){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void Board::renderField(void){
    if(field.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < field.size(); j++){
                cout << field[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}