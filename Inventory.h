#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();

        std::vector<Item> & getItems();
        void insertItemAt(Item item, int i);
        Item & getItemAt(int i);
        void removeItemAt(int i);
        void insertItem(Item item);
        void printContents();

    protected:

    private:
        std::vector<Item> items;
};

#endif // INVENTORY_H
