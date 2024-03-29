#include <vector>

#include "HandView.h"

HandView::HandView ( HandModel *model, HandController *controller ) : model_ (model), controller_ (controller) {
	for ( int i = 0; i < 13; i++ ) {
		images_[i] = new Gtk::Image ( imgManager_.getBlankCard () );
		buttons_[i] = new Gtk::Button ();
		buttons_[i] -> set_image (*images_[i]);
		add (*buttons_[i]);

		buttons_[i]->signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &HandView::onHandButtonClick),i));
	}

	selectedCardImage_.set( imgManager_.getBlankCard () );
	playButton_.set_label( "play" );
	discardButton_.set_label( "discard" );
	rageQuitButton_.set_label( "rage quit" );

	playOptionsList_.add (playButton_);
	playOptionsList_.add (discardButton_);
	playOptionsList_.add (rageQuitButton_);

	playButton_.signal_clicked().connect( sigc::mem_fun( *this, &HandView::onPlayButtonClick ) );
	discardButton_.signal_clicked().connect( sigc::mem_fun( *this, &HandView::onDiscardButtonClick ) );
	rageQuitButton_.signal_clicked().connect( sigc::mem_fun( *this, &HandView::onRageQuitButtonClick ) );

	add (selectedCardImage_);
	add (playOptionsList_);
}

HandView::~HandView () {
	for (int i = 0; i < 13; i++) {
		delete images_[i];
		delete buttons_[i];
	}

}

void HandView::update () {

	//std::vector<Card> hand = model_ -> getCurrentPlayerHand();

	std::vector<Card> hand = model_ -> hand();
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

void HandView::onHandButtonClick ( int index ) {
	controller_ -> selectCardToPlay (index);
}

void HandView::onPlayButtonClick () {
	// controller_ -> playHandCard();
}

void HandView::onDiscardButtonClick () {
	// controller_ -> discardHandCard();
}

void HandView::onRageQuitButtonClick () {
	// controller_ -> rageQuit();
}