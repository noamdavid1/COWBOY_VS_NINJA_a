#include "Character.hpp"

namespace ariel
{
    Character::Character(const Point &location, int hit_points,const string &character_name)
    {

    }
    bool Character::isAlive()
    {
        return true;
    }
    double Character::distance(Character &other)
    {
        return 0.0;
    }
    void Character::hit(int hitpoints)
    {
    }
    string Character::getName()
    {
        return "";
    }
    Point Character::getLocation()
    {
        return Point(0.0, 1.0);
    }
    string Character::print()
    {
        return "";
    }
    int Character::getHitpoints() { return 0; }
}