
#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstring>
#include <stack>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

class RPN {
private:
    RPN(const RPN & src);
    RPN & operator=(const RPN & src);
    std::stack<double> s;

    char * fillStack(char *arg);
    char * doOp(char *arg);

public:
    RPN(void);
    ~RPN(void);

    double calculate(char * arg);

    class badCalc : public std::exception {
        const char * what(void) const throw() {
            return ("error: bad calc");
        }
    };
    class divisionByZero : public std::exception {
        const char * what(void) const throw() {
            return ("error: division by zero");
        }
    };
};
