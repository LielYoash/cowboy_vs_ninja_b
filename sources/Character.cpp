#include "Character.hpp"

using namespace std;
using namespace ariel;

//--------------------------------------------------------------------------------//
//---------------------------General Character functions--------------------------//
//--------------------------------------------------------------------------------//

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
    if (damage > 0 && this->isAlive())
    {
        this->setHP(this->getHP() - damage);
    }
    else
    {
        throw invalid_argument("Damage must be positive");
    }
}

Point Character::getLocation()
{
    return this->location;
}

void Character::setLocation(Point newLocation)
{
    this->location = newLocation;
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

void Character::setIdentifier(Character *other)
{
    if (dynamic_cast<Cowboy *>(other) != nullptr)
    {
        this->identifier = "C";
    }
    else if (dynamic_cast<Ninja *>(other) != nullptr)
    {
        this->identifier = "N";
    }
    else
    {
        throw invalid_argument("Character is not a Cowboy or a Ninja");
    }
}

string Character::print()
{
    return getIdentifier();
}

void Character::recruit()
{
    if (isAlive() == false)
    {
        throw invalid_argument("Character is dead");
    }
    else
    {
        this->inTeam = true;
    }
}

bool Character::recruited()
{
    return this->inTeam;
}

//--------------------------------------------------------------------------------//
//--------------------------------Cowboy functions--------------------------------//
//--------------------------------------------------------------------------------//
Cowboy::Cowboy(string name, Point location) : Character(name, location)
{
    this->setHP(110);
    setIdentifier(this);
}

bool Cowboy::hasboolets()
{
    return this->numOfBullets > 0;
}

void Cowboy::reload()
{
    if (this->numOfBullets < 6)
    {
        this->numOfBullets = 6;
    }
}

void Cowboy::shoot(Character *enemy)
{
    if (numOfBullets == 0)
    {
        throw invalid_argument("No Bullets");
    }
    if (this->isAlive() && this->hasboolets())
    {
        enemy->hit(10);
        this->numOfBullets--;
    }
    if (this->isAlive() == false)
    {
        throw invalid_argument("Your Cowboy is Dead");
    }
}

string Cowboy::print()
{
    if (this->isAlive())
    {
        return this->getName() + " " + to_string(this->getHP()) + " (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")";
    }
    else
    {
        return "(" + this->getIdentifier() + ") "
                                             "(" +
               this->getName() + ") " + to_string(this->getHP()) + " (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")";
    };
}

//--------------------------------------------------------------------------------//
//----------------------------General Ninja functions-----------------------------//
//--------------------------------------------------------------------------------//
Ninja::Ninja(string name, Point location) : Character(name, location) { setIdentifier(this); }

void Ninja::move(Character *enemy)
{
    this->setLocation(this->getLocation().move_towards(getLocation(), this->getSpeed(), enemy->getLocation()));
}

void Ninja::slash(Character *enemy)
{
    if (enemy->isAlive() == false)
    {
        throw invalid_argument("Enemy is Dead");
    }

    if (this->isAlive() && this->getLocation().distance(enemy->getLocation()) <= 1)
    {
        enemy->hit(40);
    }
    else
    {
        throw invalid_argument("Enemy is too far");
    }
}

void Ninja::setSpeed(int newSpeed)
{
    this->speed = newSpeed;
}

int Ninja::getSpeed()
{
    return this->speed;
}

string Ninja::print()
{
    if (this->isAlive())
    {
        return this->getName() + " " + to_string(this->getHP()) + " (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")";
    }
    else
    {
        return "(" + this->getIdentifier() + ") "
                                             "(" +
               this->getName() + ") " + to_string(this->getHP()) + " (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")";
    };
}

// The kinds of the ninja
OldNinja::OldNinja(string name, Point location) : Ninja(name, location)
{
    this->setHP(150);
    this->setSpeed(8);
}

TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location)
{
    this->setHP(120);
    this->setSpeed(12);
}

YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location)
{
    this->setHP(100);
    this->setSpeed(14);
}