#include <iostream>

#include "CardTableController.h"

CardTableController::CardTableController (CardTableModel *model) : model_(model) {

}

CardTableController::~CardTableController () {

}

void CardTableController::showCard ( const Card card ) const {
	//std::cout << "Controller" << std::endl;
	model_ -> setCardVisible ( card );
}