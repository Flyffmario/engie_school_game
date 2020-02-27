#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <vector>

#include "Weapon.h"
#include "Item.h"
#include "Enemy.h"
#include "Map.h"

class Engine
{

    HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;


    public:

        Engine();
        virtual ~Engine();

        void init();
        void changeTextColor(WORD hexColor);

        Enemy generateEncounter();
        Item generateItem(std::string itemName);
        Weapon generateWeapon(std::string weaponName, int damage);
        Item generateRandomItem();
        Weapon generateRandomWeapon();

        Map & getMap();
        void generateMap();

        Map gameMap = Map(3,3);
        std::vector<int> coordinates = {3,3};


    protected:

    private:
        std::vector<std::string> itemNames;
        std::vector<std::string> weaponNames;

};

#endif // ENGINE_H
