//
// Created by rani.aboraya on 12/27/17.
//

#ifndef EX1_ARENSTORFPOINT_H
#define EX1_ARENSTORFPOINT_H

#include <iostream>


/**
 * A class that represents a point in the two dimensional space
 */
class ArenstorfPoint
{

public:
    /**
     * A constructor that inits the class with the x, y coordinates, vx, and vy.
     * @param x the x cordinate of the point
     * @param y the y cordinate of the point
     * @param vx the velocity on x axis
     * @param vy the velocity on y axis
     */
    ArenstorfPoint(long double x , long double y, long double vx, long double vy);

    /**
     * Writes to the os a string representation of the point in the format x, y.
     * @param os the output stream
     * @param a the point to print
     * @return a stream that prints an ArenstrorfPoint object.
     */
    friend std::ostream& operator <<(std::ostream& os, const ArenstorfPoint& a);

/**
 * A getter for the x cordinate of the point
 * @return x cord.
 */
    long double getX() const;

/**
 * A getter for the y cordinate of the point.
 * @return y cord.
 */
    long double getY() const;


/**
 * A getter for the velocity on x axis
 * @return velocity on x axis
 */
    long double getVX()const;


/**
 * A getter for the velocity on y axis
 * @return velocity on y axis
 */
    long double getVY() const;



private:
    long double x;
    long double y;
    long double vx;
    long double vy;
};


#endif //EX1_ARENSTORFPOINT_H
