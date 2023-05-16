#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) {}
    SmartTeam::~SmartTeam() {}
    void SmartTeam::add(Character *player) {}
    void SmartTeam::attack(SmartTeam *other) {}
    int SmartTeam::stillAlive() { return 1; }
    string SmartTeam::print() { return ""; }
}