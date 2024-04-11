//
// Created by rani.aboraya on 12/27/17.
//

#include "ArenstorfPoint.h"


#include <iomanip> // setprecision
#include <sstream> // stringstream



/**
 * A constructor that inits the class with the x, y coordinates, vx, and vy.
 * @param x the x cordinate of the point
 * @param y the y cordinate of the point
 * @param vx the velocity on x axis
 * @param vy the velocity on y axis
 */
ArenstorfPoint::ArenstorfPoint(long double x , long double y, long double vx, long double vy)
{
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
}


/**
 * A getter for the x cordinate of the point
 * @return x cord.
 */
long double ArenstorfPoint::getX() const
{
    return this->x;
}

/**
 * A getter for the y cordinate of the point.
 * @return y cord.
 */
long double ArenstorfPoint::getY() const
{
    return this->y;
}

/**
 * A getter for the velocity on x axis
 * @return velocity on x axis
 */
long double ArenstorfPoint::getVX() const
{
    return this->vx;
}

/**
 * A getter for the velocity on y axis
 * @return velocity on y axis
 */
long double ArenstorfPoint::getVY() const
{
    return this->vy;
}


/**
 * Writes to the os a string representation of the point in the format x, y.
 * @param os the output stream
 * @param a the point to print
 * @return a stream that prints an ArenstrorfPoint object.
 */
std::ostream& operator <<(std::ostream& os, const ArenstorfPoint& a)
{

    std::stringstream precisionValue;
    precisionValue << std::scientific;
    precisionValue << std::setprecision(3) << a.getX()  << ", " << a.getY();
    os << precisionValue.str();

    return os;
}


