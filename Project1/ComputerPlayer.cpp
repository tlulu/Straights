#include "ComputerPlayer.h"

// Constructor
ComputerPlayer::ComputerPlayer (int id): Player(id) {};

// Destructor
ComputerPlayer::~ComputerPlayer () {};

// Copy constructor
ComputerPlayer::ComputerPlayer (const Player &player) : Player(player) {};

TurnResult ComputerPlayer::takeTurn (const Deck& deck, Board& board) {
	Hand hand = getLegalPlays( deck, board);				// Get the legal plays using current hand and board

	if (hand.size () == 0) {
		Player::discard (currentHand().cardAt(0), hand);	// Discard the first card of there are no legal plays
	} else {
		Player::play (hand.cardAt(0), board, hand);			// Play the first legal play
	}

	return Nothing;
}