#ifndef ENUMS_H
#define ENUMS_H

namespace Enums{
    enum playerClass {
        Scavenger,
        Brawler,
        Marksman,
        Technician
    };

    enum weaponHandling {
        SingleHanded,
        DoubleHanded,
        NoHanded
    };

    enum combatStyle {
        Combat,
        Ranged
    };

    enum objectType {
        Food,
        Tool,
        Material
    };
}

#endif // ENUMS_H_INCLUDED
