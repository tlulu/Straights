#include "GameController.h"

//************************************************************************
// Base Exception
//************************************************************************

GameController::GameException::GameException () {}

GameController::GameException::~GameException () {}

//************************************************************************
// Illegal Play Exception
//************************************************************************

GameController::IllegalPlayException::IllegalPlayException () {};

GameController::IllegalPlayException::~IllegalPlayException () {};

std::string GameController::IllegalPlayException::message () const {
	return "This is not a legal play.";
}

//************************************************************************
// Illegal Discard Exception
//************************************************************************

GameController::IllegalDiscardException::IllegalDiscardException () {};

GameController::IllegalDiscardException::~IllegalDiscardException () {};

std::string GameController::IllegalDiscardException::message () const {
	return "You have a legal play. You may not discard.";
}

GameController::GameController ( GameModel *model ) : model_ (model) {

}

GameController::~GameController () {

}

void GameController::joinGame ( int index ) {
	model_ -> changeComputerToHuman ( index );
}

void GameController::startGame () {
	// shuffle deck
	model_ -> shuffle ();

	// Deal card
	model_ -> dealCardToPlayers ();

	// Set current player
	model_ -> setCurrentPlayer ();

	// Player turn
	computerTurnLoop ();
}

void GameController::playCard () {
	if ( model_ -> canPlayCard () ) {
		model_ -> playCard ();
		model_ -> nextPlayer ();
		computerTurnLoop ();
	} else {
		throw IllegalPlayException ();
	}
}

void GameController::selectCardToPlay ( int index ){
	model_ -> setCurrentSelectedCard ( index );
}

void GameController::discardCard () {
	if ( model_ -> canDiscardCard () ) {
		model_ -> discardCard ();
		model_ -> nextPlayer ();
		computerTurnLoop ();
	} else {
		throw IllegalDiscardException ();
	}
}

void GameController::rageQuit () {
	model_ -> changeCurrentPlayerToComputer ();
	computerTurnLoop ();
}

void GameController::computerTurnLoop () {
	while ( model_ -> currentPlayerIsComputer () ) {
		model_ -> takeTurnForCurrentPlayer ();
		model_ -> nextPlayer ();
	}
}