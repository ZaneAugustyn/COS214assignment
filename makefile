CXX=g++
TARGET=main
OBJS= Waiter.o Group.o Chef.o Pass.o Order.o main.o

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