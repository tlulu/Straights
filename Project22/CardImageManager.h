#ifndef CARDIMAGEMANAGER_H
#define CARDIMAGEMANAGER_H

#include <gdkmm/pixbuf.h>
#include <vector>

#include "Card.h"

class CardImageManager {
public:
	CardImageManager ();
	virtual ~CardImageManager ();

	Glib::RefPtr< Gdk::Pixbuf > getImageForCard ( const Card card );
	Glib::RefPtr< Gdk::Pixbuf > getBlankCard ();

private:
	std::vector< Glib::RefPtr< Gdk::Pixbuf > > cardImages_;
};

#endif