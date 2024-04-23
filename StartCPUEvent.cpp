#include "StartCPUEvent.h"
#include "Simulation.h"
#include "CompleteCPUEvent.h"
#include "TimeOutEvent.h"
#include <iostream>

using namespace std;

StartCPUEvent::StartCPUEvent(Process *theProcess, int theTime, Simulation *theSim) : Event(theTime, theProcess, theSim)
{
    process = theProcess;
}

void StartCPUEvent::handleEvent()
{
    int eventTime = sim->getSimulationTime();
    sim->setCPUStatus(true);
    cout << "Time    " << eventTime << ": Process " << process->getID() << " begins CPU burst ";
    if (process->getCPUTime() > sim->getMaxCPUTime())
    {
        cout << "(will time out; need " << process->getCPUTime() << " units total)." << endl;
        Event *timeOut = new TimeOutEvent(process, eventTime + sim->getMaxCPUTime(), sim);
        sim->addEvent(timeOut);
    }
    else
    {
        cout << "(will complete all " << process->getCPUTime() << " remaining units)." << endl;
        Event *completeCPU = new CompleteCPUEvent(process, eventTime + process->getCPUTime(), sim);
        sim->addEvent(completeCPU);
    }
}