#ifndef HANDCONTROLLER_H
#define HANDCONTROLLER_H

#include "BaseController.h"
#include "HandModel.h"
#include "Card.h"

class HandController : public BaseController {
public:
	HandController ( HandModel* );
	virtual ~HandController ();

	void addCardToHand ( const Card );
	void removeCardFromHand ( const Card );
	void selectCardToPlay ( int );

private:
	HandModel *model_;
};

#endif