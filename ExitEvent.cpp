#include "ExitEvent.h"
#include "Simulation.h"
#include <iostream>

using namespace std;

ExitEvent::ExitEvent(Process *theProcess, int theTime, Simulation *theSim) : Event(theTime, theProcess, theSim)
{
    process = theProcess;
}

void ExitEvent::handleEvent()
{
    int eventTime = sim->getSimulationTime();
    process->setExitTime(eventTime); //record the exit time
    cout << "Time    " << eventTime << ": Process " << process->getID() << " complete. Total wait time is: " << process->getExitTime() - process->getArrivalTime() - process->getTotalTime() << endl;
}