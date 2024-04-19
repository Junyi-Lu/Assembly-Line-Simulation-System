/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */

#pragma once
#include "ListItem.h"
#include "OrderedItem.h"
#include "Event.h"

class Node;

class PriorityQueue : public ListItem
    {
private:
    Node *front; // front of PriorityQueue.
    Node *back; // back of PriorityQueue
    int size; // size of PriorityQueue.
public:
    PriorityQueue(); //constructor
    int getSize(); // how many elements are in queue?
    bool isEmpty(); // is queue empty?
    void enqueue(Event *item); // add item to PriorityQueue.
    Event * getFront(); // look at first item in PriorityQueue.
    ListItem *dequeue(); // remove first item from PriorityQueue.
    ~PriorityQueue(); // destructor

    bool posFound();
}; // class Queue
