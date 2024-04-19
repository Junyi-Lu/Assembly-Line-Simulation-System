/**
 * @author 		Saif Mahmud
 * @id          7808507
 * @version     Jul. 25, 2020
 * @instructor	Ali Neshati
 * @assignment  A02
 */
#include <iostream>
#include "PriorityQueue.h"
#include "Node.h"


PriorityQueue::PriorityQueue() : front(nullptr), back(nullptr), size(0) {}

int PriorityQueue::getSize(){ return size; }
bool PriorityQueue::isEmpty()
{
    return size == 0;
}

void PriorityQueue::enqueue(Event* item){
    // special case: adding to empty queue

    if(front == nullptr){

        front = new Node(item, nullptr);
        back = front;
    } else {
        Node* curr = front;
        Node* prev;
        bool posFound = false;
        while (curr != nullptr && !posFound)
        {
            if(item->getTime() < dynamic_cast<Event*>(curr->getItem())->getTime())
            {
                posFound = true;

            } else {
                prev = curr;
                curr = curr->getNext();
            }
            Node* newNode = new Node(item,curr);
            prev->setNext(newNode);
        }
    }
    size++;
}// enqueue

ListItem *PriorityQueue::dequeue() {
    ListItem *theItem = nullptr;
    Node *theNode = front;
    if(front != nullptr){

        theItem = front->getItem();
        // special case: removing last item
        if(front == back){
            front = back = nullptr;
        } else {
            front = front->getNext();
        }
        size--;
        delete(theNode);
    }
    return theItem;
}// dequeue

Event *PriorityQueue::getFront(){
    Event *theItem = nullptr;

    if(front != nullptr){
        theItem = dynamic_cast<Event *>(front->getItem());
    }

    return theItem;
}// getFront
// destructor
PriorityQueue::~PriorityQueue() {}

bool PriorityQueue::posFound() {
    return false;
}



