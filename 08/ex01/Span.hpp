
#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
    unsigned int        _N;
    std::vector<int>    _V;

public:
    //Constructors / Destructors
    Span(void);
    Span(const unsigned int n);
    Span(const Span & src);
    ~Span(void);

    //Functions
    int getN(void) const;
    const std::vector<int> & getV(void);
    void displayV(void);
    void addNumber(const int n);
    void addNumbers(const int *args, int length);
    template <typename T>
    void addNumbers(T begin, T end) {
        T it = begin;
        for ( ; it != end; it++) {
            addNumber(*it);
        }
    }
    int shortestSpan(void);
    int longestSpan(void);

    // Exceptions
    class   maximumReached : public std::exception {
        const char * what(void) const throw() {
            return ("Maximum number of elements reached");
        }
    };
    class   tooFewElements : public std::exception {
        const char * what(void) const throw() {
            return ("Too few elements in the span container");
        }
    };

    //Operators overloads
    Span & operator=(const Span & src);
};