#include "Enemy.h"
#include "Weapon.h"
#include "Item.h"

Enemy::Enemy()
{
    //ctor
    currentWeapon.setName("None");
}

Enemy::~Enemy()
{
    //dtor
}

int Enemy::attack()
{
    if ((currentWeapon.getName()).compare("None")==0){
        return baseDamage;
    } else {
        return currentWeapon.getBaseDamage();
    }
}

int Enemy::getBaseDamage()
{
    return baseDamage;
}

void Enemy::setBaseDamage(int newBaseDamage)
{
    baseDamage=newBaseDamage;
}

Weapon Enemy::getWeapon()
{
    return currentWeapon;
}

void Enemy::setWeapon(Weapon newWeapon)
{
    currentWeapon=newWeapon;
}

int Enemy::getHp()
{
    return hp;
}

void Enemy::setHp(int newHp)
{
    hp=newHp;
}

