#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        std::string getDescription();
        void setDescription(std::string ongoingDescription);
        std::string getEntityName();
        void setEntityName(std::string newEntityName);

        std::string entityName;
        std::string description;

    protected:

    private:
};

#endif // ENTITY_H
