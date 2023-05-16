#include "Cowboy.hpp"
#include "Point.hpp"
#include <string>

namespace ariel
{
    Cowboy::Cowboy(const string &cowboy_name, Point location): Character(location,110,cowboy_name),bullets_num(6) {}
    void Cowboy::shoot(Character *enemy) {}
    bool Cowboy::hasboolets()
    {
        return true;
    }
    void Cowboy::reload() {}
    int Cowboy::getBulletsnum() { return 6; }
}