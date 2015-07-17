#ifndef HANDMODEL_H
#define HANDMODEL_H

#include <vector>

#include "Subject.h"
#include "Card.h"

class HandModel : public Subject {
public:
	HandModel ();
	virtual ~HandModel ();

	void addCard ( const Card );
	void removeCard ( const Card );
	void selectCard ( int );

	std::vector<Card> hand () const;
	Card* selectedCard () const;

private:
	std::vector<Card> hand_;
	Card *selectedCard_;
};

#endif