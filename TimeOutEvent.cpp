#include "TimeOutEvent.h"
#include "Simulation.h"
#include "StartCPUEvent.h"
#include <iostream>

using namespace std;

TimeOutEvent::TimeOutEvent(Process *theProcess, int theTime, Simulation *theSim) : Event(theTime, theProcess, theSim)
{
    process = theProcess;
}

void TimeOutEvent::handleEvent()
{
    int eventTime = sim->getSimulationTime();
    sim->setCPUStatus(false);
    process->setCPUTime(process->getCPUTime() - sim->getMaxCPUTime()); //Update new time, original time - max time = new time
    cout << "Time    " << eventTime << ": Process " << process->getID() << " times out (need " << process->getCPUTime() << " units more)." << endl;
    process->increaseTotalTime(sim->getMaxCPUTime());
    Process *currProcess = sim->dequeueCPU();    //store the cpu, in order to next process
    sim->waitForCPU(currProcess);                //readd to the cpu queue
    Process *nextProcess = sim->getCPUProcess(); //get the next cpu
    Event *startCPU = new StartCPUEvent(nextProcess, eventTime, sim);
    sim->addEvent(startCPU);
}