// CLASS: PrioirtyQueue
//
// Author: junyi lu 7879161
//
// REMARKS: data strecture of eventList
//
//-----------------------------------------
#pragma once
#include "ListItem.h"

class Node;

class PriorityQueue
{
private:
    Node *front;
    Node *back;
    int size;

public:
    PriorityQueue();
    int getSize();
    bool isEmpty();
    void enqueue(ListItem *item);
    ListItem *getFront();
    ListItem *dequeue();
};