#include "Character.hpp"

using namespace std;
using namespace ariel;

//General Character functions
Character::Character(string name,Point location){

}
double Character::distance(Character* other){
    return 0;
}
bool Character::isAlive(){
    return false;
}
void Character::hit(int damage){

}
Point Character::getLocation(){
    return Point(0,0);
}
string Character::getName(){
    return "";
}
int Character::getHP(){
    return 1;
}
void Character::setHP(int updated){

}
string Character::print(){
    return "";
}

//Cowboy functions
Cowboy::Cowboy(string name,Point location):Character(name,location){
}
bool Cowboy::hasboolets(){
    return false;
}
void Cowboy::reload(){

}
void Cowboy::shoot(Character* enemy){

}
string Cowboy::print(){
    return "";
}

//General ninja functions
Ninja::Ninja(string name,Point location):Character(name,location){

}
void Ninja::move(Character*){

}
void Ninja::slash(Character *other){

}
void Ninja::setSpeed(int){

}
int Ninja::getSpeed(){
    return 1;
}
string Ninja::print(){
    return "";
}

//The kinds of the ninja
OldNinja::OldNinja(string name, Point location):Ninja(name, location){
}

TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location){
}

YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location){
}