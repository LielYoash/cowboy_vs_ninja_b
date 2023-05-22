#ifndef TEAM2_HPP
#define TEAM2_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Character.hpp"
#include "Point.hpp"
#include "Team.hpp"

using namespace std;
using namespace ariel;

class Team2
{
public:
    Team2(Character *leader);
    void attack(Team *other);
    void print();
};
#endif // TEAM2_HPP