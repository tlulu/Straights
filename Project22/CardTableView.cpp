#include "CardTableView.h"

CardTableView::CardTableView (CardTableModel *model, CardTableController *controller) : Gtk::Table (4, 13, true), 
																			model_ (model), 
																			controller_ (controller) {

	set_col_spacings (5);

	for (int i=0; i<52; i++) {
		images_[i] = new Gtk::Image ( imgManager_.getBlankCard() );
	}

	for (int i = 0; i < 52; i++) {
		attach (*images_[i], i%13, i%13+1, i/13, i/13+1);
	}

}

CardTableView::~CardTableView () {
	for (int i = 0; i < 52; i++) {
		delete images_[i];
	}
}

void CardTableView::update () {

	std::vector<Card> visibleCards = model_ -> visibleCards ();
	for (int i = 0; i < visibleCards.size(); i++) {
		Card c = visibleCards[i];

		images_[c.getRank()+c.getSuit()*13] -> set ( imgManager_.getImageForCard (c) );
	}

	show_all ();
}