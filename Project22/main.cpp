#include <gtkmm.h>
#include "GameWindow.h"

int main ( int argc, char *argv[] ) {
	Gtk::Main kit( argc, argv );

	GameWindow window;

	Gtk::Main::run( window );

	return 0;
}