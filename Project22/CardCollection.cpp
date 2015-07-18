#include "CardCollection.h"

//************************************************************************
//* IMPLENTATION OF CARDCOLLECTION
//************************************************************************

// Constructor
CardCollection::CardCollection(){}

// Destructor
CardCollection::~CardCollection(){}

bool CardCollection::hasCard(const Card& card) const {
    for (int i=0;i<cards_.size();i++){
        if ((cards_[i]) == (card)) {
            return true;
        }
    }
    return false;
}

Card CardCollection::cardAt(int index) const {
	return cards_[index];
}

void CardCollection::addCard(Card card) {
    cards_.push_back(card);
}

void CardCollection::removeCard(Card card) {
    for(int i=0;i<cards_.size();i++){
        if (card==cards_[i]){
            cards_.erase (cards_.begin()+(i));
        }
    }
}

void CardCollection::swapCard(int from, int to) {
	Card temp = cards_[from];
	cards_[from] = cards_[to];
	cards_[to] = temp;
}

int CardCollection::size() const {
	return cards_.size();
}

void CardCollection::clear(){
	cards_.clear();
}