/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */
#pragma once
#include "Event.h"

class Arrival : public Event {
private:
    int endTime;
public:
    virtual void processEvent() ;
    Arrival(int theTime, int endTime, Simulation* sim) :
    Event(theTime, sim), endTime(endTime) {}
    int getTime();
    ~Arrival(); // destructor
};

