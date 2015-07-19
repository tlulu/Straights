# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -O -g -std=c++0x `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = main.o Board.o Card.o CardCollection.o Command.o ComputerPlayer.o Deck.o GameModel.o Hand.o HumanPlayer.o Player.o GameController.o HandView.o GamePanelView.o PlayerView.o CardTableView.o GameWindow.o CardImageManager.o
EXEC = straights

# ****************************************************

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)


main.o: main.cpp GameController.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Board.o: Board.h Card.h

Card.o: Card.h

CardCollection.o: CardCollection.h Card.h

Command.o: Command.h Card.h

ComputerPlayer.o: ComputerPlayer.h Player.h

Deck.o: CardCollection.h Deck.h

GameModel.o: GameModel.h Card.h Player.h HumanPlayer.h ComputerPlayer.h Board.h Deck.h Observer.h

Hand.o: Hand.h CardCollection.h Card.h

HumanPlayer.o: HumanPlayer.h Player.h

Player.o: Player.h Deck.h Card.h Board.h

GameController.o: GameController.h GameModel.h Card.h

GameWindow.o: GameWindow.h CardTableView.h GameModel.h GameController.h Card.h HandView.h GamePanelView.h PlayerView.h

CardTableView.o: CardTableView.h Observer.h GameModel.h GameController.h Card.h CardImageManager.h

CardImageManager.o: CardImageManager.h Card.h

HandView.o: HandView.h Observer.h GameModel.h GameController.h CardImageManager.h

PlayerView.o: PlayerView.h Observer.h GameModel.h GameController.h

GamePanelView.o: GamePanelView.h GameModel.h GameController.h


clean:
	rm -rf $(OBJS) $(EXEC)