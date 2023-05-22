#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "Character.hpp"
#include "Point.hpp"


using namespace std;
using namespace ariel;

class Team{
    private:
    vector <Character*> team;
    const int maxTeamSize = 10;
    Character *leader;
    public:
    Team(Character *leader);
    void add(Character *newMember);
    virtual void print();
    int stillAlive();
    void attack(Team *other);
};
#endif // TEAM_HPP