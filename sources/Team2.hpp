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

    class Team2
    {
    private:
    std::vector<Character*> fighters;
    Character* leader;
    public:
        Team2(Character *leader);
        ~Team2();
        void add(Character *player);
        void attack(Team2 *other);
        int stillAlive();
        string print();
    };

}