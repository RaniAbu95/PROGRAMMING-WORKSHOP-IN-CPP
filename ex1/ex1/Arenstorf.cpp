//
// Created by rani.aboraya on 12/27/17.
//

#include "Arenstorf.h"

#define PARAM_ERR "Error! input parameters not in range"

long double mass_ratio = 0.012299; //TODO: DEFINE MASS_RATIO
long double b = 1 - mass_ratio;




/**
* A method which will compute the trajectory points and write it to the output stream
* @param init The initial point
* @param n number of trajectory points
* @param m
* @param dt
* @param out
* @return Returns 0 on success, -1 on an error.
*/
int Arenstorf::computeArenstorf(const ArenstorfPoint& init,
                                unsigned int n,
                                unsigned int m,
                                long double dt,
                                std::ostream& out)
{



    if(m <= 0 || m > n)
    {
        std::cerr << PARAM_ERR << std::endl;
    }


    ArenstorfPoint temp = init;

    long double d1;
    long double d2;
    long double ax;
    long double ay;
    long double newX;
    long double newY;
    long double newVX;
    long double newVY;

    int counter = 0;

    for (unsigned int i = 0; i < n; i++)
    {


        d1 = pow(pow(temp.getX() + mass_ratio, 2) + pow(temp.getY(), 2), 1.5);
        d2 = pow(pow(temp.getX() - b, 2) + pow(temp.getY(), 2), 1.5);

        ax = temp.getX() + 2 * temp.getVY() - b * (temp.getX() + mass_ratio) / d1 - mass_ratio * (temp.getX() - b) / d2;
        ay = temp.getY() - 2 * temp.getVX() - b * temp.getY() / d1 - mass_ratio * temp.getY() / d2;

        newX = temp.getX() + temp.getVX() * dt;
        newY = temp.getY() + temp.getVY() * dt;
        newVX = temp.getVX() + ax * dt;
        newVY = temp.getVY() + ay * dt;

        temp = ArenstorfPoint(newX, newY, newVX, newVY);


        //TODO TRY ALL THE POSSIBLES OF M
        if (i % (n / m) == 0)
        {
            counter++;
            if (counter % m != 0)
            {
                out << temp << ", ";
            }
            else
            {
                out << temp;
            }
        }
    }

    return 0;
}


