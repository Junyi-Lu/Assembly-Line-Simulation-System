/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */
#pragma once
#include <fstream>
#include <string.h>
using namespace std;

class PriorityQueue; // Priority Queue
class Queue; // Queue class - provided to you
class Event; // Event - given to you.

class Simulation {
private:
    ifstream ifile;
    int simulationTime; // what is the current time of the simulation?
    int partsType;
    int mainProducts;
    int finishedProducts;
    string oneLine;
    int gapPos;
    PriorityQueue *eventList; // priority queue of Events.
    Queue* productQueue; // queue of partially assembled products (for finishing station).
    Queue** partQueues; // *array* of queues of parts for the stations.
    int  mainAssemblyTime; //  how long does the main station take?
    int  finishingAssemblyTime; //  how long does the main station take?
	bool mainBusy; // is the main station busy?
	bool finishingBusy; // is the finishing station busy?
    int mainDepartureTime;
    int finDepartureTime;
public:
    Simulation();

	// you need methods to manipulate product and part queues.
	// [add them here.]
    void addPart(Event *currEvent);
    int getSimulationTime();
    void setSimulationTime(int time);

    // main method for driving the simulation
    void runSimulation(char *fileName);

	// add an event to event queue.
	void addEvent (Event*); 

	// read next arrival from file and add it to the event queue. 
        void getNextArrival();
	
	// getters and setters for station statuses.
	bool isMainBusy();
	bool isFinishingBusy();
	void setMainStatus(bool);
	void setFinishingStatus(bool);
    void getSummery();
    void addPartialFinishedProduct();
    ~Simulation();

    void deleteMainPartSet();
};// class Simulation
