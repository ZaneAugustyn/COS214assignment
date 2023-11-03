CXX = g++
CXXFLAGS = -std=c++11

SRC_DIR = .
SRC_FILES = main.cpp Floor.cpp FloorState.cpp Full.cpp SpaceAvailable.cpp MaitreD.cpp rderComponent.o Order.o OrderItem.o Group.o Bun.o Patty.o BeefPatty.o ChickenPatty.o Side.o Salad.o Chips.o Drink.o Milkshake.o Soda.o Garnish.o Lettuce.o Tomato.o GroupIterator.o ItemIterator.o Chef.o HeadChef.o MeatChef.o DrinkChef.o SidesChef.o GarnishChef.o Plate.o Pass.o Colleague.o Waiter.o
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
