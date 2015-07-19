#include "Deck.h"

#include <random>

//************************************************************************
//* IMPLENTATION OF DECK
//************************************************************************

// Constructor
Deck::Deck () : CardCollection(){
    // Add all cards into deck in order of:
    // CLUBS, DIAMOND, HEART, SPADE
    // AC, 2C ... AD, 2D ... AH, 2H ... AS, 2S ...
    reset ();
}

// Destructor
Deck::~Deck() {}

// Shuffle the deck using a seed
void Deck::shuffle(int seed) {
    static std::mt19937 rng(seed);

    int n = 52;

    while ( n > 1 ) {
        int k = (int) (rng() % n);
        --n;
        swapCard(n, k);
    }
}

void Deck::reset () {
    clear ();
    for(int i=0;i<SUIT_COUNT;i++){
        for (int j=0;j<RANK_COUNT;j++){
            addCard (Card (Suit(i), Rank(j)));
        }
    }
}

// Output
std::ostream& operator<< (std::ostream& os, const Deck& deck) {
    // Print deck in lines of 13 cards
    for ( int i=1; i<(deck.size()); i++ ) {
        os << (deck.cardAt(i-1));
        if (i%13 == 0) {
            os << std::endl;
        } else {
            os << " ";
        }
    }
    os << (deck.cardAt(deck.size() - 1));

    return os;
}
