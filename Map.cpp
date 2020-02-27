#include "Map.h"
#include "Wall.h"

#include <typeinfo>

Map::Map(int i, int j)
{
    //ctor
    //It's a vector of Rooms
    x_length=i;
    y_length=j;

    for (int k = 0 ; k < x_length ; k++) {
        for (int l = 0 ; l < y_length ; l++) {
            //dostuff
            roomMap.push_back(Room());
        }
    }
}

Map::~Map()
{
    //dtor
}

std::vector<int> Map::getSize()
{
    std::vector<int> sizeOfMap {x_length,y_length};
    return sizeOfMap;
}

void Map::printMap()
{
    //To Visualize the map
    std::string upBorder = "  ";
    std::string downBorder = "__";

    for (unsigned int i = 0 ; i < x_length ; i++) {
        upBorder = upBorder+" ";
        downBorder = downBorder+"_";
    }

    std::cout << upBorder << std::endl;

    for (unsigned int i = 0; i < x_length ; i++) {
        std::cout << " ";
        for (unsigned j = 0 ; j < y_length ; j++) {
            Room & actualRoom = roomMap[i*x_length+j];

            Entity westSide = actualRoom.getWest();
            Entity eastSide = actualRoom.getEast();
            Entity northSide = actualRoom.getNorth();
            Entity southSide = actualRoom.getSouth();

            if ((westSide.getEntityName()).compare("Wall")==0) {
                if ((northSide.getEntityName()).compare("Wall")==0) {
                    if ((southSide.getEntityName()).compare("Wall")==0) {
                        //West DeadEnd
                        std::cout << "=";
                    } else {
                        //NW Corner
                        std::cout << "/";
                    }
                }

                if ((southSide.getEntityName()).compare("Wall")==0) {
                    //SW Corner
                    std::cout << "\\";
                }

                if ((eastSide.getEntityName()).compare("Wall")==0) {
                    //NS Straight Path
                    std::cout << "|";
                }
            }

            if ((eastSide.getEntityName()).compare("Wall")==0) {
                if ((northSide.getEntityName()).compare("Wall")==0) {
                    if ((southSide.getEntityName()).compare("Wall")==0) {
                        //East DeadEnd
                        std::cout << "=";
                    } else {
                        //NE
                        std::cout << "\\";
                    }
                }

                if ((southSide.getEntityName()).compare("Wall")==0) {
                    //SE Corner
                    std::cout << "/";
                }
            }

            if ((northSide.getEntityName()).compare("Wall")==0) {
                if ((westSide.getEntityName()).compare("Wall")==0) {
                    if ((eastSide.getEntityName()).compare("Wall")==0) {
                        //North DeadEnd
                        std::cout << "|";
                    }
                }

                if ((southSide.getEntityName()).compare("Wall")==0) {
                    //WE Straight Path
                    std::cout << "=";
                }

            }

            if ((southSide.getEntityName()).compare("Wall")==0) {
               if ((eastSide.getEntityName()).compare("Wall")==0) {
                    if ((westSide.getEntityName()).compare("Wall")==0) {
                        //South DeadEnd
                        std::cout << "|";
                    }
               }
            }

            if ((southSide.getEntityName()).compare("Wall")!=0) {
                if ((northSide.getEntityName()).compare("Wall")!=0) {
                    if ((eastSide.getEntityName()).compare("Wall")!=0) {
                        if ((westSide.getEntityName()).compare("Wall")!=0) {
                            std::cout << "+";
                        }
                    }
                }
            }
        }
        std::cout << " " << std::endl;
    }
    std::cout << downBorder << std::endl;
}

void Map::printRoom(int i, int j)
{
    //Still in dev
    Room seekedRoom = roomMap[i*x_length+j];
}


Room & Map::getRoom(int i, int j)
{
    return roomMap[i*x_length+j];
}

void Map::setRoom(Room room, int i, int j)
{
    //Function not working, wtf ?
    roomMap[i*x_length+j]=room;
}

void Map::generateMap()
{
    //First Building the Walls of the Dungeon

    for (unsigned int i = 1 ; i < x_length-1 ; i++) {
        //West and East Side of the Dungeon, excluding Corners
        Room westBorder = Room();
        westBorder.setWest(Wall());

        Room eastBorder = Room();
        eastBorder.setEast(Wall());

        setRoom(westBorder,i,0);
        setRoom(eastBorder,i,y_length-1);
    }

    for (unsigned int j = 1 ; j < y_length-1 ; j++) {
        //North and South Side of the Dungeon, excluding Corners

        Room northBorder = Room();
        northBorder.setNorth(Wall());

        Room southBorder=Room();
        southBorder.setSouth(Wall());

        setRoom(northBorder,0,j);
        setRoom(southBorder,x_length-1,j);
    }

    //Corners

    Room NWCorner = Room();
    NWCorner.setWest(Wall());
    NWCorner.setNorth(Wall());
    setRoom(NWCorner,0,0);

    Room NECorner = Room();
    NECorner.setEast(Wall());
    NECorner.setNorth(Wall());
    setRoom(NECorner,0,y_length-1);

    Room SWCorner = Room();
    SWCorner.setWest(Wall());
    SWCorner.setSouth(Wall());
    setRoom(SWCorner,x_length-1,0);

    Room SECorner = Room();
    SECorner.setEast(Wall());
    SECorner.setSouth(Wall());
    setRoom(SECorner,x_length-1,y_length-1);

    //Set Inside Walls

    getRoom(2,0).setNorth(Wall());
    getRoom(1,0).setSouth(Wall());

    getRoom(2,1).setEast(Wall());
    getRoom(2,2).setWest(Wall());

    getRoom(1,1).setEast(Wall());
    getRoom(1,2).setWest(Wall());

    getRoom(1,1).setNorth(Wall());
    getRoom(0,1).setSouth(Wall());

}

