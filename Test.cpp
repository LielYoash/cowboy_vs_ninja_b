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

// TEST_CASE("Point")
// {
//     Point a(32.3, 44);
//     Point c(4, 5), d(2, 5);
//     CHECK(a.getX() == 32.3);
//     CHECK(a.getY() == 44);
//     CHECK(c.distance(d) == d.distance(c));
//     CHECK(c.distance(d) == 2);
//     Point e = c.move_towards(c, 2, d);
//     CHECK(e.getX() == 2);
//     CHECK(e.getY() == 5);
// }

// TEST_CASE("generic character")
// {
//     Point a(32.3, 44);
//     Character *tom = new Character("Tom", a);
//     CHECK(tom->getName() == "Tom");
//     CHECK(tom->getLocation().getX() == 32.3);
//     CHECK(tom->getLocation().getY() == 44);
//     CHECK(tom->getHP() == 0);
//     CHECK(tom->isAlive() == false);
//     CHECK_THROWS_AS(tom->hit(10), std::invalid_argument);
//     CHECK(tom->getHP() == 0);
//     CHECK(tom->isAlive() == false);
//     tom->setHP(100);
//     CHECK(tom->getHP() == 100);
//     CHECK(tom->isAlive() == true);
//     string s = tom->print();
//     cout << s << endl;
//     tom->setHP(-100);
//     CHECK(tom->getHP() == 0);
//     CHECK(tom->isAlive() == false);
//     tom->setLocation(Point(1, 1));
//     CHECK(tom->getLocation().getX() == 1);
//     CHECK(tom->getLocation().getY() == 1);
//     CHECK(tom->recruited() == false);
//     CHECK_THROWS_AS(tom->recruit(), std::invalid_argument);
//     tom->setHP(100);
//     tom->recruit();
//     CHECK(tom->recruited() == true);
// }

// TEST_CASE("Cowboy")
// {
//     Point a(32.3, 44);
//     Cowboy *tom = new Cowboy("Tom", a);
//     Cowboy *jim = new Cowboy("Jim", a);
//     CHECK(tom->getName() == "Tom");
//     CHECK(tom->getLocation().getX() == 32.3);
//     CHECK(tom->getLocation().getY() == 44);
//     CHECK(tom->getHP() == 110);
//     CHECK(tom->isAlive() == true);
//     CHECK(tom->hasboolets() == true);
//     tom->hit(10);
//     CHECK(tom->getHP() == 100);
//     CHECK(tom->isAlive() == true);
//     tom->hit(100);
//     CHECK(tom->getHP() == 0);
//     CHECK(tom->isAlive() == false);
//     tom->setHP(100);
//     CHECK(tom->getHP() == 100);
//     CHECK(tom->isAlive() == true);
//     string s = tom->print();
//     cout << s << endl;
//     tom->shoot(jim);    
//     CHECK(tom->hasboolets() == true);
//     CHECK_NOTHROW(tom->shoot(jim));
//     CHECK_NOTHROW(tom->shoot(jim));
//     CHECK_NOTHROW(tom->shoot(jim));
//     CHECK_NOTHROW(tom->shoot(jim));
//     CHECK_NOTHROW(tom->shoot(jim));
//     CHECK_THROWS_AS(tom->shoot(jim), std::invalid_argument);
//     CHECK(tom->hasboolets() == false);
//     tom->reload();
//     CHECK(tom->hasboolets() == true);
//     CHECK(tom->recruited() == false);
//     tom->recruit();
//     CHECK(tom->recruited() == true);
// }

// TEST_CASE("Ninja"){
//     Point a(32.3, 44);
//     Point b(35, 37.5);
//     Ninja *hiro = new OldNinja("Hiro", a);
//     Ninja *kenshi = new TrainedNinja("Kenshi", b);
//     Ninja *yogi = new YoungNinja("Yogi", Point(34, 36));
//     CHECK(hiro->getName() == "Hiro");
//     CHECK(hiro->getLocation().getX() == 32.3);
//     CHECK(hiro->getLocation().getY() == 44);
//     CHECK(hiro->getHP() == 150);
//     CHECK(hiro->isAlive() == true);
//     CHECK(hiro->getSpeed() == 8);
//     CHECK(kenshi->getName() == "Kenshi");
//     CHECK(kenshi->getLocation().getX() == 35);
//     CHECK(kenshi->getLocation().getY() == 37.5);
//     CHECK(kenshi->getHP() == 120);
//     CHECK(kenshi->isAlive() == true);
//     CHECK(kenshi->getSpeed() == 12);
//     CHECK(yogi->getName() == "Yogi");
//     CHECK(yogi->getLocation().getX() == 34);
//     CHECK(yogi->getLocation().getY() == 36);
//     CHECK(yogi->getHP() == 100);
//     CHECK(yogi->isAlive() == true);
//     CHECK(yogi->getSpeed() == 14);
//     hiro->hit(10);
//     CHECK(hiro->getHP() == 140);
//     CHECK(hiro->isAlive() == true);
//     hiro->hit(140);
//     CHECK(hiro->getHP() == 0);
//     CHECK(hiro->isAlive() == false);
//     hiro->setHP(150);
//     CHECK(hiro->getHP() == 150);
//     CHECK(hiro->isAlive() == true);
//     string s = hiro->print();
//     cout << s << endl;
//     CHECK_NOTHROW(hiro->move(kenshi));
//     CHECK_NOTHROW(hiro->slash(kenshi));
//     CHECK(hiro->getLocation().getX() == 35);
//     CHECK(hiro->getLocation().getY() == 37.5);
//     CHECK(kenshi->getHP() == 80);
//     CHECK_NOTHROW(hiro->move(yogi));
//     CHECK_NOTHROW(hiro->slash(yogi));
// }

TEST_CASE("simple team"){
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    YoungNinja *sushi = new YoungNinja("sushi", b);
    Team team_A(tom);
    Team team_B(sushi);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 0);
    CHECK(team_B.stillAlive() == 1);
    CHECK_THROWS_AS(team_A.attack(&team_B), std::invalid_argument);
    CHECK_THROWS_AS(team_B.attack(&team_A), std::invalid_argument);
    sushi->setHP(0);
    team_A.print();
    team_B.print();
    OldNinja *kenshi = new OldNinja("Kenshi", Point(35, 37.5));
    team_A.add(kenshi);
    team_A.print();
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12, 81));
    team_A.add(hikari);
    team_A.print();
    Cowboy *jerry = new Cowboy("Jerry", Point(12, 81));
    team_B.add(jerry);
    team_B.print();
}

TEST_CASE("simple team2"){
    Point a(32.3, 44), b(1.3, 3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    YoungNinja *sushi = new YoungNinja("sushi", b);
    Team2 team_A(tom);
    Team2 team_B(sushi);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 1);
    CHECK(team_B.stillAlive() == 1);
    team_A.attack(&team_B);
    team_B.attack(&team_A);
    CHECK(team_A.stillAlive() == 0);
    CHECK(team_B.stillAlive() == 1);
    CHECK_THROWS_AS(team_A.attack(&team_B), std::invalid_argument);
    CHECK_THROWS_AS(team_B.attack(&team_A), std::invalid_argument);
    sushi->setHP(0);
    team_A.print();
    team_B.print();
    OldNinja *kenshi = new OldNinja("Kenshi", Point(35, 37.5));
    team_A.add(kenshi);
    team_A.print();
    TrainedNinja *hikari = new TrainedNinja("Hikari", Point(12, 81));
    team_A.add(hikari);
    team_A.print();
    Cowboy *jerry = new Cowboy("Jerry", Point(12, 81));
    team_B.add(jerry);
    team_B.print();
}


