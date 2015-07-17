#ifndef HANDVIEW_H
#define HANDVIEW_H

#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/button.h>

#include "Observer.h"
#include "HandModel.h"
#include "HandController.h"
#include "CardImageManager.h"

class HandView : public Gtk::HBox, public Observer {
public:
	HandView ( HandModel*, HandController* );
	virtual ~HandView ();

	void update ();

protected:
	void onButtonClick ( int );

private:	
	HandModel *model_;
	HandController *controller_;

	Gtk::Image *images_[13];
	Gtk::Button *buttons_[13];
	CardImageManager imgManager_;

	Gtk::VBox selectedCardBox_;
	Gtk::Image selectedCardImage_;
	Gtk::Button playButton_;
};

#endif