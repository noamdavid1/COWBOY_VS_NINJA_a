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

    class Team
    {
    private:
    std::vector<Character*> fighters;
    Character* leader;
    public:
        Team(Character *leader); //initialization constructor.
        ~Team(); //destruction function.
        void add(Character *player); //add a character to the team.
        void attack(Team *other); //Gets a pointer to the enemy team and attacks it.
        int stillAlive(); //Returns an integer number of surviving group members.
        string print(); //Goes through all the characters in the group and prints their details.
    };

}