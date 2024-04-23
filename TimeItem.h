// CLASS: TimeItem
//
// Author: junyi lu 7879161
//
// REMARKS: specific time item
//
//-----------------------------------------
#pragma once
#include "ListItem.h"

class TimeItem : public ListItem
{
private:
    int time;

public:
    TimeItem(int theTime);
    int getTime();
    void setTime(int time);
    int compareTo(ListItem *other);
};