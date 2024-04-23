// CLASS: StartIO
//
// Author: junyi lu 7879161
//
// REMARKS: subclass of event
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "Process.h"

class StartIOEvent : public Event
{
private:
    Process *process;

public:
    StartIOEvent(Process *theProcess, int theTime, Simulation *theSim);
    void handleEvent();
};