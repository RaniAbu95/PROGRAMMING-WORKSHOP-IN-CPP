#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <vector>
#include "Complex.h"
#include "MatrixException.cpp"

#define DEFAULT_ROWS 1
#define DEFAULT_COLOMNS 1
#define ZERO_ELEMENT 0
#define MINIMAL_COLS_NUM 1
#define MINIMAL_ROWS_NUM 1
#define TAB "\t"
#define NEW_LINE "\n"

#define CREATION_ERR "ERR: ILLEGAL MATRIX CREATION"
#define COPY_CONSTRUCTOR_ERR "ERR: CANNOT COPY NULL POINTER"
#define VECTOR_SIZE_ERR "ERR: VECTOR SIZE INCOMPATIBLE"
#define ADDITION_ERR "Cannot addition matrices of different sizes."
#define SUBTRACTION_ERR "Cannot subtraction matrices of different sizes."
#define MULTIPLICATION_ERR "ERR: Cannot multiplication matrices of different sizes."
#define NO_SUCH_ELEMENT_ERR "ERR: NO SUCH PLACE"

using namespace std;


template <class T>

/**
* A class that repreents a matrix with T values.
*/
class Matrix
{

private:
    std::vector<T> _matrixVec; 
    unsigned int _rows;
    unsigned int _colomns;

public:

    /**
     * A getter for the number of rows in the matrix.
     * @return the number of rows. 
     */
    unsigned int rows() const
    {
        return _rows;
    }

    /**
     * A getter for the number of colomns in the matrix.
     * @return the number of colomns. 
     */
    unsigned int cols() const
    {
        return _colomns;
    }

    /**
     * A setter for the number of rows in the matrix.
     * @param x the new number of rows. 
     */
    void setRows(unsigned int x)
    {
        _rows = x;
    }
    

    /**
     * A setter for the number of colomns in the matrix.
     * @param x the new number of colomns. 
     */
    void setCols(unsigned int y)
    {
        _colomns = y;
    }
    



    /**
    * Default constructor.
    */
    Matrix()
    {
        _rows = DEFAULT_ROWS;
        _colomns = DEFAULT_COLOMNS;
        _matrixVec.push_back(T(ZERO_ELEMENT));
    }

    /**
    * Destructor's class.
    */
    ~Matrix(){}
    
    /**
    * A constructor that initialize a matrix with the given number of row and 
    * colomns.
    */
    Matrix(unsigned int rows, unsigned int cols)
    {
        if(rows < MINIMAL_COLS_NUM || cols < MINIMAL_ROWS_NUM)
        {
            throw MatrixException(CREATION_ERR);
        }
        _rows = rows;
        _colomns = cols;
        _matrixVec.resize(rows * cols);
    }

    /**
    * A copy constructor.
    * @param m pointer to a matrix.
    */
    Matrix(Matrix* m)
    {
        if(m == nullptr)
        {
            throw MatrixException(COPY_CONSTRUCTOR_ERR);
        }
        _rows = m->rows();
        _colomns = m->cols();
        _matrixVec = m->getCells();
    }


    /**
    * Move constructor that gets matrix m and copy its values to this matrix.
    * @param m refference to a matrix
    */
    Matrix(Matrix && m)
    {
        _colomns = m.cols(); 
        _rows = m.rows();
        for(unsigned int i = 0; i < _colomns * _rows; i++)
        {
            _matrixVec.push_back(m._matrixVec[i]);
            m._matrixVec[i] = T(ZERO_ELEMENT);
        }
        m.setRows(DEFAULT_ROWS);
        m.setCols(DEFAULT_COLOMNS);        
    }

    /**
    * A constructor that initialize the matrix with the given rows and colomns
    * and a vector.
    * @param rows num of rows to set for the matrix. 
    * @param cols num of cols to set for the matrix. 
    * @param cells a vector that contains all the values of the matrix.
    */
    Matrix(unsigned int rows, unsigned int cols, const vector<T>& cells)
    {
        if(rows < MINIMAL_COLS_NUM || cols < MINIMAL_ROWS_NUM)
        {
            throw MatrixException(CREATION_ERR);
        }
        else if (cells.size() != cols * rows)
        {
            throw MatrixException(VECTOR_SIZE_ERR);
        }
        this-> setRows(rows);
        this-> setCols(cols);
        _matrixVec = cells;
    }

    /**
     * A getter for the matrix cells.
     * @return A vector that contains the cells of the matrix.
     */
    std::vector<T> getCells()const
    {
        return _matrixVec;
    }
    

    /**
    * The Assignment operator.
    * @param other is the matrix that we want to copy.
    * @return A refference to a matrix after that it has been copyed.
    */   
    Matrix& operator=(const Matrix<T>& other) 
    {   
        _rows = other.rows();
        _colomns = other.cols();
        _matrixVec = other.getCells();
        return *this;
    }
    
    /**
    * An operator to check if two matrix are equal.
    * @param other is the other matrix to check.
    * @return true if the two objects are equal, false otherwise.
    */ 
     bool operator==(const Matrix& other) const
    {
        if(_rows != other.rows() || _colomns != other.cols())
        {
            return false;
        }
        for(unsigned int i = 0; i < _rows * _colomns; i++)
        {
            if(other.getCells()[i] != _matrixVec[i])
            {
                return false;
            }
        }
        return true;
    }

    /**
    * An operator to check if two matrix aren't equal.
    * @param other is the other matrix to check.
    * @return true if the two objects aren't equal, false otherwise.
    */ 
    bool operator!=(const Matrix& other) const
    {
        if(this->operator==(other))
        {
            return false;
        }
        return true;
    }


    /**
    * A function that prints the matrix values.
    * @return an ostream object that is used in order to print.
    */ 
    friend ostream& operator<<(ostream& os, const Matrix<T>& m) 
    {
        for(unsigned int i = 0; i < m.rows() * m.cols(); i++)
        {
            os << m.getCells()[i] << TAB;
            if((i + 1) % m.cols() == 0)
            {
                os << NEW_LINE;
            }
        }
        return os;
    }

    /**
    * An operator for addition operation between two matrixes.
    * @param other the other matrix to add.
    * @return a refference for a matrix that represent the result of the 
    * two matrixes addition.
    */ 
     Matrix operator+(const Matrix& other) const
    {
        if(_rows != other.rows() || _colomns != other.cols())
        {
            throw MatrixException(ADDITION_ERR);
        }
        Matrix<T> result(this->rows(), this->cols());        
        for(unsigned int i = 0; i < result.rows() * result.cols(); i++)
        {
            result._matrixVec[i] = this->getCells()[i] + other.getCells()[i] ;        
        }
        return result;
    }

    /**
    * An operator for subtraction operation between two matrixes.
    * @param other the other matrix to subtract.
    * @return a refference for a matrix that represent the result of the 
    * two matrixes subtraction.
    */ 
     Matrix operator-(const Matrix& other) 
    {
        if(_rows != other.rows() || _colomns != other.cols())
        {
            throw MatrixException(SUBTRACTION_ERR);
        }
        Matrix<T> result(this->rows(), this->cols());
        for(unsigned int i = 0; i < result.rows() * result.cols(); i++)
        {
            result._matrixVec[i] =  this->getCells()[i] - other.getCells()[i];        
        }
        return result;
    }


    

    /**
    * An operator for subtraction operation between two matrixes.
    * @param other the other matrix to subtract.
    * @return a non-const refference for a matrix that represent the result of the 
    * two matrixes subtraction.
    */ 
    T& operator() (unsigned int row, unsigned int col) 
    {
        if(_rows < row || _colomns < col || row < 0 || col < 0)
        {
            throw MatrixException(NO_SUCH_ELEMENT_ERR);
        }
        return _matrixVec[row * this->_colomns + col];
    }
    
    /**
    * An operator for subtraction operation between two matrixes.
    * @param other the other matrix to subtract.
    * @return a cosnt refference for a matrix that represent the result of the 
    * two matrixes subtraction.
    */ 
    T operator() (unsigned int row, unsigned int col) const
    {
        if(_rows < row || _colomns < col || row < 0 || col < 0)
        {
            throw MatrixException(NO_SUCH_ELEMENT_ERR);
        }
        return _matrixVec[row * this->_colomns + col];
    }
    


   /**
    * An operator for multiplication operation between two matrixes.
    * @param other the other matrix to subtract.
    * @return a refference for a matrix that represent the result of the 
    * two matrixes multiplication.
    */ 
     Matrix operator*(Matrix& other) 
    {       
        if(other._rows != this -> _colomns)
        {
            throw MatrixException(MULTIPLICATION_ERR);
        }
        Matrix<T>result(this -> rows(), other.cols());
        for(unsigned int i = 0; i < this -> _rows; i++)
        {
            for(unsigned int j = 0; j < other.cols(); j++)
            {
                for(unsigned int k = 0; k < this -> _colomns; k++)
                {
                    result(i, j) = result(i, j) + (*this)(i, k) * other(k, j);
                }
            }
        }

        return result;

    
    }

    /**
    * A function that determinds if a matrix is square.
    * @return true if the matrix is square, else false.
    */
    bool isSquareMatrix()
    {
        return (this->rows() == this->cols());
    }

    /**
    * A that calculate the transmited matrix
    * @return A new transmited matrix.
    */
    Matrix<T> trans() const
    {
        Matrix<T> transmetedMatrix(this -> cols(), this -> rows());
        for (unsigned int i = 0; i < this -> cols(); i++)
        {
            for (unsigned int j = 0; j < this -> rows(); j++)
            {
                transmetedMatrix(i, j) = (*this)(j, i);
            }
        }
        return transmetedMatrix;
    }   


    typedef typename vector<T>::iterator const_iterator;
    /**
     * begin iterator
     */
    const const_iterator begin()
    {
        return this -> _matrixVec.begin();
    }

    /**
     * end iterator
     */
    const const_iterator end()
    {
        return this -> _matrixVec.end();
    }


};

/**
* A function that calculates the tran of a complex matrix.
* @return the transmited matrix.
*/ 
template<>
Matrix <Complex> Matrix <Complex> ::trans() const
{
    Matrix <Complex> result(cols(), rows());
    for (unsigned int i = 0; i < rows(); i++)
    {
        for (unsigned int j = 0; j < cols(); j++)
        {
            result(j, i) = (*this)(i, j).conj();
        }
    }
    return result;
}




#endif









