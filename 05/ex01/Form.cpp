
#include "Form.hpp"

Form::Form( void ) : _name("none"), _requiredGradeToExec(150), _requiredGradeToSign(150), _isSigned(false)
{
    std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form( const std::string & name, int execGrade, int signGrade ) : _name(name)
{
    setGradeToExec(execGrade);
    setGradeToSign(signGrade);
}

Form::~Form( void )
{
    std::cout << RED << "Form destructor called" << RESET << std::endl;
}

const std::string&  Form::getName( void )
{
    return (this->_name);
}

int Form::getRequiredGradeToExec( void )
{
    return(this->_requiredGradeToExec);
}

int Form::getRequiredGradeToSign( void )
{
    return (this->_requiredGradeToSign);
}

bool    Form::getIsSigned( void )
{
    return (this->_isSigned);
}

void    Form::beSigned(const Bureaucrat &src)
{
    if (src._grade > this->_requiredGradeToSign)
        throw GradeTooLowException();
    this->_isSigned = true;
}

void    Form::setGradeToSign(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_requiredGradeToSign = grade;
}

void    Form::setGradeToExec(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_requiredGradeToExec = grade;
}