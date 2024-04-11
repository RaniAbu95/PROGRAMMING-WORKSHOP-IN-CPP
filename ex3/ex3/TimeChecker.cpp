//
// Created by rani.aboraya on 2/4/18.
//

#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#include <stack>
#include <ctime>
#include <chrono>
#include "Matrix.hpp"
#include <vector>

using Eigen::MatrixXd;
using namespace std;

/**
 * main function that make time checks for matrix operation(Eigen and myLib)
 * @param argc number of arguments
 * @param argv the array of argument
 * @return return 0 on success, -1 if error occurs.
 */
int main(int argc, char *argv[])
{
    int n;
    if(argc == 1)
    {
        n = 500;
    }
    else if(argc == 2)
    {
        n = atoi(argv[1]);
    }
    else
    {
        cout<<"Error: The program should receive one argument(number between 0 and 500) "<<endl;
        return -1;
    }


    cout<<"size "<< n << endl;

    //initialize the stack
    std::stack<std::chrono::time_point<std::chrono::system_clock>> tictoc_stack;

    //Initialize two eigen matrix - one for mult and the second for add.
    MatrixXd eigen_Mult(n,n);
    MatrixXd eigen_Add(n,n);

    //Initialize two matrix random matrix by eigen
    MatrixXd eigen_m1 = MatrixXd::Random(n,n);
    MatrixXd eigen_m2 = MatrixXd::Random(n,n);


    tictoc_stack.push(std::chrono::system_clock::now());
    eigen_Mult = eigen_m1 * eigen_m2;
    std::chrono::duration<double> elapsed_seconds1 = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "eigen mult: " << elapsed_seconds1.count() << "sec\n";
    tictoc_stack.pop();


    tictoc_stack.push(std::chrono::system_clock::now());
    eigen_Add = eigen_m1 + eigen_m2;
    std::chrono::duration<double> elapsed_seconds2 = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "eigen add: " << elapsed_seconds2.count() << "sec\n";
    tictoc_stack.pop();


    Matrix<int> mult_res(n,n);
    Matrix<int> add_res(n,n);
    vector<int> vec(n*n,1);
    Matrix<int> my_Matrix(n, n, vec);

    tictoc_stack.push(std::chrono::system_clock::now());
    mult_res = my_Matrix * my_Matrix;
    std::chrono::duration<double> elapsed_seconds3 = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "matlib mult: " << elapsed_seconds1.count() << "sec\n";
    tictoc_stack.pop();

    tictoc_stack.push(std::chrono::system_clock::now());
    add_res = my_Matrix + my_Matrix;
    std::chrono::duration<double> elapsed_seconds4 = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << "matlib add: " << elapsed_seconds1.count() << "sec\n";
    tictoc_stack.pop();

    return 0;
}





