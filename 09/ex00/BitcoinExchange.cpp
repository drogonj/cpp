
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src) : _input(src._input), _dataBase(src._dataBase) { }

BitcoinExchange::~BitcoinExchange(void) { }

int BitcoinExchange::toDate(std::string year, std::string month, std::string day) {
    std::string all = year + month + day;
    if (all.length() > 8)
        throw formatErrorInDatabase();
    for (int i = 0; all[i]; i++) {
        if (all[i] < '0' || all[i] > '9')
            throw formatErrorInDatabase();
    }
    int dayPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dyear = atoi(year.c_str());
    int dmonth = atoi(month.c_str());
    int dday = atoi(day.c_str());
    (dyear % 4 == 0 && (dyear % 100 != 0 || dyear % 400 == 0)) ? dayPerMonth[1] += 1 : 0;
    if (dyear < 2009)
        throw invalidDateInDatabase();
    if (dmonth < 1 || dmonth > 12)
        throw invalidDateInDatabase();
    if (dday < 1 || dday > dayPerMonth[dmonth - 1])
        throw  invalidDateInDatabase();
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
            throw formatErrorInDatabase();
        while (std::getline(fd, line)) {
            try {
                date = toDate(line.substr(0, 4), line.substr(5, 2), line.substr(8, 2));
                strvalue = line.substr(10);
                if (strvalue[0] != ',')
                    throw formatErrorInDatabase();
                strvalue.erase(0, 1);
                value = strtod(strvalue.c_str(), 0);
            } catch (std::exception &e) {
                throw;
            }
            this->_dataBase[date] = value;
        }
    }
    std::map<int, float>::iterator it = this->_dataBase.begin();
    std::advance(it, 198);
    std::cout << it->first << "=" << it->second << std::endl;
}

void BitcoinExchange::exec(void) {

}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & src) {
    if (&src != this) {
        this->_input = src._input;
        this->_dataBase = src._dataBase;
    }
    return (*this);
}