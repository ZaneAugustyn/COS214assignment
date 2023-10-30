CXX=g++
TARGET=main
OBJS= main.o OrderComponent.o Order.o OrderItem.o Group.o

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