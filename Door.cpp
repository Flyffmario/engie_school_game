#include "Door.h"

Door::Door(Room &destination_in)
{
    //ctor
    *destination=destination_in;
    description="A door stands here.";
}

Door::~Door()
{
    //dtor
}

Room Door::getDestination()
{
    return *destination;
}

void Door::setDestination(Room &roomToGo)
{
    *destination=roomToGo;
}


