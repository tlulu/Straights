#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>

#include "Observer.h"
#include "GameModel.h"
#include "GameController.h"
#include "Hand.h"

class PlayerView : public Gtk::Frame, public Observer {
public:
  PlayerView ( GameModel*, GameController*, int );
  virtual ~PlayerView ();

  void update ();

protected:
  void onJoinButtonClick ();

private:
  int playerId_;

  GameModel *model_;
  GameController *controller_;
  
  Gtk::VBox vBox_;

  Gtk::HBox pointsBox_;
  Gtk::HBox discardsBox_;

  Gtk::Label pLabel_;
  Gtk::Label pointsLabel_;

  Gtk::Label dLabel_;
  Gtk::Label discardsLabel_;

  Gtk::Button joinButton_;

};

#endif