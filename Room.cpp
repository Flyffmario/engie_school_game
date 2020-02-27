#include "Room.h"
#include "Entity.h"

Room::Room()
{
    //ctor
}

Room::~Room()
{
    //dtor
}

Entity &Room::getWest()
{
    return west;
}

Entity &Room::getEast()
{
    return east;
}

Entity &Room::getNorth()
{
    return north;
}

Entity &Room::getSouth()
{
    return south;
}

Entity &Room::getMainEntity()
{
    return mainEntity;
}

void Room::setWest(Entity newEntity)
{
    west=newEntity;
}

void Room::setEast(Entity newEntity)
{
    east=newEntity;
}

void Room::setNorth(Entity newEntity)
{
    north=newEntity;
}

void Room::setSouth(Entity newEntity)
{
    south=newEntity;
}

void Room::setMainEntity(Entity newEntity)
{

}
