#pragma once

#include <fstream>
#include "ListItem.h"
#include "Process.h"
using namespace std;

class PriorityQueue;
class Queue;
class Event;

class Simulation
{
private:
	ifstream ifile;
	int simulationTime;
	PriorityQueue *eventList;
	Queue *CPUQueue;
	Queue *IOQueue;
	int maxCpuTime;
	bool cpuBusy;
	bool ioBusy;
	int numProcess;
	Queue *allProcesses;

public:
	Simulation();

	void waitForCPU(ListItem *process);
	void waitForIO(ListItem *process);
	int getMaxCPUTime();
	Process *getCPUProcess();
	Process *getIOProcess();
	Process *dequeueCPU();
	Process *dequeueIO();
	void increaseNumProcess();
	void increaseTotalTime(int time);

	int getSimulationTime();
	void setSimulationTime(int time);

	void addEvent(Event *);
	void addProcess(Process *process);

	void getNextArrival();

	bool isCPUBusy();
	bool isIOBusy();
	void setCPUStatus(bool);
	void setIOStatus(bool);

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName);

	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods

}; // class Simulation
