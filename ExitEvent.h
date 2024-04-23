// CLASS: ExitEvent
//
// Author: junyi lu 7879161
//
// REMARKS: subclass of event
//
//-----------------------------------------
#pragma once
#include "Event.h"
#include "Process.h"

class ExitEvent : public Event
{
private:
    Process *process;

public:
	// constructor, with pointer to the process that is being handled, and the simulation.
    ExitEvent(Process *theProcess, int theTime, Simulation *theSim);
    void handleEvent();
};