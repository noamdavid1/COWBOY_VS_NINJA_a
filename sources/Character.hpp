#pragma once
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point location;
        int hit_points;
        string character_name;

    public:
        Character(const Point &location, int hit_points,const string &character_name); //initialization constructor.
        virtual ~Character() = default; //destruction function.
        bool isAlive(); //returns true if the character still in the game.
        double distance(Character &other); //returns the distance between two character.
        void hit(int hitpoints); //Subtracts the appropriate amount of hit points from the character.
        string getName(); //returns the name of the character.
        Point getLocation();//returns the location of the character.
        string print(); //Prints the name of the character, the number of its hit points, and the point where the character is.
        int getHitpoints(); //returns the hit points of the character.
    };
}