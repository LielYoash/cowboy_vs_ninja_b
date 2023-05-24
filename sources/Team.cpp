#include "Team.hpp"
using namespace std;
using namespace ariel;

Team::Team(Character *leader)
{
    this->team.clear();
    if (leader == nullptr)
    {
        throw invalid_argument("Character is null");
    }
    if (leader->isAlive() == false)
    {
        throw invalid_argument("Character is dead");
    }
    if (leader->recruited() == true)
    {
        throw invalid_argument("Character is already recruited");
    }
    this->leader = leader;
    this->team.push_back(leader);
}

Team::~Team()
{
    for (std::vector<Character*>::size_type i =0; i < team.size(); i++)
    {
        delete team.at(i);
    }
}

bool Team::inGame(Character *member)
{
    if (member->recruited())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Team::add(Character *newMember)
{
    if (newMember == nullptr)
    {
        throw invalid_argument("Character is null");
    }
    if (team.size() < 10)
    {
        newMember->recruit();
        team.push_back(newMember);
    }
    else
    {
        throw invalid_argument("Team is full");
    }
}

void Team::print()
{
    for (int i =0; i < 2; i++)
    {
        for(std::vector<Character*>::size_type j=0; j < team.size(); j++){
            if(i==0){
                if(dynamic_cast<Cowboy*>(team.at(j)) != nullptr){
                    cout << dynamic_cast<Cowboy*>(team.at(j))->print()<< endl;
                }
            }
            else{
                if(dynamic_cast<Ninja*>(team.at(j)) != nullptr){
                    cout << dynamic_cast<Ninja*>(team.at(j))->print()<< endl;
                }
            }
        }
    }
}

int Team::stillAlive()
{
    int alive = 0;
    for (std::vector<Character*>::size_type i =0; i < team.size(); i++)
    {
        if (team.at(i)->isAlive())
        {
            alive++;
        }
    }
    return alive;
}

void Team::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
    {
        throw invalid_argument("Team is null");
    }
    if (enemyTeam->stillAlive() == 0)
    {
        throw invalid_argument("Team is dead");
    }
    if (enemyTeam->getLeader()->isAlive() == false)
    {
        enemyTeam->potencialVictim(enemyTeam, enemyTeam->getLeader());
    }
    if (enemyTeam == this)
    {
        throw invalid_argument("Team is attacking itself");
    }
    if(this->stillAlive() == 0)
    {
        throw invalid_argument("Team is dead");
    }

    Character *victim = potencialVictim(enemyTeam, this->leader);
    for (auto teamate : team)
    {
        if (this->stillAlive() == 0 || enemyTeam->stillAlive() == 0)
        {
            break;
        }
        if (teamate->isAlive() == false)
        {
            continue;
        }
        if (victim->isAlive() == false)
        {
            victim = potencialVictim(enemyTeam, this->leader);
        }
        if (dynamic_cast<Cowboy *>(teamate) != nullptr && dynamic_cast<Cowboy *>(teamate)->hasboolets())
        {
            dynamic_cast<Cowboy *>(teamate)->shoot(victim);
        }
        else if (dynamic_cast<Cowboy *>(teamate) != nullptr && dynamic_cast<Cowboy *>(teamate)->hasboolets() == false)
        {
            dynamic_cast<Cowboy *>(teamate)->reload();
        }
    }
    for (auto teamate : team)
    {
        if (this->stillAlive() == 0 || enemyTeam->stillAlive() == 0)
        {
            break;
        }
        if (teamate->isAlive() == false)
        {
            continue;
        }
        if (victim->isAlive() == false)
        {
            victim = potencialVictim(enemyTeam, this->leader);
        }
        if(dynamic_cast<Ninja*>(teamate) != nullptr && teamate->distance(victim)<=1){
            dynamic_cast<Ninja*>(teamate)->slash(victim);
        }
        else if (dynamic_cast<Ninja*>(teamate) != nullptr && teamate->distance(victim)>1){
            dynamic_cast<Ninja*>(teamate)->move(victim);
        }
    }
}

Character *Team::potencialVictim(Team *Team, Character *leader)
{
    double minDistance = 1000000;
    std::vector<Character*>::size_type index = 0;
    for (std::vector<Character*>::size_type i =0; i < Team->team.size(); i++)
    {
        if (Team->team.at(i)->isAlive())
        {
            if (Team->team.at(i)->distance(leader) < minDistance)
            {
                minDistance = Team->team.at(i)->distance(leader);
                index = i;
            }
        }
    }
    return Team->team.at(index);
}

Character *Team::getLeader()
{
    return this->leader;
}

void Team::setLeader(Character *newLeader)
{
    this->leader = newLeader;
}