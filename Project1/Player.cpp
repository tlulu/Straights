#include "Player.h"

//************************************************************************
//* IMPLENTATION OF PLAYER
//************************************************************************

// Constructor, set score to 0
Player::Player (int id) : id_(id), currentScore_(0), totalScore_(0) {}

// Destructor
Player::~Player () {}

// Copy constructor, copy id, scores, hand, discarded hand
Player::Player (const Player& player) : id_(player.id_),
										currentScore_(player.currentScore_),
										totalScore_(player.totalScore_),
										currentHand_(player.currentHand_),
										discardedHand_(player.discardedHand_) {}

// Output player
std::ostream& operator<< (std::ostream& os, const Player& player) {
	os << "player " << player.id ();
	return os;
}

int Player::id () const {
	return id_;
}

int Player::currentScore () const {
	return currentScore_;
}

int Player::totalScore () const {
	return totalScore_;
}

// Prepare player for next round
void Player::refreshPlayer () {
	totalScore_ += currentScore_;		// Add total score
	currentScore_ = 0;					// Reset current score
	discardedHand_.clear ();			// Remove discarded cards
}

bool Player::hasCard (const Card& card) const {
	return currentHand_.hasCard (card);
}

void Player::addCard (Card card) {
	currentHand_.addCard (card);
}

// Check for legal plays a player have
// A legal play is:
//	- Card in player's hand
//	- 7 of anything
//	- Card with the same suit and adjecent rank as any card on board
Hand Player::getLegalPlays (const Deck& deck, const Board& board) const {
	Hand hand;
	for (int i=0; i<deck.size(); i++) {
		Card temp = deck.cardAt(i);
		if (currentHand_.hasCard(temp)){	// Check if player has card
			if (board.isLegalPlay(temp)){	// Check if it's a legal play in the board
				hand.addCard(temp);			// Add card to possible legal plays
			}
		}
	}
	return hand;	// Return legal plays
}

Hand Player::currentHand () const {
	return currentHand_;
}

void Player::addScore( int  score ){
	currentScore_+=score;
}

void Player::printDiscardedHand () const{
	std::cout << "Player " << id_ << "'s discards:" << discardedHand_ << std::endl;
}

void Player::printScore () const {
	std::cout << "Player " << id_ << "'s score: " << totalScore_ << " + " << currentScore_ << " = " << totalScore_+currentScore_ << std::endl;
}

// Player plays a card
void Player::play (Card card, Board& board, const Hand& legalPlays ) {
	currentHand_.removeCard( card );	// Remove card from hand
	board.addCard( card );				// Add card to board
	std::cout << "Player " << id_ << " plays " << card << "." << std::endl;
}

// Player discards a card
void Player::discard (Card card, const Hand& legalPlays) {
	currentHand_.removeCard( card );	// Remove card from hand
	discardedHand_.addCard( card );		// Add card to discarded pile
	addScore( card.getScore() );		// Add score
	std::cout << "Player " << id_ << " discards " << card << "." << std::endl;
}
