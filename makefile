CXX=g++
CFLAGS=-I. -Wall
TARGET=main
OBJS= main.o OrderComponent.o Order.o OrderItem.o Group.o Bun.o Patty.o BeefPatty.o ChickenPatty.o Side.o Salad.o Chips.o Drink.o Milkshake.o Soda.o Garnish.o Lettuce.o Tomato.o GroupIterator.o ItemIterator.o Chef.o HeadChef.o MeatChef.o DrinkChef.o SidesChef.o GarnishChef.o Plate.o Pass.o Colleague.o Waiter.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)
    
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
    
clean:
	rm -f $(TARGET) $(OBJS)

run: main
	./main
