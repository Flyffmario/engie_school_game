#ifndef MAP_H
#define MAP_H

#include "Room.h"

class Map
{
    public:
        Map(int i, int j);
        virtual ~Map();

        std::vector<int> getSize();
        void printMap();

        Room & getRoom(int i, int j);
        void setRoom(Room room, int i, int j);

        void generateMap();

    protected:

    private:

        void printRoom(int i, int j);

        int x_length;
        int y_length;
        std::vector<Room> roomMap;
};

#endif // MAP_H
