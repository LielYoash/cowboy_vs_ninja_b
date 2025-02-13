#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>

#include "Point.hpp"

using namespace std;
using namespace ariel;

class Character
{
protected:
    string name;
    Point location;
    int HP =0;
    string identifier;
    bool inTeam;

public:
    Character(string name, Point location);
    bool isAlive();
    double distance(Character *other);
    void hit(int damage);
    string getName();
    Point getLocation();
    void setLocation(Point newLocation);
    string getIdentifier();
    void setIdentifier(Character *other);
    int getHP();
    void setHP(int newHP);
    virtual string print();
    virtual void recruit(bool);
    virtual bool recruited();
};

class Cowboy : public Character
{
private:
    int numOfBullets = 6;

public:
    Cowboy(string name, Point location);
    void reload();
    void shoot(Character *other);
    string print();
    bool hasboolets();
};

class Ninja : public Character
{
private:
    int speed;

public:
    Ninja(string name, Point location);
    void move(Character *other);
    void slash(Character *other);
    int getSpeed();
    string print();
    void setSpeed(int newSpeed);
};

class OldNinja : public Ninja
{
public:
    OldNinja(string name, Point location);
};

class TrainedNinja : public Ninja
{
public:
    TrainedNinja(string name, Point location);
};

class YoungNinja : public Ninja
{
public:
    YoungNinja(string name, Point location);
};

#endif // CHARACTER_HPP
