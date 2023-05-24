#ifndef Point_HPP
#define Point_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(double x, double y);
        Point();
        double distance(Point other);
        void print();
        static Point moveTowards(Point origin, Point destination, double distance);
        double getX();
        double getY();
    };
}

#endif // Point_HPP