#ifndef DOOR_H
#define DOOR_H

#include "Entity.h"
#include "Room.h"

class Door : public Entity
{
    public:
        Door(Room &destination_in);
        virtual ~Door();

        Room getDestination();
        void setDestination(Room &roomToGo);


        Room *destination;


    protected:

    private:
};

#endif // DOOR_H
