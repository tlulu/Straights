#ifndef HANDVIEW_H
#define HANDVIEW_H

#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/button.h>
#include <gtkmm/dialog.h>

#include "Observer.h"
#include "GameModel.h"
#include "GameController.h"
#include "CardImageManager.h"

class HandView : public Gtk::HBox, public Observer {
public:
	HandView ( GameModel*, GameController* );
	virtual ~HandView ();

	void update ();

protected:
	void onHandButtonClick ( int );
	void onPlayButtonClick ();
	void onDiscardButtonClick ();
	void onRageQuitButtonClick ();

private:	
	GameModel *model_;
  GameController *controller_;

  CardImageManager imgManager_;

	Gtk::Image *images_[13];
	Gtk::Image selectedCardImage_;

	Gtk::VBox playOptionsList_;

	Gtk::Button *buttons_[13];
	Gtk::Button playButton_;
	Gtk::Button discardButton_;
	Gtk::Button rageQuitButton_;

	Gtk::Dialog dialogBox_;
};

#endif