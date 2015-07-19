#include "CardTableView.h"

CardTableView::CardTableView (GameModel *model, GameController *controller) : Gtk::Table (4, 13, true), 
																			model_ (model), 
																			controller_ (controller) {


	set_col_spacings (5);

	// Attatch blank images to each cell
	for (int i=0; i<52; i++) {
		images_[i] = new Gtk::Image ( imgManager_.getBlankCard() );
	}

	for (int i = 0; i < 52; i++) {
		attach (*images_[i], i%13, i%13+1, i/13, i/13+1);
	}

	show_all ();

}

CardTableView::~CardTableView () {
	for (int i = 0; i < 52; i++) {
		delete images_[i];
	}
}

void CardTableView::update () {
	// Reset all cell to blank image
	for (int i=0; i<52; i++) {
		images_[i] -> set ( imgManager_.getBlankCard() );
	}
		
	// Update the board based on the model
	Board *board = model_ -> board ();
	for (int i = 0; i < board -> size(); i++) {
		Card c = board -> cardAt(i);

		images_[c.getRank()+c.getSuit()*13] -> set ( imgManager_.getImageForCard (c) );
	}
}