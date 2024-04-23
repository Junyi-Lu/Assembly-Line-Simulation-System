//-----------------------------------------
// NAME		: junyi lu
// STUDENT NUMBER	: 7879161
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike Domaratzki
// ASSIGNMENT	: assignment 2
// QUESTION	: question 1
//
// REMARKS: What is the purpose of this program?
// Test the data structure
//
//-----------------------------------------
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ProcessArrivalEvent.h"
#include "PriorityQueue.h"
#include "StartCPUEvent.h"
#include "TimeOutEvent.h"
#include "CompleteCPUEvent.h"
#include "Process.h"
#include "Simulation.h"

TEST_CASE("test the isEmpty in PQ", "[isEmpty]")
{
    PriorityQueue *testPQ = new PriorityQueue();
    Process *theProcess = new Process(0, 1);
    Simulation *sim = new Simulation();
    REQUIRE(testPQ->isEmpty());
    testPQ->enqueue(new ProcessArrivalEvent(theProcess, 1, sim));
    REQUIRE(!testPQ->isEmpty());
}

TEST_CASE("test the getSize in PQ", "[getSize]")
{
    PriorityQueue *testPQ = new PriorityQueue();
    Process *theProcess = new Process(0, 1);
    Simulation *sim = new Simulation();
    REQUIRE(testPQ->getSize() == 0);

    SECTION("enqueue one event and get size")
    {
        testPQ->enqueue(new ProcessArrivalEvent(theProcess, 1, sim));
        REQUIRE(testPQ->getSize() == 1);
    }

    SECTION("dequeue one event and get size")
    {
        testPQ->dequeue();
        REQUIRE(testPQ->getSize() == 0);
    }

    SECTION("enqueue mutiple events and get size")
    {
        for (int i = 0; i < 49; i++)
        {
            testPQ->enqueue(new TimeOutEvent(theProcess, random(), sim));
        }
        REQUIRE(testPQ->getSize() == 49);
    }
}

TEST_CASE("test the getFront in PQ", "[getFront]")
{
    PriorityQueue *testPQ = new PriorityQueue();
    Process *theProcess = new Process(1, 10);
    Simulation *sim = new Simulation();
    ProcessArrivalEvent *test1 = new ProcessArrivalEvent(theProcess, 3, sim);
    testPQ->enqueue(test1);
    REQUIRE(testPQ->getFront() == test1);
    SECTION("enqueue less time object")
    {
        StartCPUEvent *test2 = new StartCPUEvent(theProcess, 2, sim);
        testPQ->enqueue(test2);
        REQUIRE(testPQ->getFront() == test2);
    }

    SECTION("enqueue larger time obejct")
    {
        CompleteCPUEvent *test3 = new CompleteCPUEvent(theProcess, 10, sim);
        testPQ->enqueue(test3);
        REQUIRE(testPQ->getFront() != test3);
    }
}

TEST_CASE("test the enqueue in PQ", "[enqueue]")
{
    PriorityQueue *testPQ = new PriorityQueue();
    Simulation *sim = new Simulation();
    Process *theProcess = new Process(1, 1);
    ProcessArrivalEvent *test1 = new ProcessArrivalEvent(theProcess, 1, sim);
    testPQ->enqueue(test1);
    REQUIRE(testPQ->getSize() == 1);

    SECTION("enqueue same time obejct")
    {
        for (int i = 0; i < 100; i++)
        {
            testPQ->enqueue(test1);
        }
        REQUIRE(testPQ->getSize() == 101);
    }
}

TEST_CASE("test rhe dequeue in PQ", "[dequeue]")
{
    PriorityQueue *testPQ = new PriorityQueue();
    Simulation *sim = new Simulation();
    Process *theProcess = new Process(1, 1);
    ProcessArrivalEvent *test1 = new ProcessArrivalEvent(theProcess, 1, sim);
    testPQ->enqueue(test1);
    REQUIRE(testPQ->dequeue() == test1);
    SECTION("delete empty pq")
    {
        REQUIRE(testPQ->dequeue() == nullptr);
    }
}