#ifndef CARDTABLEVIEW_H
#define CARDTABLEVIEW_H

#include <gtkmm/table.h>
#include <gtkmm/image.h>

#include "Observer.h"
#include "GameModel.h"
#include "GameController.h"
#include "Card.h"
#include "CardImageManager.h"


class CardTableView : public Gtk::Table, public Observer{
public:
	CardTableView (GameModel*, GameController*);
	virtual ~CardTableView ();

	void update ();
private:
	GameModel *model_;
	GameController *controller_;

	Gtk::Image *images_[52];
	CardImageManager imgManager_;
};

#endif