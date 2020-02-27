#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include "Entity.h"

class Item : public Entity
{

    public:
        explicit Item();
        virtual ~Item();

        std::string getName();
        void setName(std::string newName);

        int getWeight();
        void setWeight(int newWeight);

        int getVolume();
        void setVolume(int newVolume);

    protected:

    private:
        int weight;
        int volume;
        std::string name;
};



#endif // ITEM_H
