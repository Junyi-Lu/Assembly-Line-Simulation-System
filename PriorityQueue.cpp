#include "PriorityQueue.h"
#include "Node.h"

#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue() : front(nullptr), back(nullptr), size(0) {}
int PriorityQueue::getSize() { return size; }
bool PriorityQueue::isEmpty() { return size == 0; }

void PriorityQueue::enqueue(ListItem *item)
{
    if (front == nullptr) // empty pq
    {
        front = new Node(item, nullptr);
        back = front;
    }
    else
    {
        Node *newNode = new Node(item, nullptr);
        Node *currNode = front;
        Node *prevNode = nullptr;
        ListItem *currItem = dynamic_cast<ListItem *>(currNode->getItem());
        ListItem *newItem = dynamic_cast<ListItem *>(item);
        while (currNode != nullptr && currItem->compareTo(newItem) < 0) //in order to find the correct position
        {
            prevNode = currNode;
            currNode = currNode->getNext();
            if (currNode != nullptr)
            {
                currItem = dynamic_cast<ListItem *>(currNode->getItem()); //Keep refreshing curr, check the time, and compare
            }
        }
        if (prevNode == nullptr)
        {
            newNode->setNext(front);
            front = newNode;
        }
        else
        {
            newNode->setNext(currNode);
            prevNode->setNext(newNode);
            if (currNode == nullptr)
            {
                back = newNode;
            }
        }
    }
    size++;
}

ListItem *PriorityQueue::dequeue()
{
    ListItem *theItem = nullptr;
    Node *theNode = front;
    if (front != nullptr)
    {
        theItem = front->getItem(); //store the front item
        if (front == back)          //only one item
        {
            front = back = nullptr;
        }
        else
        {
            front = front->getNext();
        }
        size--;
        delete (theNode);
    }
    return theItem;
}

ListItem *PriorityQueue::getFront()
{
    ListItem *theItem = nullptr;
    if (front != nullptr)
    {
        theItem = front->getItem();
    }
    return theItem;
}
