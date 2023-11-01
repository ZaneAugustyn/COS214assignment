CXX=g++
CFLAGS=-I. -Wall
TARGET=main
OBJS= main.o Chef.o HeadChef.o MeatChef.o DrinkChef.o SidesChef.o GarnishChef.o Order.o Plate.o Pass.o Colleague.o OrderComponent.o

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)
    
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
    
clean:
	rm -f $(TARGET) $(OBJS)

run: main
	./main