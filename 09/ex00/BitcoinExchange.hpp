
#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <exception>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

class BitcoinExchange {
private:
    std::map<long int, float> _input;
    std::map<long int, float> _dataBase;

    // Functions
    long int toDate(std::string year, std::string month, std::string day);

public:
    // Constructors / Destructors
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange & src);
    ~BitcoinExchange(void);

    // Functions
    void loadDataBase(void);
    void exec(char * filename);

    // Operators overloads
    BitcoinExchange & operator=(const BitcoinExchange & src);

    // Exceptions
    class failedToLoadDatabase : public std::exception {
        const char * what(void) const throw() {
            return ("error: failed to load database");
        }
    };
    class formatError : public std::exception {
        const char * what(void) const throw() {
            return ("error: wrong date format");
        }
    };
    class wrongHeaderInput : public std::exception {
        const char * what(void) const throw() {
            return ("error: first line must be \"date | value\"");
        }
    };
    class wrongHeaderDataBase : public std::exception {
        const char * what(void) const throw() {
            return ("error: first line must be \"date,exchange_rate\"");
        }
    };
    class invalidDate : public std::exception {
        const char * what(void) const throw() {
            return ("error: invalid date");
        }
    };
    class dateTooLow : public std::exception {
        const char * what(void) const throw() {
            return ("error: invalid date (bitcoin started in 2009)");
        }
    };
    class failedToLoadInputFile : public std::exception {
        const char * what(void) const throw() {
            return ("error: failed to load input file");
        }
    };
    class invalidValue : public std::exception {
        const char * what(void) const throw() {
            return ("error: invalid value");
        }
    };
    class tooLargeValue : public std::exception {
        const char * what(void) const throw() {
            return ("error: value too large");
        }
    };
    class negativeNumber : public std::exception {
        const char * what(void) const throw() {
            return ("error: negative number aren't allowed");
        }
    };
};