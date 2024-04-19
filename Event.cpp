/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */
#include "Event.h"

Event::Event(int theTime, Simulation *theSim) : eventTime(theTime), sim (theSim) {}
Event::~Event() {}

int Event::getTime()
{
    return eventTime;
}
void Event::processEvent() {

}
// returns 0 if the item of parameter is bigger
int Event::compareTo(OrderedItem *other)
{
    int out = 0;

    if(this->getTime() >= dynamic_cast<Event*>(other)->getTime())
    {
        out = 1; //means other is smaller
    }

	return out; // you must implement this.
}// compareTo
