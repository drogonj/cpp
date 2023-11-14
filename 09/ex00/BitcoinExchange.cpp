
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src) : _input(src._input), _dataBase(src._dataBase) { }

BitcoinExchange::~BitcoinExchange(void) { }



long int BitcoinExchange::toDate(std::string year, std::string month, std::string day) {
    std::string all = year + month + day;
    if (all.length() > 8)
        throw formatError();
    for (int i = 0; all[i]; i++) {
        if (all[i] < '0' || all[i] > '9')
            throw formatError();
    }
    int dayPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dyear = atoi(year.c_str());
    int dmonth = atoi(month.c_str());
    int dday = atoi(day.c_str());
    (dyear % 4 == 0 && (dyear % 100 != 0 || dyear % 400 == 0)) ? dayPerMonth[1] += 1 : 0;
    if (dmonth < 1 || dmonth > 12)
        throw invalidDate();
    if (dday < 1 || dday > dayPerMonth[dmonth - 1])
        throw  invalidDate();
    long int res = ((dyear * 10000) + (dmonth) * 100) + dday);
    if (res < 20090201)
        throw invalidDate();
    return (((dyear * 10000) + (dmonth) * 100) + dday);
}

void BitcoinExchange::loadDataBase(void) {
    int             date;
    std::string     strvalue;
    float           value;
    std::ifstream   fd("./data.csv");
    if (!fd.is_open()) {
        throw failedToLoadDatabase();
    } else {
        std::string line;
        std::getline(fd, line);
        if (line != "date,exchange_rate")
            throw formatError();
        while (std::getline(fd, line)) {
            try {
                date = toDate(line.substr(0, 4), line.substr(5, 2), line.substr(8, 2));
                strvalue = line.substr(10);
                if (strvalue[0] != ',')
                    throw formatError();
                strvalue.erase(0, 1);
                value = strtod(strvalue.c_str(), 0);
            } catch (std::exception &e) {
                throw;
            }
            this->_dataBase[date] = value;
        }
    }
    fd.close();
}

void BitcoinExchange::exec(char * filename) {
    std::ifstream   file(filename);
    std::string     line;
    int             date;
    std::string     strvalue;
    int             value;

    if (!file.is_open()) {
        throw failedToLoadInputFile();
    }
    std::getline(file, line);
    if (line != "date | value")
        throw formatError();
    while (std::getline(file, line)) {
        try {
            date = toDate(line.substr(0, 4), line.substr(5, 2), line.substr(8, 2));
            if (line.substr(10, 3) != " | ")
                throw formatError();
            strvalue = line.substr(13);
            if (strvalue.empty())
                throw formatError();
            value = strtod(strvalue.c_str(), 0);
            if (value < 0)
                throw invalidValue();
            for (std::map<long int, float>::iterator it = this->_dataBase.begin(); it != this->_dataBase.end(); it++) {
                if (date == it->first) {
                    std::cout << GREEN << line.substr(0, 10) << " ➔ " << value << " = " << value * it->second << RESET << std::endl;
                    break;
                } else if (date < it->first) {
                    std::cout << GREEN << "moin" << RESET << std::endl;
                    break;
                }
            }
        } catch (std::exception &e) {
            std::cout << YELLOW << "input: " << e.what() << RESET << std::endl;
        }
    }
    file.close();
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & src) {
    if (&src != this) {
        this->_input = src._input;
        this->_dataBase = src._dataBase;
    }
    return (*this);
}