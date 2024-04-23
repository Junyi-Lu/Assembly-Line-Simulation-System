// CLASS: CompleteIO
//
// Author: junyi lu 7879161
//
// REMARKS: subclass of event
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "Process.h"

class CompleteIOEvent : public Event
{
private:
    Process *process;

public:
    // constructor, with pointer to the process that is being handled, and the simulation.
    CompleteIOEvent(Process *theProcess, int theTime, Simulation *theSim);
    void handleEvent();
};