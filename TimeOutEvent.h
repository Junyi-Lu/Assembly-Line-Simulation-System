// CLASS: TimeOut
//
// Author: junyi lu 7879161
//
// REMARKS: subclass of event
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "Process.h"

class TimeOutEvent : public Event
{
private:
    Process *process;

public:
    TimeOutEvent(Process *theProcess, int theTime, Simulation *theSim);
    void handleEvent();
};