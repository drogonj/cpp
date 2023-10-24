
#include "Array.hpp"

template<typename A>
Array<A>::Array(void)
{
    this->_len = 0;
    this->_array = 0;
}

template<typename A>
Array<A>::Array(unsigned int n)
{
    this->_len = n;
    this->_array = new A[n];
}

template<typename A>
Array<A>::Array(const Array<A> &src)
{
    if (this->_len > 0)
        delete [] this->_array;
    this->_len = src._len;
    this->_array = new A[src._len];
    for (unsigned int i = 0; i < src._len; i++)
        this->_array = src._array;
}

template<typename A>
unsigned int Array<A>::size(void) const
{
    return (this->_len);
}

template<typename A>
Array<A> & Array<A>::operator=(const Array & src)
{
    this->_len = src._len;
    this->_array = new A[src._len];
    for (unsigned int i = 0; i < src._len; i++)
        this->_array = src._array;
    return (*this);
}

template<typename A>
A & Array<A>::operator[](unsigned int index)
{
    if (index > this->_len - 1)
        throw indexOutOfBounds();
    return (this->_array[index]);
}
