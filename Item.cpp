#include <iostream>
#include "Item.h"

Item::Item()
{
    //ctor
    entityName="Item";
    description="A Crate lies at the center of the room..";
}

Item::~Item()
{
    //dtor
}

std::string Item::getName()
{
    return name;
}

void Item::setName(std::string newName)
{
    name=newName;
}


int Item::getWeight()
{
    return weight;
}

void Item::setWeight(int newWeight)
{
    weight=newWeight;
}

int Item::getVolume()
{
    return volume;
}

void Item::setVolume(int newVolume)
{
    volume=newVolume;
}
