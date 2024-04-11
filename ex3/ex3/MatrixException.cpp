
#include<exception>
#include<string>


using namespace std;

/**
* A class that defines the matrix exceptions.
*/
class MatrixException : public exception
{

    private:
            string _errMsg;
    public:

    /**
    * My Exception class constructor.
    */
    MatrixException(string message)
    {
        _errMsg = message;
    }
    
    /**
    * My Exception class destructor.
    */
    ~MatrixException(){}

    virtual const char* what() const throw()
    {
        return _errMsg.c_str();
    }
};
