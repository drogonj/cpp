
#include "RPN.hpp"

RPN::RPN(void) { }
RPN::RPN(const RPN & src) : s(src.s) { }
RPN::~RPN(void) { }

char * RPN::fillStack(char *arg) {
    size_t i = 0;
    for ( ; arg[i] == ' ' || (arg[i] >= '0' && arg[i] <= '9'); i++) {
        if (arg[i] == ' ')
            continue;
        this->s.push(static_cast<double>(arg[i] - '0'));
    }
    return (&arg[i]);
}

char * RPN::doOp(char *arg) {
    size_t i = 0;
    for ( ; arg[i] == ' ' || arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/'; i++) {
        if (arg[i] == ' ')
            continue;
        if (this->s.size() < 2)
            throw badCalc();
        float second = this->s.top();
        this->s.pop();
        float first = this->s.top();
        this->s.pop();
        if (arg[i] == '+')
            this->s.push(first + second);
        else if (arg[i] == '-')
            this->s.push(first - second);
        else if (arg[i] == '*')
            this->s.push(first * second);
        else if (arg[i] == '/') {
            if (second == 0.0)
                throw divisionByZero();
            this->s.push(first / second);
        }
        else
            throw badCalc();
    }
    return (&arg[i]);
}

double RPN::calculate(char *arg) {
    if (strlen(arg) < 5)
        throw badCalc();
    arg = fillStack(arg);
    while (this->s.size() > 1) {
        if (strlen(arg) < 1)
            throw badCalc();
        try {
            arg = doOp(arg);
        } catch (std::exception &e) {
            throw;
        }
        arg = fillStack(arg);
    }
    if (this->s.size() != 1 || strlen(arg) > 0)
        throw badCalc();
    float res = this->s.top();
    return (res);
}

RPN & RPN::operator=(const RPN & src) {
    if (this != &src) {
        this->s = src.s;
    }
    return (*this);
}