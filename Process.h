// CLASS: Process
//
// Author: junyi lu 7879161
//
// REMARKS: important object of data, in order to store the a lot of io time and cpu time
//
//-----------------------------------------

#pragma once
#include "ListItem.h"
#include "Queue.h"

class Process : public ListItem
{
private:
    int ID;
    int arrivalTime;
    Queue *CPUTime;
    Queue *IOTime;
    int exitTime;
    int totalTime;

public:
    Process(int id, int arrTime);
    int getID();
    int getArrivalTime();
    int getCPUTime();
    void setCPUTime(int time);
    int getIOTime();
    void dequeueCPU();
    void dequeueIO();
    void addCPUTime(int time);
    void addIOTime(int time);
    int getExitTime();
    void setExitTime(int time);
    int getTotalTime();
    void increaseTotalTime(int time);
    int compareTo(ListItem *other);
};