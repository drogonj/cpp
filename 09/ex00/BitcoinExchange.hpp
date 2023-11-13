
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
    std::map<int, float> _input;
    std::map<int, float> _dataBase;

    // Functions
    int toDate(std::string year, std::string month, std::string day);

public:
    // Constructors / Destructors
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange & src);
    ~BitcoinExchange(void);

    // Functions
    void loadDataBase(void);
    void exec(void);

    // Operators overloads
    BitcoinExchange & operator=(const BitcoinExchange & src);

    // Exceptions
    class failedToLoadDatabase : public std::exception {
        const char * what(void) const throw() {
            return ("error: failed to load database");
        }
    };
    class formatErrorInDatabase : public std::exception {
        const char * what(void) const throw() {
            return ("error: wrong format in database");
        }
    };
    class invalidDateInDatabase : public std::exception {
        const char * what(void) const throw() {
            return ("error: invalid date in database");
        }
    };
};