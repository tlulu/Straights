#include <vector>

#include "HandView.h"

HandView::HandView ( HandModel *model, HandController *controller ) : model_ (model), controller_ (controller) {
	for ( int i = 0; i < 13; i++ ) {
		images_[i] = new Gtk::Image ( imgManager_.getBlankCard () );
		buttons_[i] = new Gtk::Button ();
		buttons_[i] -> set_image (*images_[i]);
		add (*buttons_[i]);

		buttons_[i]->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &HandView::onButtonClick),i));
	}

	selectedCardImage_.set( imgManager_.getBlankCard () );
	playButton_.set_label( "play" );
	selectedCardBox_.add (selectedCardImage_);
	selectedCardBox_.add (playButton_);

	add (selectedCardBox_);
}

HandView::~HandView () {
	for (int i = 0; i < 13; i++) {
		delete images_[i];
		delete buttons_[i];
	}

}

void HandView::update () {
	std::vector<Card> hand = model_ -> hand ();
	for (int i=0; i<hand.size(); i++) {
		Card c = hand[i];
		images_[i] -> set ( imgManager_.getImageForCard(c) );
	}

	for (int i=hand.size(); i<13; i++) {
		images_[i] -> set ( imgManager_.getBlankCard () );
	}

	Card *c = model_->selectedCard();
	if (c != NULL) {
		selectedCardImage_.set ( imgManager_.getImageForCard(*c) );
	} else {
		selectedCardImage_.set ( imgManager_.getBlankCard () );	
	}

}

void HandView::onButtonClick ( int index ) {
	controller_ -> selectCardToPlay (index);
}