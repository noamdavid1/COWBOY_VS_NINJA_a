#pragma once
#include "Point.hpp"
#include "Character.hpp"
#include <string>

using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets_num;

    public:
        Cowboy(const string &cowboy_name, Point location); //initalizaition constructor.
        void shoot(Character *enemy); //Receives a pointer to the enemy. The cowboy shoots the enemy, subtracting 10 hit points from the enemy and losing 1 bullet.
        bool hasboolets(); //returns true if there are any bullets left in the cowboy's gun.
        void reload(); //Loads the gun with six new bullets.
        int getBulletsnum(); //returns the number of bullets that left in the cowboy's gun.
    };
}