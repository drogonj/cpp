
#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_requiredGradeToSign;
		const int			_requiredGradeToExec;
		// Exceptions
		class	GradeTooLowException : public std::exception
		{
			const char *what(void) const throw()
			{
				return ("Grade too low");
			}
		};
		class	GradeTooHighException : public std::exception
		{
			const char *what(void) const throw()
			{
				return ("Grade too high");
			}
		};

	public:
		//Constructors / Destructors
		Form(void);
		Form(const std::string & name, int requiredGradeToSign, int requiredGradeToExec);
		Form(const Form & src);
		~Form(void);
		//Functions
		const std::string & getName(void);
		void beSigned(const Bureaucrat & src);
		//Operators
		Form & operator=(Form const & src);
		friend std::ostream & operator<<(std::ostream & out, const Form & src);
};
