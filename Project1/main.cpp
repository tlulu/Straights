#include "GameController.h"

#include <cstdlib>

using namespace std;

int main (int argc, char* argv[]) {

	int seed = 0;

	// Grab seed from argument
	if (argc > 1) {
		seed = atoi(argv[1]);
	}

	// Create game controller
	GameController gm (4, seed);
	// Start the game
	gm.startGame ();

	return 0;
}