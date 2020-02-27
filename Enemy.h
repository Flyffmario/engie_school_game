#ifndef ENEMY_H
#define ENEMY_H

#include "Weapon.h"

class Enemy : public Entity
{
    public:
        Enemy();
        virtual ~Enemy();

        int attack();
        int getBaseDamage();
        void setBaseDamage(int newBaseDamage);

        int getHp();
        void setHp(int newHp);

        Weapon getWeapon();
        void setWeapon(Weapon newWeapon);

    protected:

    private:
        int hp = 15;
        Weapon currentWeapon = Weapon();
        int baseDamage = 3;
};

#endif // ENEMY_H
