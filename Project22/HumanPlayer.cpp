#include "HumanPlayer.h"
#include "Command.h"

#include <iostream>

//************************************************************************
//* IMPLENTATION OF HUMANPLAYER
//************************************************************************

//************************************************************************
// Human Player
//************************************************************************

/*** Protected Methods ***/

// Play a card
void HumanPlayer::play (Card card, Board& board) {
	Player::play (card, board);
}

// Discard a card
void HumanPlayer::discard (Card card) {
	Player::discard (card);
}

/*** Public Method ***/

// Constructor
HumanPlayer::HumanPlayer (int id): Player(id) {};

// Destructor
HumanPlayer::~HumanPlayer () {};

// Copy Constructor
HumanPlayer::HumanPlayer (const Player& player) : Player(player) {};

bool HumanPlayer::playable () const {
	return true;
}

// Player takes turn
TurnResult HumanPlayer::takeTurn (const Deck& deck, Board& board) {
	// Hand hand = getLegalPlays( deck, board);						// Get the legal plays

	// std::cout << board << std::endl;								// Display current board
	// std::cout << "Your hand:" << currentHand() << std::endl;		// Display player's hand
	// std::cout << "Legal plays:" << hand << std::endl;				// Display player's legal plays

	// // Depending on the command, player may be able to redo their turn
	// bool replay = true;
	// do {
	// 	Command c;													// Get player's command
	// 	std::cout << ">";
	// 	std::cin >> c;

	// 	try {
	// 		switch (c.type) {
	// 			case PLAY:
	// 				play (c.card, board, hand);						// Player plays a card
	// 				replay = false;									// Does not replay
	// 				break;
	// 			case DISCARD:
	// 				discard (c.card, hand);							// Player discards a card
	// 				replay = false;									// Does not replay
	// 				break;
	// 			case DECK:
	// 				std::cout << deck << std::endl;					// Player wants to see the deck, replay turn
	// 				break;
	// 			case QUIT:											// Player quits, terminate the turn, return QUIT status
	// 				return Quit;
	// 			case RAGEQUIT:										// Player ragequits, terminate the turn, return RAGEQUIT status
	// 				return RageQuit;
	// 			default:
	// 				break;
	// 		}
	// 	} catch (const PlayerException &e) {
	// 		std::cout << e.message () << std::endl;							// Player tries to do an illegal move, display error, replay turn
	// 	}
	// } while (replay);

	return Nothing;													// Turn ends successfully
}