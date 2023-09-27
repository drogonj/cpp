
#pragma once

#include "AForm.hpp"
#include <thread>
#include <chrono>
#include <random>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string & target);
		RobotomyRequestForm(const RobotomyRequestForm & src);
		~RobotomyRequestForm(void);

		//Functions
		const std::string & getTarget(void) const;
		void execute(const Bureaucrat & src) const;

		//Operators overloads
		RobotomyRequestForm & operator=(const RobotomyRequestForm & src);
};