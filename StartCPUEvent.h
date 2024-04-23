// CLASS: StartCPU
//
// Author: junyi lu 7879161
//
// REMARKS: subclass of event
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "Process.h"

class StartCPUEvent : public Event
{
private:
    Process *process;

public:
    StartCPUEvent(Process *theProcess, int theTime, Simulation *theSim);
    void handleEvent();
};