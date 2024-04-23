#include "CompleteIOEvent.h"
#include "Simulation.h"
#include "ExitEvent.h"
#include "StartCPUEvent.h"
#include "StartIOEvent.h"
#include <iostream>

using namespace std;

CompleteIOEvent::CompleteIOEvent(Process *theProcess, int theTime, Simulation *theSim) : Event(theTime, theProcess, theSim)
{
    process = theProcess;
}

void CompleteIOEvent::handleEvent()
{
    int eventTime = sim->getSimulationTime();//get the time
    sim->setIOStatus(false);//after complete IO status
    cout << "Time    " << eventTime << ": Process " << process->getID() << " completes IO burst. ";
    process->increaseTotalTime(process->getIOTime());
    process->dequeueIO();
    if (process->getCPUTime() != -1)
    {
        cout << "Queueing for CPU. ";
        sim->waitForCPU(process);//add to the CPU queue
        if (!sim->isCPUBusy())//keep dealing next cpu
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
    else
    {
        cout << "Will exit." << endl;
        Event *exit = new ExitEvent(process, eventTime, sim);
        sim->addEvent(exit);
    }

    sim->dequeueIO();

    if (sim->getIOProcess() != nullptr)//direct deal the next IO
    {
        Event *startIO = new StartIOEvent(sim->getIOProcess(), eventTime, sim);
        sim->addEvent(startIO);
    }
}