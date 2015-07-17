#ifndef CARDTABLEVIEW_H
#define CARDTABLEVIEW_H

#include <gtkmm/table.h>
#include <gtkmm/image.h>

#include "Observer.h"
#include "CardTableModel.h"
#include "CardTableController.h"
#include "Card.h"
#include "CardImageManager.h"


class CardTableView : public Gtk::Table, public Observer{
public:
	CardTableView (CardTableModel*, CardTableController*);
	virtual ~CardTableView ();

	void update ();
private:
	CardTableModel *model_;
	CardTableController *controller_;

	Gtk::Image *images_[52];
	CardImageManager imgManager_;
};

#endif