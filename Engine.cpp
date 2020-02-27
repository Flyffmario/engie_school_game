#include "Engine.h"

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cmath>
#include <cstdlib>

#include "Enemy.h"
#include "Map.h"
#include "Room.h"
#include "Wall.h"

Engine::Engine()
{
    //ctor
    //Types of Items and Weapons
    itemNames.push_back("Apple");
    itemNames.push_back("Bread");
    itemNames.push_back("Wine");
    itemNames.push_back("Cooked Meat");

    weaponNames.push_back("Broadsword");
    weaponNames.push_back("Mace");
    weaponNames.push_back("Hammer");
    weaponNames.push_back("Sword");

}

Engine::~Engine()
{
    //dtor
    FlushConsoleInputBuffer( hstdin );
    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
}

//-----------------------

void Engine::init()
{
    //Windows handles terminals weirdly...
    GetConsoleScreenBufferInfo( hstdout, &csbi );
}

void Engine::changeTextColor(WORD hexColor)
{
    //Windows handles terminals weirdly...
    SetConsoleTextAttribute(hstdout, hexColor);
}

//-----------------------

Enemy Engine::generateEncounter()
{
    //Generates an Enemy
    Enemy newEnemy=Enemy();
    return newEnemy;
}

Item Engine::generateItem(std::string itemName)
{
    //Generates an Item
    Item newItem=Item();
    newItem.setName(itemName);
    return newItem;
}

Weapon Engine::generateWeapon(std::string weaponName, int damage)
{
    //Generates a Weapon
    Weapon newWeapon=Weapon();
    newWeapon.setBaseDamage(damage);
    newWeapon.setName(weaponName);
    return newWeapon;
}

Item Engine::generateRandomItem()
{
    //Generates an Item, Name based on the list defined at the beginning
    int randomNumber = rand() % itemNames.size();
    return generateItem(itemNames[randomNumber]);
}

Weapon Engine::generateRandomWeapon()
{
    //Generates a Weapon, Name based on the list defined at the beginning, Damage set to random in a range
    int randomNumber = rand() % weaponNames.size();
    int damageDone = rand() % 4 + 4;
    return generateWeapon(weaponNames[randomNumber], damageDone);
}

//-----------------------

Map& Engine::getMap()
{
    return gameMap;
}

void Engine::generateMap()
{
    //First Building the Walls of the Dungeon
    //Not working.. Don't know why, and didn't had the time to seriously debug...

    for (unsigned int i = 1 ; i < coordinates[0]-1 ; i++) {
        //West and East Side of the Dungeon, excluding Corners
        Room westBorder = Room();
        westBorder.setWest(Wall());

        Room eastBorder = Room();
        eastBorder.setEast(Wall());

        gameMap.setRoom(westBorder,i,0);
        gameMap.setRoom(eastBorder,i,coordinates[1]-1);
    }

    for (unsigned int j = 1 ; j < coordinates[1]-1 ; j++) {
        //North and South Side of the Dungeon, excluding Corners

        Room northBorder = Room();
        northBorder.setNorth(Wall());

        Room southBorder=Room();
        southBorder.setSouth(Wall());

        gameMap.setRoom(northBorder,0,j);
        gameMap.setRoom(southBorder,coordinates[0]-1,j);
    }

    //Corners

    Room NWCorner = Room();
    NWCorner.setWest(Wall());
    NWCorner.setNorth(Wall());
    gameMap.setRoom(NWCorner,0,0);

    Room NECorner = Room();
    NECorner.setEast(Wall());
    NECorner.setNorth(Wall());
    gameMap.setRoom(NECorner,0,coordinates[1]-1);

    Room SWCorner = Room();
    SWCorner.setWest(Wall());
    SWCorner.setSouth(Wall());
    gameMap.setRoom(SWCorner,coordinates[0]-1,0);

    Room SECorner = Room();
    SECorner.setEast(Wall());
    SECorner.setSouth(Wall());
    gameMap.setRoom(SECorner,coordinates[0]-1,coordinates[1]-1);

    //Set Inside Walls

    gameMap.getRoom(2,0).setNorth(Wall());
    gameMap.getRoom(1,0).setSouth(Wall());

    gameMap.getRoom(2,1).setEast(Wall());
    gameMap.getRoom(2,2).setWest(Wall());

    gameMap.getRoom(1,1).setEast(Wall());
    gameMap.getRoom(1,2).setWest(Wall());

    gameMap.getRoom(1,1).setNorth(Wall());
    gameMap.getRoom(0,1).setSouth(Wall());

    //

}

