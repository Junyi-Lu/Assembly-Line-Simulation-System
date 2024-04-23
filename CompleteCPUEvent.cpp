#include "CompleteCPUEvent.h"
#include "Simulation.h"
#include "StartCPUEvent.h"
#include "StartIOEvent.h"
#include "ExitEvent.h"
#include <iostream>

using namespace std;

CompleteCPUEvent::CompleteCPUEvent(Process *theProcess, int theTime, Simulation *theSim) : Event(theTime, theProcess, theSim)
{
    process = theProcess;
}

void CompleteCPUEvent::handleEvent()
{
    int eventTime = sim->getSimulationTime();//get the time
    sim->setCPUStatus(false);//refresh the new status of cpu
    cout << "Time    " << eventTime << ": Process " << process->getID() << " completes CPU burst. ";
    process->increaseTotalTime(process->getCPUTime()); //record the global time
    process->dequeueCPU();//dequeue from the speicial queue for process
    sim->dequeueCPU();//dequeue from the simutation cpu queue
    if (process->getIOTime() != -1)
    {
        cout << " Queueing for I/O. ";
        sim->waitForIO(process);//add to the io queue
        if (!sim->isIOBusy())//when io is free
        {
            cout << "IO is free (process begins execution)." << endl;
            Event *startIO = new StartIOEvent(process, eventTime, sim);
            sim->addEvent(startIO);
        }
        else
        {
            cout << "IO is busy (process will be queued)." << endl;
        }
    }
    else
    {
        cout << "Will exit." << endl;
        Event *exit = new ExitEvent(process, eventTime, sim);//exit the whole program
        sim->addEvent(exit);
    }

    if (sim->getCPUProcess() != nullptr)
    {
        Event *startCPU = new StartCPUEvent(sim->getCPUProcess(), eventTime, sim);
        sim->addEvent(startCPU);
    }
}