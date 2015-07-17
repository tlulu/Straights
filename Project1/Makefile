# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++0x

# ****************************************************
# Targets needed to bring the executable up to date

straights: main.o Board.o Card.o CardCollection.o Command.o ComputerPlayer.o Deck.o GameController.o Hand.o HumanPlayer.o Player.o
	$(CXX) $(CXXFLAGS) -o straights main.o Board.o Card.o CardCollection.o Command.o ComputerPlayer.o Deck.o GameController.o Hand.o HumanPlayer.o Player.o

# The main.o target can be written more simply

main.o: main.cpp GameController.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Board.o: Board.h Card.h

Card.o: Card.h

CardCollection.o: CardCollection.h Card.h

Command.o: Command.h Card.h

ComputerPlayer.o: ComputerPlayer.h Player.h

Deck.o: CardCollection.h Deck.h

GameController.o: GameController.h Card.h CardCollection.h Player.h HumanPlayer.h ComputerPlayer.h Board.h Deck.h

Hand.o: Hand.h CardCollection.h Card.h

HumanPlayer.o: HumanPlayer.h Player.h

Player.o: Player.h Deck.h Card.h Board.h

