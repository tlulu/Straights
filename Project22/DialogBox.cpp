#include "DialogBox.h"
#include <gtkmm/stock.h>
#include <gtkmm/main.h>
#include <iostream>
#include <stdlib.h>

DialogBox::DialogBox( Gtk::Window & parentWindow, 
                      std::string title, 
                      std::string message) : Dialog( title, parentWindow, true, true ) {

  Gtk::VBox* contentArea = this->get_vbox();
  Gtk::Button* content = new Gtk::Button();
  content -> set_label( message );

  contentArea -> add( *content );
  add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK );
  show_all_children();

  int result = run();

  switch(result){
     case Gtk::RESPONSE_OK:
      if ( title == "Game Over" ){
        exit(EXIT_SUCCESS);
      }
      break;  
  }
}

DialogBox::~DialogBox(){}