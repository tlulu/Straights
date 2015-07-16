#include "CardTableModel.h"

CardTableModel::CardTableModel () {

}

CardTableModel::~CardTableModel () {

}

void CardTableModel::setCardVisible ( const Card card ) {
	visibleCards_.push_back ( card );

	notify ();
}

std::vector<Card> CardTableModel::visibleCards () const {
	return visibleCards_;
}

