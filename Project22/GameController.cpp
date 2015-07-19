#include "GameController.h"
#include <iostream>
#include <gtkmm/main.h>
#include <vector>

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
	model_ -> setGameInProgress (true);

	// shuffle deck
	model_ -> shuffle ();

	// Deal card
	model_ -> dealCardToPlayers ();

	// Set current player
	model_ -> setCurrentPlayer ();

	// Player turn
	computerTurnLoop ();
}

void GameController::newGame ( int seed ) {
	model_ -> refreshWithSeed( seed );
}

void GameController::endRound () {
	if ( model_ -> turnCount() == 52 ){
		std::vector<Player*> players = model_ -> winningPlayers();
		if ( players.size() == 0 ){
			model_ -> reset();
		}
	}
}

void GameController::playCard () {
	if ( model_ -> canPlayCard () ) {
		model_ -> playCard ();
		model_ -> nextPlayer ();
		endRound();
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
		endRound();
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
	std::cout << "computer" << std::endl;
	while ( model_ -> currentPlayerIsComputer () ) {
		std::cout << "aaa" << std::endl;
		model_ -> takeTurnForCurrentPlayer ();
		model_ -> nextPlayer ();
		endRound();
	}
}