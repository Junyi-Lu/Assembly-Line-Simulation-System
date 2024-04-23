#include "Simulation.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "Process.h"
#include "ProcessArrivalEvent.h"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

Simulation::Simulation() : simulationTime(0), maxCpuTime(0), cpuBusy(false), ioBusy(false), numProcess(1)
{
    eventList = new PriorityQueue(); // eventlist pq for process event
    CPUQueue = new Queue();          // store the cpu time
    IOQueue = new Queue();           //store the io time
    allProcesses = new Queue();      // store the process
}

int Simulation::getSimulationTime() { return simulationTime; }
void Simulation::setSimulationTime(int time) { simulationTime = time; }

void Simulation::runSimulation(char *fileName)
{
    Event *theEvent;
    ifile.open(fileName);
    char buffer[100];
    ifile.getline(buffer, 100);
    if (!ifile.eof())
    {
        stringstream line(buffer);
        line >> maxCpuTime; //get the max cpu time
    }

    cout << "Maximum time for one access in CPU is " << maxCpuTime << endl;
    getNextArrival();

    while (!eventList->isEmpty())
    {
        theEvent = (Event *)(eventList->dequeue()); //curr event,meaning to process
        simulationTime = theEvent->getTime();
        theEvent->handleEvent(); //Specific handling of specific events
        delete (theEvent);
    }
    ifile.close();
}

void Simulation::getNextArrival()
{
    Process *newProcess;
    char buffer[1000];
    int arrivalTime;
    int temp;
    Event *arrival = NULL;
    ifile.getline(buffer, 1000);
    if (!ifile.eof())
    {
        stringstream line(buffer);
        line >> arrivalTime;
        newProcess = new Process(numProcess, arrivalTime); //get the first process value
        increaseNumProcess();
        while (!line.eof())
        {
            line >> temp;
            if (temp > 0) //if input data >0
            {
                newProcess->addCPUTime(temp);
            }
            else // <0 is io time
            {
                temp = abs(temp);
                newProcess->addIOTime(temp);
            }
        }

        arrival = new ProcessArrivalEvent(newProcess, arrivalTime, this); //produce a first event
        addEvent(arrival);
        addProcess(newProcess);
    }
}

void Simulation::addEvent(Event *theEvent)
{
    eventList->enqueue(theEvent);
}

bool Simulation::isCPUBusy()
{
    return cpuBusy;
}

bool Simulation::isIOBusy()
{
    return ioBusy;
}

void Simulation::setCPUStatus(bool stat)
{
    cpuBusy = stat;
}

void Simulation::setIOStatus(bool stat)
{
    ioBusy = stat;
}

void Simulation::waitForCPU(ListItem *process)
{
    CPUQueue->enqueue(process);
}

void Simulation::waitForIO(ListItem *process)
{
    IOQueue->enqueue(process);
}

int Simulation::getMaxCPUTime() { return maxCpuTime; }

void Simulation::increaseNumProcess() { numProcess++; }

Process *Simulation::getCPUProcess()
{
    return dynamic_cast<Process *>(CPUQueue->getFront());
}

Process *Simulation::getIOProcess()
{
    return dynamic_cast<Process *>(IOQueue->getFront());
}

Process *Simulation::dequeueCPU()
{
    return dynamic_cast<Process *>(CPUQueue->dequeue());
}

Process *Simulation::dequeueIO()
{
    return dynamic_cast<Process *>(IOQueue->dequeue());
}

void Simulation::addProcess(Process *process)
{
    allProcesses->enqueue(process);
}

void Simulation::summary()
{
    cout << " Process   Arrival    Exit    Wait" << endl;
    cout << "       #      Time    Time    Time" << endl;
    cout << "------------------------------------" << endl;
    while (!allProcesses->isEmpty())
    {
        Process *curr = dynamic_cast<Process *>(allProcesses->dequeue());
        cout << "        " << curr->getID() << "          " << curr->getArrivalTime() << "        "
             << curr->getExitTime() << "        " << curr->getExitTime() - curr->getArrivalTime() - curr->getTotalTime() << endl;
    }
}