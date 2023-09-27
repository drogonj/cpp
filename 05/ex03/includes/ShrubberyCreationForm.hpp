
#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string & target);
		ShrubberyCreationForm(const ShrubberyCreationForm & src);
		~ShrubberyCreationForm(void);

		//Functions
		const std::string & getTarget(void) const;
		void execute(const Bureaucrat & src) const;

		//Operators overloads
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

		//Exceptions
		class	shrubberyPlantingError : public std::exception
		{
			const char *what(void) const throw()
			{
				return ("There was an error during the shrubbery plantation");
			}
		};
};