#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Enums.h"
#include "Entity.h"
#include "Weapon.h"
#include "Inventory.h"

class Player : public Entity
{



    public:
        Player(std::string firstName, Enums::playerClass firstClass);
        virtual ~Player();

        std::string getName();
        void setName(const std::string newName);

        int getHp();
        void setHp(int newHp);

        int getFp();
        void setFp(int newFp);

        Weapon getWeapon();
        void setWeapon(Weapon &newWeapon);

        int getBaseDamage();
        void setBaseDamage(int newBaseDamage);

        Enums::playerClass getClass();
        void setClass(Enums::playerClass classPlayed);

        Inventory & getInventory();

    protected:

    private:
        int hp = 100;
        int fp = 100;
        std::string name;
        Enums::playerClass actualClass;
        Weapon currentWeapon = Weapon();
        int baseDamage = 3;
        Inventory inventory;

};

#endif // PLAYER_H
