CXX=g++
TARGET=main
OBJS= main.o OrderComponent.o Order.o OrderItem.o Group.o Bun.o Patty.o BeefPatty.o ChickenPatty.o Side.o Salad.o Chips.o Drink.o Milkshake.o Soda.o Garnish.o Lettuce.o Tomato.o Iterator.o OrderIterator.o IteratorItems.o ItemIterator.o
all: $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
    
%.o: %.cpp
	$(CXX) -c $< -o $@

run: all
	./main

runValgrind: all
	valgrind --leak-check=full ./main

clean:
	rm -f $(TARGET) $(OBJS)