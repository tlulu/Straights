#include "HandController.h"

HandController::HandController ( HandModel *model ) : model_ (model) {

}

HandController::~HandController () {

}

void HandController::addCardToHand ( const Card card ) {
	model_ -> addCard (card);
}

void HandController::removeCardFromHand ( const Card card ) {
	model_ -> removeCard (card);
}

void HandController::selectCardToPlay ( int index ) {
	model_ -> selectCard ( index );
}