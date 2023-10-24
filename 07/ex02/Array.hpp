
#pragma once

#include <iostream>
#include <exception>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

template<typename A>
class   Array
{
private:
    //Vars
    unsigned int    _len;
    A               *_array;

public:
    // Constructors, destructors
    Array(void) : _len(0), _array(0) {}
    Array(unsigned int n) : _len(n) { this->_array = new A[n]; }
    Array(const Array & src) {
        if (this->_len > 0)
            delete [] this->_array;
        this->_len = src._len;
        this->_array = new A[src._len];
        for (unsigned int i = 0; i < src._len; i++)
            this->_array = src._array;
    }
    ~Array(void) { delete [] this->_array; }

    //Functions
    unsigned int size(void) const { return(this->_len); }

    //Exceptions
    class indexOutOfBounds : public std::exception
    {
        const char *what(void) const throw()
        {
            return ("Index out of bounds");
        }
    };

    //Operators overloads
    Array & operator=(const Array & src) {
        this->_len = src._len;
        this->_array = new A[src._len];
        for (unsigned int i = 0; i < src._len; i++)
            this->_array = src._array;
        return (*this);
    }
    A & operator[](unsigned int index) {
        if (index > this->_len - 1)
            throw indexOutOfBounds();
        return (this->_array[index]);
    }
};
