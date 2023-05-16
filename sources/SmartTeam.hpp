#pragma once

#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Ninja.hpp"

#include <iostream>
#include <vector>

namespace ariel
{

    class SmartTeam
    {
    private:
    std::vector<Character*> fighters;
    Character* leader;
    public:
        SmartTeam(Character *leader);
        ~SmartTeam();
        void add(Character *player);
        void attack(SmartTeam *other);
        int stillAlive();
        string print();
    };

}