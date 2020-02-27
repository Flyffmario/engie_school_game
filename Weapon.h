#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Enums.h"

class Weapon : public Item
{

    Enums::weaponHandling handling;
    Enums::combatStyle combatStyle;

    int baseDamage;

    public:
        explicit Weapon();
        virtual ~Weapon();

        Enums::weaponHandling getHandling();
        void setHandling(Enums::weaponHandling newHandling);
        Enums::combatStyle getCombatStyle();
        void setCombatStyle(Enums::combatStyle newCombatStyle);

        int getBaseDamage();
        void setBaseDamage(int newBaseDamage);

    protected:

    private:
};

#endif // WEAPON_H
