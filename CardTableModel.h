#ifndef CARDTABLEMODEL_H
#define CARDTABLEMODEL_H

#include <vector>

#include "Subject.h"
#include "Card.h"

class CardTableModel : public Subject {
public:
	CardTableModel ();
	virtual ~CardTableModel ();

	void setCardVisible ( const Card );
	std::vector<Card> visibleCards () const;
	
private:
	std::vector<Card> visibleCards_;
};

#endif