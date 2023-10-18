
#include "Data.hpp"

Data::Data(void) : str("Default")
{

}

Data::Data(std::string str) : str(str)
{

}

Data::Data(const Data &src) : str(src.str)
{

}

Data::~Data(void)
{

}

Data & Data::operator=(const Data &src)
{
    this->str = src.str;
    return (*this);
}
