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

	// Change the default computer player to human
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

	// Restart the game with a new seed
	model_ -> refreshWithSeed( seed );
}

bool GameController::endRound () {
	// Check of the turn count is 52
	if ( model_ -> turnCount() % 52 == 0 ){
		std::vector<Player*> players = model_ -> winningPlayers();
		// Check for any winners
		if ( players.size() == 0 ){
			model_ -> reset();
		} else {
			// Return true if there is a winner
			return true;
		}
	}
	return false;
}

void GameController::playCard () {
	if ( model_ -> canPlayCard () ) {
		// If the player can play this card, play it, and go to the next player
		model_ -> playCard ();
		model_ -> nextPlayer ();
		endRound();
		computerTurnLoop ();
	} else {
		// Otherwise throw exception
		throw IllegalPlayException ();
	}
}

void GameController::selectCardToPlay ( int index ){
	model_ -> setCurrentSelectedCard ( index );
}

void GameController::discardCard () {
	if ( model_ -> canDiscardCard () ) {
		// If the player can discard the card, discard it, and go to the next player
		model_ -> discardCard ();
		model_ -> nextPlayer ();
		endRound();
		computerTurnLoop ();
	} else {
		// Otherwise throw exception
		throw IllegalDiscardException ();
	}
}

void GameController::rageQuit () {
	// Turn human to computer player
	model_ -> changeCurrentPlayerToComputer ();
	// Restart its turn
	computerTurnLoop ();
}

void GameController::computerTurnLoop () {
	// Keep looping as long as its a computer's turn
	while ( model_ -> currentPlayerIsComputer () ) {
		model_ -> takeTurnForCurrentPlayer ();
		model_ -> nextPlayer ();
		bool end = endRound();
		// Break if a winner is found
		if ( end ) {
			break;
		}
	}
}