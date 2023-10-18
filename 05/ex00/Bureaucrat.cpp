
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("none"), _grade(150)
{
    std::cout << GREEN <<"Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
    std::cout << GREEN <<"Bureaucrat constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name), _grade(src._grade)
{
    std::cout << GREEN <<"Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int  Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->setGrade(this->_grade + 1);
}

void	Bureaucrat::decrementGrade()
{
	this->setGrade(this->_grade - 1);
}

void    Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src._grade;
	return (*this);
}

std::ostream & operator<<(std::ostream & out, const Bureaucrat & src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (out);
}
