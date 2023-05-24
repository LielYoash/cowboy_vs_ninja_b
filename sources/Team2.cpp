#include "Team2.hpp"
using namespace std;
using namespace ariel;

Team2::Team2(Character *leader) : Team(leader) {}
void Team2::attack(Team *enemyTeam)
{
    if (enemyTeam == nullptr)
    {
        throw invalid_argument("Team is null");
    }
    if (enemyTeam->stillAlive() == 0)
    {
        throw invalid_argument("Team is dead");
    }
    if (this->stillAlive() == 0)
    {
        throw invalid_argument("Team is dead");
    }
    if (enemyTeam == this)
    {
        throw invalid_argument("Team is attacking itself");
    }
    if (enemyTeam->getLeader()->isAlive() == false)
    {
        enemyTeam->potencialVictim(enemyTeam, enemyTeam->getLeader());
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
        else if (dynamic_cast<Ninja *>(teamate) != nullptr && dynamic_cast<Ninja *>(teamate)->distance(victim) <= 1)
        {
            dynamic_cast<Ninja *>(teamate)->slash(victim);
        }
        else if (dynamic_cast<Ninja *>(teamate) != nullptr && dynamic_cast<Ninja *>(teamate)->distance(victim) > 1)
        {
            dynamic_cast<Ninja *>(teamate)->move(victim);
        }
    }
}
void Team2::print()
{
    for (std::vector<Character *>::size_type i = 0; i != team.size(); i++)
    {
        cout << team.at(i)->print() << endl;
    }
}
