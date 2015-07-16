#include "HandModel.h"

HandModel::HandModel () {

}

HandModel::~HandModel () {

}

void HandModel::addCard ( const Card card ) {
	hand_.push_back ( card );
}

std::vector<Card> HandModel::HandModel () const {
	return hand_;
}