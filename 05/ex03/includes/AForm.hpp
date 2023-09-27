
#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_requiredGradeToSign;
		const int			_requiredGradeToExec;

	public:
		//Constructors / Destructors
		AForm(void);
		AForm(const std::string & name, int requiredGradeToSign, int requiredGradeToExec);
		AForm(const AForm & src);
		virtual ~AForm(void);

		//Functions
		const std::string & getName(void) const;
		int	getRequiredGradeToSign(void) const;
		int	getRequiredGradeToExecute(void) const;
		bool isSigned(void) const;
		void beSigned(const Bureaucrat & src);
		virtual void execute(const Bureaucrat & src) const = 0;
        virtual const std::string & getTarget(void) const = 0;

		//Operators
		AForm & operator=(AForm const & src);
		friend std::ostream & operator<<(std::ostream & out, const AForm & src);

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
		class	FormNotSigned : public std::exception
		{
			const char *what(void) const throw()
			{
				return ("Form is not signed");
			}
		};
};
