#include "Point.hpp"
using namespace ariel;

Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

Point::Point(){
    this->x = 0;
    this->y = 0;
}

double Point::distance(Point other){
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

void Point::print(){
    cout << "(" << this->x << "," << this->y << ")" << endl;
}

Point Point::moveTowards(Point origin, Point destination,  double distance) {
    if (distance < 0) {
        throw invalid_argument("distance cannot be negative");
    }
    if (distance == 0) {
        return origin;
    }
    if (distance == origin.distance(destination)) {
        return destination;
    }
    if (distance > origin.distance(destination)) {
        return destination;
    }
    double x = origin.x + (distance * ((destination.x - origin.x) / origin.distance(destination)));
    double y = origin.y + (distance * ((destination.y - origin.y) / origin.distance(destination)));
    return Point(x, y);
}


double Point::getX(){
    return this->x;
}

double Point::getY(){
    return this->y;
}
