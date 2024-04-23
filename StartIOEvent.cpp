#include "StartIOEvent.h"
#include "Simulation.h"
#include "CompleteIOEvent.h"
#include <iostream>

using namespace std;

StartIOEvent::StartIOEvent(Process *theProcess, int theTime, Simulation *theSim) : Event(theTime, theProcess, theSim)
{
    process = theProcess;
}

void StartIOEvent::handleEvent()
{
    int eventTime = sim->getSimulationTime();
    sim->setIOStatus(true);
    cout << "Time    " << eventTime << ": Process " << process->getID() << " begins I/O burst of length " << process->getIOTime() << "." << endl;
    Event *completeIO = new CompleteIOEvent(process, eventTime + process->getIOTime(), sim);
    sim->addEvent(completeIO);
}