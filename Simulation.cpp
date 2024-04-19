/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */
#include <iostream>
#include <climits>
#include "Simulation.h"
#include "OrderedItem.h"
#include "Arrival.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "MainAssembly.h"
#include "FinishingAssembly.h"

Simulation::Simulation()
{
    finDepartureTime = INT_MAX;
    mainDepartureTime = INT_MAX;
    eventList = new PriorityQueue();
    partQueues = new Queue*[3];
    mainProducts = 0;
    finishedProducts = 0;
    for(int i = 0; i < 3; i++)
    {
        partQueues[i] = new Queue();
    } // all parts queue.
    productQueue = new Queue();
}
void Simulation:: runSimulation(char *fileName)
{
    ifile.open(fileName);
    Event* currEvent;

    if(ifile.is_open())
    {
        getline(ifile, oneLine);
        gapPos = oneLine.find_last_of(" ");

        mainAssemblyTime = stoi(oneLine.substr(0,gapPos));
        finishingAssemblyTime = stoi(oneLine.substr(gapPos+1));

        setMainStatus(false);
        setFinishingStatus(false);

        currEvent = new Arrival(mainAssemblyTime, finishingAssemblyTime, this);
        cout << "MAIN STATION ASSEMBLY TIME: " << mainAssemblyTime <<
        "; FINISHING STATION ASSEMBLY TIME: " << finishingAssemblyTime << endl;
        addEvent(currEvent);


        while (!eventList->isEmpty())
        {
            eventList->dequeue();
            if(eventList->isEmpty() && !ifile.eof())
            {
                getNextArrival();
                if(!ifile.eof())
                {
                    addEvent(new Arrival(getSimulationTime(), partsType, this));
                    cout << "TIME: "<< getSimulationTime() <<" : EVENT: ARRIVAL : PART P" << partsType << endl;
                }
            }

            if(!eventList->isEmpty())
            {
                eventList->getFront()->processEvent();
            }



            //start main station assembly
            if(!partQueues[0]->isEmpty() && !partQueues[1]->isEmpty() && !isMainBusy())
            {
                mainDepartureTime = simulationTime + mainAssemblyTime;
                currEvent = new MainAssembly(simulationTime,mainDepartureTime, this);
                cout << "TIME: "<< simulationTime <<" : EVENT: MAIN-ASSEMBLY START. WILL FINISH AT "
                     << mainDepartureTime << endl;
                setMainStatus(true);
            }
            //Did main station finished?
            if(mainDepartureTime <= simulationTime && isMainBusy())
            {
                setMainStatus(false);
                deleteMainPartSet();
                addPartialFinishedProduct();
                cout << "TIME: "<< simulationTime <<" : EVENT: MAIN-ASSEMBLY FINISHED."<< endl;
            }

            //start finishing station assembly
            if(!productQueue->isEmpty() && !productQueue[2].isEmpty() && !isFinishingBusy())
            {
                productQueue->dequeue();
                finDepartureTime = simulationTime + finishingAssemblyTime;
                currEvent = new FinishingAssembly(getSimulationTime(),
                        finDepartureTime, this);
                cout << "TIME: "<< simulationTime <<" : EVENT: FINISHING ASSEMBLY START. "
                                                         "WILL BE COMPLETED AT "<<finDepartureTime<< endl;
                setFinishingStatus(true);
            }

            //did finishing station assembly completed?
            if(finDepartureTime <= simulationTime && isFinishingBusy())
            {
                setFinishingStatus(false);
                cout << "TIME: "<< simulationTime
                     <<" : EVENT: FINISHING ASSEMBLY COMPLETE. FINAL PRODUCT ADDED TO THE QUEUE."<< endl;
                finishedProducts++;
            }
        }//while
    } else {
        cout << "Cannot open the file";
        exit(1);
    }
}
// read next arrival from file and add it to the event queue.
void Simulation::getNextArrival()
{
    getline(ifile, oneLine);
    if(!ifile.eof())
    {
        gapPos = oneLine.find_last_of(" ");
        setSimulationTime(stoi(oneLine.substr(0,gapPos)));
        partsType = stoi(oneLine.substr(gapPos+1));
    }
}
int Simulation::getSimulationTime()
{
    return this->simulationTime;
}
void Simulation::setSimulationTime(int time)
{
    this->simulationTime = time;
}
// add an event to event queue
void Simulation::addEvent (Event* event)
{
    eventList->enqueue(event);
}
// add a part to event queue
void Simulation::addPart (Event* currEvent)
{
    partQueues[partsType]->enqueue(currEvent);
}
// getters and setters for station statuses.
bool Simulation::isMainBusy()
{
    return mainBusy;
}
bool Simulation::isFinishingBusy()
{
    return finishingBusy;
}
//true means busy
void Simulation::setMainStatus(bool value)
{
    mainBusy = value;
}
//true means busy
void Simulation::setFinishingStatus(bool value)
{
    finishingBusy = value;
}
void Simulation::deleteMainPartSet()
{
    partQueues[0]->dequeue();
    partQueues[1]->dequeue();
}

void Simulation::getSummery()
{
    cout << "Total items assembly completed: " << finishedProducts << endl;
	float a = simulationTime;
	float b = finishedProducts;
    cout << "Total Average time: "<< a/b << "(time units) per product." << endl;
    cout << "P0 parts left: "<< partQueues[0]->getSize() << endl;
    cout << "P1 parts left: "<< partQueues[1]->getSize() << endl;
    cout << "P2 parts left: "<< partQueues[2]->getSize() << endl;
    cout << "Partial Finished parts left: "<< productQueue->getSize() << endl;
}

void Simulation::addPartialFinishedProduct() {
    productQueue->enqueue(new Arrival(getSimulationTime(), finishingAssemblyTime, this));
    mainProducts++;
}
