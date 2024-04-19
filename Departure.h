/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */

#pragma once

#include "Event.h"

class Departure : public Event {

public:
    Departure(int departureTime, Simulation* sim) : Event(departureTime, sim){};
    virtual void processEvent();
};