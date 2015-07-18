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
	//HandView ( GameModel*, GameController* );
	HandView ( HandModel*, HandController* );
	virtual ~HandView ();

	void update ();

protected:
	void onHandButtonClick ( int );
	void onPlayButtonClick ();
	void onDiscardButtonClick ();
	void onRageQuitButtonClick ();

private:	
	//GameModel *model_;
  //GameController *controller_;

	HandModel *model_;
	HandController *controller_;

	Gtk::Image *images_[13];
	Gtk::Button *buttons_[13];
	CardImageManager imgManager_;

	Gtk::Image selectedCardImage_;
	Gtk::VBox playOptionsList_;
	Gtk::Button playButton_;
	Gtk::Button discardButton_;
	Gtk::Button rageQuitButton_;
};

#endif