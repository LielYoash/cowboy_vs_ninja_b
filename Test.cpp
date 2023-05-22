#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/smartTeam.hpp"
#include "sources/Point.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("Point")
{
    Point a(32.3, 44);
    Point c(4, 5), d(2, 5);
    for (int i = 0; i < 20; i++)
    {
        CHECK(a.getX() == 32.3);
        CHECK(a.getY() == 44);
        CHECK(c.distance(d) == d.distance(c));
        CHECK(c.distance(d) == 2);
        Point e = c.move_towards(c, 1.5, d);
        CHECK(e.getX() == 3.5);
        CHECK(e.getY() == 5);
    }
}

TEST_CASE("Character")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    YoungNinja *yogi = new YoungNinja("Yogi", Point(64, 57));
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12, 81));
    CHECK(tom->getName() == "Tom");
    CHECK(tom->getLocation().getX() == 32.3);
    CHECK(tom->getLocation().getY() == 44);
    CHECK(tom->getHP() == 110);
    CHECK(tom->isAlive() == true);
    CHECK(sushi->getName() == "sushi");
    CHECK(sushi->getLocation().getX() == 1.3);
    CHECK(sushi->getLocation().getY() == 3.5);
    CHECK(sushi->getHP() == 150);
    CHECK(sushi->isAlive() == true);
    CHECK(yogi->getName() == "Yogi");
    CHECK(yogi->getLocation().getX() == 64);
    CHECK(yogi->getLocation().getY() == 57);
    CHECK(yogi->getHP() == 100);
    CHECK(yogi->isAlive() == true);
    CHECK(hikari->getName() == "Hikari");
    CHECK(hikari->getLocation().getX() == 12);
    CHECK(hikari->getLocation().getY() == 81);
    CHECK(hikari->getHP() == 120);
    CHECK(hikari->isAlive() == true);
    tom->hit(10);
    sushi->hit(10);
    if (sushi->distance(tom) < 10)
    {
        sushi->slash(tom);
    }
    else
    {
        sushi->move(tom);
    }
    CHECK(tom->getHP() == 60);
    CHECK(sushi->getHP() == 130);
    CHECK(tom->isAlive() == true);
    CHECK(sushi->isAlive() == true);
    tom->shoot(sushi);
    CHECK(sushi->getHP() == 120);
    CHECK(sushi->isAlive() == true);
    sushi->move(tom);
    CHECK(sushi->getLocation().getX() == 32.3);
    CHECK(sushi->getLocation().getY() == 44);
    sushi->slash(tom);
    CHECK(tom->getHP() == 40);
    CHECK(tom->isAlive() == true);
}

TEST_CASE("Teams")
{
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    YoungNinja *yogi = new YoungNinja("Yogi", Point(64, 57));
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12, 81));
    Team team_A(tom);
    Team team_B(sushi);
    team_A.add(yogi);
    team_B.add(hikari);
    CHECK(team_A.stillAlive() == 2);
    CHECK(team_B.stillAlive() == 2);
    team_A.attack(&team_B);
    CHECK(team_B.stillAlive() == 1);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    team_A.print();
    team_B.print();
    team_A.attack(&team_B);
    CHECK(team_B.stillAlive() == 0);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 0);
    team_A.print();
    team_B.print();
    CHECK(team_A.stillAlive() == 0);
    CHECK(team_B.stillAlive() == 0);
}


