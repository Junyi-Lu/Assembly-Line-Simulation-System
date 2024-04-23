CC=clang++
CFLAGS=--std=c++11

objects = Event.o Simulation.o ListItem.o Node.o PriorityQueue.o Queue.o Process.o ProcessArrivalEvent.o StartCPUEvent.o CompleteCPUEvent.o TimeOutEvent.o StartIOEvent.o CompleteIOEvent.o ExitEvent.o TimeItem.o 

# this rule will build A2 as the executable from the object files
all: A2main.o $(objects)
	$(CC) $(CFLAGS) -o A2 $< $(objects)

test: Test.o $(objects)
		$(CC) $(CFLAGS) -o test $< $(objects)

# this rule will build a .o file from a .cpp file. 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
clean:
	rm *.o A2 test
