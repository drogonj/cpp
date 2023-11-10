
#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
    //Creating aliases that point to iterators of the underlying container (std::deque)
    //template<
    //        class T,
    //        class Container = std::deque<T>
    //> class stack;
    // See https://en.cppreference.com/w/cpp/container/stack
    // and https://en.cppreference.com/w/cpp/container/deque
    typedef typename std::stack<T>::container_type::iterator iterator;
    // No need to do it with constant_iterator or reverse_iterator because cbegin()/cend() and rbegin()/rend() dont exist in c++98

    iterator begin(void) {
        return this->c.begin();
    }

    iterator end(void) {
        return this->c.end();
    }
};
