#include "TimeItem.h"

TimeItem::TimeItem(int theTime) : time(theTime) {}
int TimeItem::getTime() { return time; }
void TimeItem::setTime(int theTime) { time = theTime; }
int TimeItem::compareTo(ListItem *other)
{
    TimeItem *otherItem = dynamic_cast<TimeItem *>(other);
    return this->time - otherItem->time;
}
