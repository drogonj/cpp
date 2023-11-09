
#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // Classes
    class iterator {
    private:
        T *address;
    public:
        // Constructors / Destructors
        iterator(void) {};
        iterator(T * _address) : address(_address) {};
        ~iterator(void) {};
    };

    // Functions
    T * begin(void) {
        MutantStack tmp = *this;
        while (tmp.size() > 1) {
            tmp.
        }

    }
};
