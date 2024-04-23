#include "Process.h"
#include "TimeItem.h"

#include <iostream>

Process::Process(int id, int arrtime) : ID(id), arrivalTime(arrtime), exitTime(0), totalTime(0)
{
    CPUTime = new Queue(); //in order to record the cpu time from input data
    IOTime = new Queue();  //in order to record the io time from input data
}

int Process::getID() { return ID; }
int Process::getArrivalTime() { return arrivalTime; }
int Process::getCPUTime()
{
    if (CPUTime->getFront() != nullptr)
    {
        return dynamic_cast<TimeItem *>(CPUTime->getFront())->getTime();
    }
    else
    {
        return -1;
    }
}
void Process::setCPUTime(int time) { dynamic_cast<TimeItem *>(CPUTime->getFront())->setTime(time); }
int Process::getIOTime()
{
    if (IOTime->getFront() != nullptr)
    {
        return dynamic_cast<TimeItem *>(IOTime->getFront())->getTime();
    }
    else
    {
        return -1;
    }
}
void Process::dequeueCPU() { CPUTime->dequeue(); }
void Process::dequeueIO() { IOTime->dequeue(); }
void Process::addCPUTime(int time) { CPUTime->enqueue(new TimeItem(time)); }
void Process::addIOTime(int time) { IOTime->enqueue(new TimeItem(time)); }
int Process::getExitTime() { return exitTime; }
void Process::setExitTime(int time) { exitTime = time; }
int Process::getTotalTime() { return totalTime; }
void Process::increaseTotalTime(int time) { totalTime += time; }

int Process::compareTo(ListItem *other)
{
    Process *otherProcess = dynamic_cast<Process *>(other);
    return this->arrivalTime - otherProcess->arrivalTime;
}