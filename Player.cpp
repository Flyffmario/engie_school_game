#include <iostream>
#include "Player.h"
#include "Enums.h"
#include "Inventory.h"

Player::Player(std::string firstName, Enums::playerClass firstClass)
{
    //ctor
    name=firstName;
    actualClass=firstClass;
    //create the weapon
    currentWeapon.setName("Hammer");
    currentWeapon.setBaseDamage(2);
    currentWeapon.setDescription("A sturdy weapon.");
}

Player::~Player()
{
    //dtor
}

//-----------------------

std::string Player::getName()
{
    return name;
}

void Player::setName(const std::string newName)
{
    name=newName;
}

int Player::getHp()
{
    return hp;
}

void Player::setHp(int newHp)
{
    hp=newHp;
}

//-----------------------

int Player::getFp()
{
    return fp;
}

void Player::setFp(int newFp)
{
    fp=newFp;
}

//-----------------------

Enums::playerClass Player::getClass()
{
    return actualClass;
}

void Player::setClass(Enums::playerClass classPlayed)
{
    actualClass=classPlayed;
}

//-----------------------

Weapon Player::getWeapon()
{
    return currentWeapon;
}

void Player::setWeapon(Weapon &newWeapon)
{
    currentWeapon=newWeapon;
}

int Player::getBaseDamage()
{
    return baseDamage;
}

void Player::setBaseDamage(int newBaseDamage)
{
    baseDamage=newBaseDamage;
}

//-----------------------

Inventory & Player::getInventory()
{
    return inventory;
}

