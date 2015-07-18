#include "Card.h"
#include "Board.h"

#include <algorithm>

//************************************************************************
//* IMPLENTATION OF BOARD
//************************************************************************

// Constructor
Board::Board():CardCollection(){}

// Destructor
Board::~Board(){}

bool Board::isLegalPlay(const Card& card) const{
    // If the board is empty, then 7S is legal
    if (size() == 0) {
        return card == Card (SPADE, SEVEN);
    }

    // Check of the card has rank 7, or has the same suit and adjecent rank as other cards played on the board
    for (int i=0;i<size();i++){
        Card temp = cardAt(i);
        if ( ( card.getSuit () == temp.getSuit () &&  abs ( card.getRank () - temp.getRank () ) == 1 ) || ( card.getRank () == SEVEN ) ) {
            return true;
        }
    }
    return false;
}
    
// Print all cards on board
//  - Seperate into suits
//  - Rank in increasing order
std::ostream& operator<< (std::ostream& os, const Board& board) {
    os << "Cards on the table:" << std::endl;

    std::vector<Card> temp;
    for (int i=0; i<board.size(); i++) {
        temp.push_back (board.cardAt (i));
    }
    sort(temp.begin(), temp.end());

    os << "Clubs:";
    for (int i=0; i<temp.size (); i++) {
        if (temp[i].getSuit() == CLUB) {
            os << " " << temp[i].getRankString();
        }
    }
    os << std::endl;

    os << "Diamonds:";
    for (int i=0; i<temp.size (); i++) {
        if (temp[i].getSuit() == DIAMOND) {
            os << " " << temp[i].getRankString();
        }
    }
    os << std::endl;

    os << "Hearts:";
    for (int i=0; i<temp.size (); i++) {
        if (temp[i].getSuit() == HEART) {
            os << " " << temp[i].getRankString();
        }
    }
    os << std::endl;

    os << "Spades:";
    for (int i=0; i<temp.size (); i++) {
        if (temp[i].getSuit() == SPADE) {
            os << " " << temp[i].getRankString();
        }
    }

    return os;    
}

