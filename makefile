CXX = g++
CXXFLAGS = -std=c++11

SRC_DIR = .
SRC_FILES = main.cpp Floor.cpp FloorState.cpp Full.cpp SpaceAvailable.cpp MaitreD.cpp OrderComponent.cpp Order.cpp OrderItem.cpp Group.cpp GroupState.cpp Bun.cpp Patty.cpp BeefPatty.cpp ChickenPatty.cpp Side.cpp Salad.cpp Chips.cpp Drink.cpp Milkshake.cpp Soda.cpp Garnish.cpp Lettuce.cpp Tomato.cpp GroupIterator.cpp ItemIterator.cpp Chef.cpp HeadChef.cpp MeatChef.cpp DrinkChef.cpp SidesChef.cpp GarnishChef.cpp Plate.cpp Pass.cpp Colleague.cpp Waiter.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(EXECUTABLE)

%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)

run:
	./main

debug:
	valgrind ./main
