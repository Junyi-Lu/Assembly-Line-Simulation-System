
//do not edit


#pragma once
#include "ListItem.h"

class OrderedItem : public ListItem
        {
private:

public:
    virtual int compareTo(OrderedItem *other) = 0;
	virtual ~OrderedItem();
}; // class ListItem
