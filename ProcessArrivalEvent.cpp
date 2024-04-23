#include "ProcessArrivalEvent.h"
#include "Simulation.h"
#include "StartCPUEvent.h"

#include <iostream>

using namespace std;

ProcessArrivalEvent::ProcessArrivalEvent(Process *theProcess, int theTime, Simulation *theSim) : Event(theTime, theProcess, theSim)
{
    process = theProcess;
}

void ProcessArrivalEvent::handleEvent()
{
    int eventTime = sim->getSimulationTime();
    cout << "Time    " << eventTime << ": Process " << process->getID() << " arrives in system: ";
    sim->getNextArrival();
    sim->waitForCPU(process);
    if (!sim->isCPUBusy())
    {
        cout << "CPU is free (process begins execution)." << endl;
        Event *startCPU = new StartCPUEvent(process, eventTime, sim);
        sim->addEvent(startCPU);
    }
    else
    {
        cout << "CPU is busy (process will be queued)." << endl;
    }
}