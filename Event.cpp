#include "Event.h"
#include "ProcessArrivalEvent.h"
#include "TimeOutEvent.h"

#include <iostream>

using namespace std;

/**** Event implementation */
Event::Event(int theTime, Process *theProcess, Simulation *theSim)
	: eventTime(theTime), process(theProcess), sim(theSim) {}

Event::~Event() {}
int Event::getTime() { return eventTime; }

int Event::compareTo(ListItem *other)
{
	Event *otherEvent = dynamic_cast<Event *>(other);	  //cast the specific the event
	int result = this->eventTime - otherEvent->eventTime; //compare the time to determine the sequence in pq

	if (result == 0)
	{
		if (ProcessArrivalEvent *arrival = dynamic_cast<ProcessArrivalEvent *>(this))
		{
			if (TimeOutEvent *timeout = dynamic_cast<TimeOutEvent *>(other))
			{
				return -1;
			}
		}
	}
	return result;
}
