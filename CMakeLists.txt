cmake_minimum_required(VERSION 3.16)
project(COMP2150A02)

set(CMAKE_CXX_STANDARD 14)

add_executable(COMP2150A02
        A2main.cpp
        Simulation.h Simulation.cpp
        PriorityQueue.h PriorityQueue.cpp
        Event.h Event.cpp
        ListItem.h ListItem.cpp
        Node.h Node.cpp
        OrderedItem.h OrderedItem.cpp
        Queue.h Queue.cpp
        Arrival.h Arrival.cpp
        MainAssembly.h MainAssembly.cpp
        Departure.h Departure.cpp FinishingAssembly.cpp FinishingAssembly.h)