#include "Hand.h"

//************************************************************************
//* IMPLENTATION OF HAND
//************************************************************************

// Constructor
Hand::Hand():CardCollection(){}

// Destructor
Hand::~Hand(){}

// Output
std::ostream& operator<< (std::ostream& os, const Hand& hand) {
    // Prints out each card in order, with a " " in front of them
    for ( int i=0; i<hand.size (); i++ ) {
        os << " " << hand.cardAt(i);
    }

    return os;
}
