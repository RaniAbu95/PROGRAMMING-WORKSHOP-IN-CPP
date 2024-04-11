#include <iostream>
#include <fstream>

#include "Arenstorf.h"

#include<vector>
#include <sstream>

long double x;
long double y;
long double vx;
long double vy;
long double t;
long double dt;
unsigned int n;
unsigned int m;




#define ARG_ERR "Usage: ArenstorfOrbit <input filename (optional)> <output filename>"
#define PARAM_ERR "Error! input parameters not in range"
#define FILE_ERR "File is empty"

/**
 * the main function which runs the whole program
 * @param argc number of arguments that the program receives
 * @param argv array that contains all the inputs of the program
 * @return 0 on success, -1 on fail.
 */
int main (int argc, char *argv[])
{

    std::string outputFileName;
    std::ofstream output;

    if (argc > 3)
    {
        std::cerr << ARG_ERR << std::endl;
        return -1;
    }
    if (argc == 2)
    {
        outputFileName = argv[1];
        output.open(outputFileName);

        std::cout << "Enter initial pos x:" << std::endl;
        std::cin >> x;

        std::cout << "Enter initial pos y:" << std::endl;
        std::cin >> y;

        std::cout << "Enter initial vel x:" << std::endl;
        std::cin >> vx;

        std::cout << "Enter initial vel y:" << std::endl;
        std::cin >> vy;

        std::cout << "Enter total time T:" << std::endl;
        std::cin >> t;

        std::cout << "Enter num of steps:" << std::endl;
        std::cin >> n;

        std::cout << "Enter num of steps to save:" << std::endl;
        std::cin >> m;

    }
    else if (argc == 3)
    {
        std::string inputFileName = argv[1];
        outputFileName = argv[2];
        output.open(outputFileName);

        std::string line1;
        std::string line2;


        std::ifstream inFile(inputFileName);
        if (inFile.is_open())
        {

            // get the first line
            if(std::getline(inFile, line1))// checks if the file is empty
            {
                std::getline(inFile, line2); // get the second line from the file.
            }
            else
            {
                //the file is empty
                std::cerr << FILE_ERR << std::endl;
                return -1;
            }


            //spliting the first line by comma - (c_str() is used to cast a string to a c_string)
            std::stringstream first_line(line1);
            std::string token1;

            getline(first_line, token1, ',');
            x = atof(token1.c_str());

            getline(first_line, token1, ',');
            y = atof(token1.c_str());

            getline(first_line, token1, ',');
            vx = atof(token1.c_str());


            getline(first_line, token1, ',');
            vy = atof(token1.c_str());


            //Spliting the second line by comma
            std::stringstream second_line(line2);
            std::string token2;

            getline(second_line , token2, ',');
            t = atof(token2.c_str());

            getline(second_line, token2, ',');
            n = atof(token2.c_str());

            getline(second_line, token2, ',');
            m = atof(token2.c_str());

            inFile.close();

        }
        else
        {
            std::cerr << "Unable to open file" << std::endl;
        }
    }
    else
    {
        std::cerr << ARG_ERR << std::endl;
        return -1 ;
    }

    ArenstorfPoint init = ArenstorfPoint(x, y, vx, vy);

    if(t < 0)
    {
        std::cerr << PARAM_ERR << std::endl;
        return -1;
    }


    dt = t / n;

    Arenstorf arenstorfObj;

    arenstorfObj.computeArenstorf(init, n, m, dt, output);

    output.close();


    return 0;
}