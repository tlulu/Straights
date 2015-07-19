#ifndef CARDIMAGEMANAGER_H
#define CARDIMAGEMANAGER_H

////////////////////////////////////////////////////////////

// Manages the images for cards

////////////////////////////////////////////////////////////

#include <gdkmm/pixbuf.h>
#include <vector>

#include "Card.h"

class CardImageManager {
public:
	CardImageManager ();
	virtual ~CardImageManager ();

	Glib::RefPtr< Gdk::Pixbuf > getImageForCard ( const Card card );	// Returns the image for a card
	Glib::RefPtr< Gdk::Pixbuf > getBlankCard ();						// Returns the image for a blank card

private:
	std::vector< Glib::RefPtr< Gdk::Pixbuf > > cardImages_;				// Stores the buffer for the cards
};

#endif