CXX = g++
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-2.4 --cflags --libs`
OBJS = GameWindow.o Subject.o Card.o CardTableController.o CardTableModel.o CardTableView.o CardImageManager.o HandModel.o HandController.o HandView.o GamePanelView.o PlayerView.o main.o
EXEC = main

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(EXEC)

main.o: main.cpp GameWindow.h
GameWindow.o: GameWindow.h CardTableView.h CardTableModel.h CardTableController.h Card.h HandView.h HandModel.h HandController.h GamePanelView.h PlayerView.h
Subject.o: Subject.h Observer.h
Card.o: Card.h
CardTableController.o: CardTableController.h BaseController.h CardTableModel.h Card.h
CardTableModel.o: CardTableModel.h Subject.h Card.h
CardTableView.o: CardTableView.h Observer.h CardTableModel.h CardTableController.h Card.h CardImageManager.h
CardImageManager.o: CardImageManager.h Card.h
HandModel.o: HandModel.h Subject.h Card.h
HandController.o: HandController.h BaseController.h HandModel.h Card.h
HandView.o: HandView.h Observer.h HandModel.h HandController.h CardImageManager.h
PlayerView.o: PlayerView.h Observer.h
GamePanelView.o: GamePanelView.h

clean:
	rm  $(OBJS) $(EXEC)
