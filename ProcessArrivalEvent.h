// CLASS: ProcessArrivalEvent
//
// Author: junyi lu 7879161
//
// REMARKS: subclass of event
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "Process.h"

class ProcessArrivalEvent : public Event
{
private:
    Process *process;

public:
    ProcessArrivalEvent(Process *theProcess, int theTime, Simulation *theSim);
    void handleEvent();
};