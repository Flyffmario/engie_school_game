#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include <time.h>


#include "Player.h"
#include "Enums.h"
#include "Item.h"
#include "Weapon.h"
#include "Engine.h"
#include "Enemy.h"

int main()
{
    Player newPlayer = Player("Marc",Enums::Brawler);

    // Text based.

    const WORD colors[] =
		{
		    0xa0
		};

    Engine engine;
    engine.init();
    engine.changeTextColor(colors[0]);

    std::string command;
    command="";
    std::cout << "You find yourself in the end of a corridor. You know you have to get out of here. Type 'help' for help.\n";

    //Pre-Allowing what comes to the Player
    Enemy * currentEnemy = nullptr;
    Item * currentItem = nullptr;
    Weapon * currentWeapon = nullptr;

    Map & currentMap = engine.gameMap;
    engine.gameMap.generateMap();

    srand(time(NULL));
    int randomNumber;
    int randomNumber2;

    //I don't want the game to end as soon as the player enter. So I created a minimum number of turns before he can exit.
    int numberOfTurns=5;

    while(command.compare("quit")){

        if (command.compare("help") == 0) {
          std::cout << "help \nproceed \nattack \ninventory \nmap \ntake \nrunaway \nsuicide \nruinthefun \nquit" << std::endl;
        }

        //Interactions

        if (command.compare("attack") == 0 && currentEnemy!=NULL) {
            //Attack !
          std::cout << "You attack the monster with your Weapon..." << std::endl;
          int damageDone = (rand() % newPlayer.getBaseDamage() + newPlayer.getWeapon().getBaseDamage());
          currentEnemy->setHp(currentEnemy->getHp()-damageDone);
          std::cout << "You deal " << damageDone << " damage !" << std::endl;
          std::cout << "The monster is at " << currentEnemy->getHp() << " Hp !" << std::endl;
        }

        if (command.compare("runaway") == 0) {
            //Flee. A good strategy if you are unarmed.
            std::cout << "You flee the combat..." << std::endl;
            int damage = currentEnemy->attack();
            damage*=5;
            newPlayer.setHp(newPlayer.getHp()-damage);
            std::cout << "The Enemy sees an opportunity and attacks, dealing " << damage << " damage !" << std::endl;
            std::cout << "You remain at " << newPlayer.getHp() << " Hp." << std::endl;
            currentEnemy=nullptr;
        }

        if (command.compare("take") == 0 && currentItem!=NULL) {
            //Take the item in your inventory
            //But Item behavior hasn't been coded yet
          std::cout << "You take the Item in your Inventory..." << std::endl;

          Inventory & playerInventory = newPlayer.getInventory();
          playerInventory.insertItem(*currentItem);
          currentItem=nullptr;
        }

        if (command.compare("take") == 0 && currentWeapon!=NULL) {
            //Take the weapon and replace your current one
          std::cout << "You take the Weapon and replace your current Weapon with it..." << std::endl;

          newPlayer.setWeapon(*currentWeapon);
          currentWeapon=nullptr;
        }

        if (command.compare("inventory") == 0) {
            //Print the Inventory
            Inventory & playerInventory = newPlayer.getInventory();
            playerInventory.printContents();
        }

        if (command.compare("suicide") == 0) {
            //Does what it does
            newPlayer.setHp(0);
        }

        if (command.compare("map") == 0) {
            //Non-Functional. Still debugging the map itself to show at least a prefunctional map.
            engine.getMap().printMap();
        }

        if (command.compare("ruinthefun") == 0) {
            //If Winning is too hard
            std::cout << "You found the exit sucker ! A burning light blinds your pathetic eyes..." << std::endl;
            break;
        }

        //New Possible Interactions
        if (command.compare("proceed") == 0 && currentEnemy==NULL) {
            //Main way to move in the corridor
            std::cout << "You venture farther in the corridor.." << std::endl;

            randomNumber=rand() % 5;
            currentItem=nullptr;
            currentWeapon=nullptr;

            if (randomNumber==0){
                //Nothing, proceed
                std::cout << "Nothing out of the ordinary." << std::endl;

            } else if (randomNumber==1 || (randomNumber==4 && numberOfTurns>=0)) {

                //Item or Weapon
                randomNumber2=rand() % 2;

                if (randomNumber2==0){
                    //Item
                    std::cout << "You find an item on the ground !" << std::endl;
                    Item foundItem = engine.generateRandomItem();
                    std::cout << "The Item is " << foundItem.getName() << std::endl;
                    currentItem=&foundItem;
                } else {
                    //Weapon
                    std::cout << "You find a weapon on the ground !" << std::endl;
                    Weapon foundWeapon = engine.generateRandomWeapon();
                    std::cout << "The Weapon is " << foundWeapon.getName() << " and its base damage is " << foundWeapon.getBaseDamage() << std::endl;
                    currentWeapon=&foundWeapon;
                }

            } else if (randomNumber==2 || randomNumber==3) {
                //Monster

                std::cout << "You encounter a monster !" << std::endl;
                Enemy foundEnemy = engine.generateEncounter();
                currentEnemy = &foundEnemy;

            } else if (randomNumber == 4 && numberOfTurns < 0){
                //Exit

                std::cout << "You found the exit ! A warm light enlit your face..." << std::endl;
                break;

            }
            numberOfTurns-=1;
        }

        //If the monster exists, it attacks

        if (currentEnemy!=NULL) {
            //dostuff
            if (currentEnemy->getHp()>0) {
                int damage = currentEnemy->attack();
                newPlayer.setHp(newPlayer.getHp()-damage);
                std::cout << "The Enemy attacks, dealing " << damage << " damage !" << std::endl;
                std::cout << "You remain at " << newPlayer.getHp() << " Hp." << std::endl;
            } else {
                std::cout << "The Monster has been defeated ! You are free to proceed..." << std::endl;
                currentEnemy=nullptr;
            }

        }

        if (newPlayer.getHp() <= 0) {
            std::cout << "You died. Game Over !" << std::endl;
            break;
        }

        command="";
        std::cout << std::endl;
        std::cout << "Please enter your next action : ";
        std::cin >> command;
        std::cout << std::endl;
    }

    return 0;
}
