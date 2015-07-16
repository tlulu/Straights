CXX = g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = GameWindow.o Subject.o Card.o CardTableController.o CardTableModel.o CardTableView.o main.o
EXEC = main

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

main.o: main.cpp GameWindow.h
GameWindow.o: GameWindow.h CardTableView.h CardTableModel.h CardTableController.h Card.h
Subject.o: Subject.h Observer.h
Card.o: Card.h
CardTableController.o: CardTableController.h BaseController.h CardTableModel.h Card.h
CardTableModel.o: CardTableModel.h Subject.h Card.h
CardTableView.o: CardTableView.h Observer.h CardTableModel.h CardTableController.h Card.h

clean:
	rm  $(OBJS) $(EXEC)
