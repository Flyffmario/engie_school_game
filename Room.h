#ifndef ROOM_H
#define ROOM_H

#include <vector>

#include "Room.h"
#include "Entity.h"

class Room
{
    public:
        Room();
        virtual ~Room();

        Entity & getWest();
        Entity & getEast();
        Entity & getNorth();
        Entity & getSouth();
        Entity & getMainEntity();

        void setWest(Entity newEntity);
        void setEast(Entity newEntity);
        void setNorth(Entity newEntity);
        void setSouth(Entity newEntity);
        void setMainEntity(Entity newEntity);

    protected:

    private:

        Entity mainEntity;

        Entity west;
        Entity east;
        Entity north;
        Entity south;
};

#endif // ROOM_H
