#include "Inventory.h"
#include "Item.h"

#include <vector>
#include "Item.h"

Inventory::Inventory()
{
    //ctor
}

Inventory::~Inventory()
{
    //dtor
}

std::vector<Item> & Inventory::getItems()
{
    return items;
}

void Inventory::insertItemAt(Item item, int i)
{
    items[i]=item;
}

Item & Inventory::getItemAt(int i)
{
    return items[i];
}

void Inventory::removeItemAt(int i)
{
    items[i]=Item();
}

void Inventory::insertItem(Item item)
{
    items.push_back(item);
}

void Inventory::printContents()
{
    for (unsigned int i = 0; i < items.size(); ++i) {
        std::cout << items[i].getName() << std::endl;
    }
}


