#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include <iostream>
#include <fstream> 
#include <sstream>
#include <stdexcept>

#include "Team.hpp"

using namespace std;
using namespace ariel;

class smartTeam : public Team{
    public:
    smartTeam(Character *leader);
    void attack(Team *other);
    void print();
};
#endif // SMARTTEAM_HPP

