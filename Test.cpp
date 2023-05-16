#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("initialize characters")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    TrainedNinja *yarden = new TrainedNinja("yarden", Point(1.2, 4.0));
    YoungNinja *maor = new YoungNinja("maor", Point(1.0, 4.1));
    CHECK_EQ(tom->getBulletsnum(), 6);
    CHECK_EQ(tom->getHitpoints(), 110);
    CHECK_EQ(maor->getSpeed(), 14);
    CHECK_EQ(yarden->getSpeed(), 12);
    CHECK_EQ(sushi->getSpeed(), 8);
    CHECK_EQ(maor->getHitpoints(), 100);
    CHECK_EQ(yarden->getHitpoints(), 120);
    CHECK_EQ(sushi->getHitpoints(), 150);
}

TEST_CASE("characters's functions")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    TrainedNinja *yarden = new TrainedNinja("yarden", Point(1.2, 4.0));
    YoungNinja *maor = new YoungNinja("maor", Point(1.0, 4.1));
    tom->shoot(sushi);
    CHECK_EQ(sushi->getHitpoints(), 140);
    CHECK_EQ(tom->getBulletsnum(), 5);
    CHECK(tom->hasboolets());
    tom->reload();
    CHECK_EQ(tom->getBulletsnum(), 11);
    maor->move(tom);
    CHECK_EQ(maor->getLocation(), Point(15.0, 18.1));
    maor->slash(tom);
    CHECK_EQ(tom->getHitpoints(), 110);
    for (int i = 0; i < 4; i++)
    {
        sushi->move(tom);
    }
    sushi->slash(tom);
    CHECK_EQ(tom->getHitpoints(), 70);
}

TEST_CASE("team's functions")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_A(tom);
    Team team_B(sushi);
    TrainedNinja *yarden = new TrainedNinja("yarden", Point(1.2, 4.0));
    YoungNinja *maor = new YoungNinja("maor", Point(1.0, 4.1));
    team_A.add(yarden);
    team_B.add(maor);
    CHECK_EQ(team_A.stillAlive(), 2);
    CHECK_EQ(team_B.stillAlive(), 2);
    CHECK_NOTHROW(team_A.attack(&team_B));
    CHECK_EQ(sushi->getHitpoints(), 100);
    CHECK_EQ(tom->getBulletsnum(), 5);
    CHECK_EQ(team_A.stillAlive(), 2);
    CHECK_EQ(team_B.stillAlive(), 2);
    CHECK_NOTHROW(team_B.attack(&team_A));
    CHECK_EQ(yarden->getHitpoints(), 40);
}

TEST_CASE("end of the game")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_A(tom);
    Team team_B(sushi);
    TrainedNinja *yarden = new TrainedNinja("yarden", Point(1.2, 4.0));
    YoungNinja *maor = new YoungNinja("maor", Point(1.0, 4.1));
    team_A.add(yarden);
    team_B.add(maor);
    while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
    {
        team_A.attack(&team_B);
        team_B.attack(&team_A);
    }
    if (team_A.stillAlive() == 0)
    {
        CHECK_FALSE(tom->isAlive());
        CHECK_FALSE(yarden->isAlive());
    }
    else
    {
        CHECK_FALSE(sushi->isAlive());
        CHECK_FALSE(maor->isAlive());
    }
}
TEST_CASE("throwing errors")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    Team team_A(tom);
    Team team_B(sushi);
    TrainedNinja *yarden = new TrainedNinja("yarden", Point(1.2, 4.0));
    YoungNinja *maor = new YoungNinja("maor", Point(1.0, 4.1));
    team_A.add(yarden);
    team_B.add(maor);
    CHECK_THROWS(tom->shoot(tom));
    CHECK_THROWS(yarden->slash(yarden));

    for (int i = 0; i < 6; i++)
    {
        tom->shoot(maor);
    }
    CHECK_THROWS(tom->shoot(maor));
    while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
    {
        team_A.attack(&team_B);
        team_B.attack(&team_A);
    }
    CHECK_THROWS(team_A.attack(&team_B));
    CHECK_THROWS(team_B.attack(&team_A));
}
