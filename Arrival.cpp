/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */
#include <iostream>
#include "Arrival.h"
#include "Simulation.h"
int Arrival::getTime()
{
    return this->getTime();
}
void Arrival::processEvent()
{
    this->sim->addPart(this);
}
Arrival::~Arrival() {}

