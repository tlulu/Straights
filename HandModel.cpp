#include <algorithm>

#include "HandModel.h"

HandModel::HandModel () {

}

HandModel::~HandModel () {

}

void HandModel::addCard ( const Card card ) {
	hand_.push_back ( card );

	notify ();
}

void HandModel::removeCard ( const Card card ) {
	std::vector<Card>::iterator p = std::find( hand_.begin(), hand_.end(), card );
	if ( p != hand_.end() ) {
		hand_.erase (p);
	}

	notify ();
}

void HandModel::selectCard ( int index ) {
	delete selectedCard_;
	if ( index < hand_.size() ) {
		selectedCard_ = new Card (hand_[index].getSuit(), hand_[index].getRank() );
	} else {
		selectedCard_ = NULL;
	}

	notify ();
}

std::vector<Card> HandModel::hand () const {
	return hand_;
}

Card* HandModel::selectedCard () const {
	return selectedCard_;
}