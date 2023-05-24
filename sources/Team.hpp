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
    protected:
    vector <Character*> team{10};
    Character *leader;
    public:
    Team(Character *leader);
    ~Team();
    bool inGame(Character *member);
    void add(Character *newMember);
    virtual void print();
    int stillAlive();
    virtual void attack(Team *other);
    Character* potencialVictim(Team *Team, Character *leader);
    Character *getLeader();
    void setLeader(Character *newLeader);
};
#endif // TEAM_HPP