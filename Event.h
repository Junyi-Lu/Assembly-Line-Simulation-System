/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */
#pragma once
#include "OrderedItem.h"


class Simulation;

/**** Event abstract interface */
class Event: public OrderedItem {
private:
        int eventTime; // time of the event.
protected: 
        Simulation *sim; // simulation event is a part of.
public:
        Event(int theTime, Simulation* sim);
        virtual void processEvent() = 0; // polymorphic method for events. 
        virtual ~Event();
        int getTime(); 
        int compareTo(OrderedItem *other); // you must implement this.

};// class Event
