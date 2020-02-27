#include "Weapon.h"
#include "Item.h"

Weapon::Weapon()
{
    //ctor;
    entityName="Weapon";
    description="A tool of destruction lies at the center of the room...";
}

Weapon::~Weapon()
{
    //dtor
}
Enums::weaponHandling Weapon::getHandling()
{
    //Not implemented yet
    return handling;
}

void Weapon::setHandling(Enums::weaponHandling newHandling)
{
    //Not implemented yet
    handling=newHandling;
}

Enums::combatStyle Weapon::getCombatStyle()
{
    //Not implemented yet
    return combatStyle;
}

void Weapon::setCombatStyle(Enums::combatStyle newCombatStyle)
{
    combatStyle=newCombatStyle;
}

int Weapon::getBaseDamage()
{
    return baseDamage;
}

void Weapon::setBaseDamage(int newBaseDamage)
{
    baseDamage=newBaseDamage;
}



