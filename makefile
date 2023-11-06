CXX = g++
CXXFLAGS = -std=c++11

SRC_DIR = .
SRC_FILES = main.cpp facade.cpp Floor.cpp FloorState.cpp Full.cpp SpaceAvailable.cpp MaitreD.cpp OrderComponent.cpp OrderItem.cpp Group.cpp GroupState.cpp Bun.cpp Patty.cpp BeefPatty.cpp ChickenPatty.cpp Side.cpp Salad.cpp Chips.cpp Drink.cpp Milkshake.cpp Soda.cpp Garnish.cpp Lettuce.cpp Tomato.cpp Chef.cpp HeadChef.cpp MeatChef.cpp DrinkChef.cpp SidesChef.cpp GarnishChef.cpp Pass.cpp Colleague.cpp Waiter.cpp WaitForTable.cpp Bill.cpp BillPayment.cpp Customer.cpp CustomerPays.cpp Happy.cpp MakeTab.cpp PayTab.cpp ReadyForBill.cpp ReadyToOrder.cpp SplitBill.cpp Tab.cpp Unhappy.cpp ItemIterator.cpp GroupIterator.cpp Order.cpp LanguageAdapter.cpp LanguageTarget.cpp Plate.cpp Neutral.cpp PrintBill.cpp OrderPrint.cpp Marginals.cpp FooterBill.cpp HeaderBill.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(EXECUTABLE)

%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE)

run: all
	./main

debug:
	valgrind ./main