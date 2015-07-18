#include <sstream>

#include "CardImageManager.h"

CardImageManager::CardImageManager () {
	for ( int i = 0; i < 52; i++ ) {
		std::ostringstream os;
		os << "img/" << (i/13) << "_" << (i%13) << ".png";

		Glib::RefPtr< Gdk::Pixbuf > card = Gdk::Pixbuf::create_from_file ( os.str() );
		cardImages_.push_back (card);
	}

	Glib::RefPtr< Gdk::Pixbuf > card = Gdk::Pixbuf::create_from_file ( "img/nothing.png" );
	cardImages_.push_back (card);
}

CardImageManager::~CardImageManager () {

}

Glib::RefPtr< Gdk::Pixbuf > CardImageManager::getImageForCard ( const Card card ) {
	return cardImages_[card.getSuit()*13+card.getRank()];
}

Glib::RefPtr< Gdk::Pixbuf > CardImageManager::getBlankCard () {
	return cardImages_[52];
}

