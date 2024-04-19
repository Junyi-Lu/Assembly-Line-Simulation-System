OBJS	= A2main.o Simulation.o PriorityQueue.o Event.o ListItem.o Node.o OrderedItem.o Queue.o Arrival.o MainAssembly.o Departure.o FinishingAssembly.o
SOURCE	= A2main.cpp Simulation.cpp PriorityQueue.cpp Event.cpp ListItem.cpp Node.cpp OrderedItem.cpp Queue.cpp Arrival.cpp MainAssembly.cpp Departure.cpp FinishingAssembly.cpp
HEADER	= Simulation.h PriorityQueue.h Event.h ListItem.h Node.h OrderedItem.h Queue.h Arrival.h MainAssembly.h Departure.h FinishingAssembly.h
OUT	= A2main
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

A2main.o: A2main.cpp
	$(CC) $(FLAGS) A2main.cpp 

Simulation.o: Simulation.cpp
	$(CC) $(FLAGS) Simulation.cpp 

PriorityQueue.o: PriorityQueue.cpp
	$(CC) $(FLAGS) PriorityQueue.cpp 

Event.o: Event.cpp
	$(CC) $(FLAGS) Event.cpp 

ListItem.o: ListItem.cpp
	$(CC) $(FLAGS) ListItem.cpp 

Node.o: Node.cpp
	$(CC) $(FLAGS) Node.cpp 

OrderedItem.o: OrderedItem.cpp
	$(CC) $(FLAGS) OrderedItem.cpp 

Queue.o: Queue.cpp
	$(CC) $(FLAGS) Queue.cpp 

Arrival.o: Arrival.cpp
	$(CC) $(FLAGS) Arrival.cpp 

MainAssembly.o: MainAssembly.cpp
	$(CC) $(FLAGS) MainAssembly.cpp 

Departure.o: Departure.cpp
	$(CC) $(FLAGS) Departure.cpp 

FinishingAssembly.o: FinishingAssembly.cpp
	$(CC) $(FLAGS) FinishingAssembly.cpp 


clean:
	rm -f $(OBJS) $(OUT)