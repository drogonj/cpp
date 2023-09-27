
#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string & target);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		~PresidentialPardonForm(void);

		//Functions
		const std::string & getTarget(void) const;
		void execute(const Bureaucrat & src) const;

		//Operators overloads
		PresidentialPardonForm & operator=(const PresidentialPardonForm & src);
};