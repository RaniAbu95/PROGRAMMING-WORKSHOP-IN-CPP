//
// Created by rani.aboraya on 12/27/17.
//

#ifndef EX1_ARENSTORF_H
#define EX1_ARENSTORF_H

#include <iostream>
#include "ArenstorfPoint.h"
#include <stdio.h>
#include <math.h>

/**
 * A class that is responsible for computing the trajectory points.
 */
class Arenstorf
{
public:

/**
 * A default constructor for Arenstorf class
 */
    Arenstorf() = default;


    /**
     * A method which will compute the trajectory points and write it to the output stream
     * @param init The initial point
     * @param n number of trajectory points
     * @param m
     * @param dt
     * @param out
     * @return Returns 0 on success, -1 on an error.
     */
    static int computeArenstorf(const ArenstorfPoint& init,
                                unsigned int n,
                                unsigned int m,
                                long double dt,
                                std::ostream& out);




};


#endif //EX1_ARENSTORF_H
