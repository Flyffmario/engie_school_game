#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    //ctor
    description="Nothing here...";
}

Entity::~Entity()
{
    //dtor
}

std::string Entity::getDescription()
{
    return description;
}

void Entity::setDescription(std::string ongoingDescription)
{
    description=ongoingDescription;
}

std::string Entity::getEntityName()
{
    return entityName;
}

void Entity::setEntityName(std::string newEntityName)
{
    entityName=newEntityName;
}

