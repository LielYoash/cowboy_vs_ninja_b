#include "Character.hpp"

using namespace std;
using namespace ariel;

// General Character functions
Character::Character(string name, Point location)
{
    this->name = name;
    this->location = location;
}

double Character::distance(Character *other)
{
    return this->location.distance(other->location);
}
bool Character::isAlive()
{
    if (this->getHP() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Character::hit(int damage)
{
    this->setHP(this->getHP() - damage);
}

Point Character::getLocation()
{
    return this->location;
}

string Character::getName()
{
    return this->name;
}

int Character::getHP()
{
    return this->HP;
}

void Character::setHP(int updated)
{
    if (updated < 0)
    {
        updated = 0;
    }
    
    this->HP = updated;
}

string Character::getIdentifier()
{
    return this->identifier;
}

string Character::print()
{
    if(this->isAlive()){
        return this->getName() + " " + to_string(this->getHP()) + " ("+ to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")";
    }
    else{
        return "("+this->getIdentifier()+") " "("+ this->getName() + ") " + to_string(this->getHP()) + " ("+ to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")" ;
    }
}

// Cowboy functions
Cowboy::Cowboy(string name, Point location) : Character(name, location) {this->setHP(110);}

bool Cowboy::hasboolets()
{
    return this->numOfBullets > 0;
}

void Cowboy::reload()
{
    if (this->numOfBullets)
    {
        this->numOfBullets = 6;
    }
}

void Cowboy::shoot(Character *enemy)
{
    if (this->isAlive() && this->hasboolets())
    {
        enemy->hit(10);
        this->numOfBullets--;
    }
    if (numOfBullets == 0)
    {
        throw invalid_argument("No Bullets");
    }
    if (this->isAlive() == false)
    {
        throw invalid_argument("Your Cowboy is Dead");
    }
}
string Cowboy::print()
{
    return this->print();
}

// General ninja functions
Ninja::Ninja(string name, Point location) : Character(name, location)
{
}
void Ninja::move(Character *)
{
}
void Ninja::slash(Character *other)
{
}
void Ninja::setSpeed(int)
{
}
int Ninja::getSpeed()
{
    return 1;
}
string Ninja::print()
{
    return "";
}

// The kinds of the ninja
OldNinja::OldNinja(string name, Point location) : Ninja(name, location)
{
}

TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location)
{
}

YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location)
{
}