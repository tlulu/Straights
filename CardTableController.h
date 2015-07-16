#ifndef CARDTABLECONTROLLER_H
#define CARDTABLECONTROLLER_H

#include "BaseController.h"
#include "CardTableModel.h"
#include "Card.h"

class CardTableController : public BaseController {
public:
	CardTableController ( CardTableModel* );
	virtual ~CardTableController ();

	void showCard ( const Card ) const;
private:
	CardTableModel *model_;
};

#endif