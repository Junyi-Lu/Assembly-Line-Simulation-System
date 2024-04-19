/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */
#pragma once
#include "Event.h"

class FinishingAssembly : public Event {
private:
    int endTime;
public:
    FinishingAssembly(int assemblyStartTime, int assemblyEndTime, Simulation* sim) :
            Event(assemblyStartTime, sim), endTime(assemblyEndTime){}
    virtual void processEvent();
    ~FinishingAssembly();

    int getTime();
};

