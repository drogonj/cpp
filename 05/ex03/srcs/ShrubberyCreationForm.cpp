
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137), _target("none")
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm(src), _target(src._target)
{
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

const std::string & ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat & src) const
{
	if (src.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else if (!this->isSigned())
		throw FormNotSigned();

	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	file(filename.c_str());

	if (!file.is_open())
		throw shrubberyPlantingError();
	file << "                    .o00o\n"
			"                   o000000oo\n"
			"                  00000000000o\n"
			"                 00000000000000\n"
			"              oooooo  00000000  o88o\n"
			"           ooOOOOOOOoo  ```''  888888\n"
			"         OOOOOOOOOOOO'.qQQQQq. `8888'\n"
			"        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
			"        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
			"         OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
			"           OOOOOOOOO `QQQQQQ/ /QQ'\n"
			"             OO:F_P:O `QQQ/  /Q'\n"
			"                \\\\. \\ |  // |\n"
			"                d\\ \\\\\\|_////\n"
			"                qP| \\\\ _' `|Ob\n"
			"                   \\  / \\  \\Op\n"
			"                   |  | O| |\n"
			"           _       /\\. \\_/ /\\\n"
			"            `---__/|_\\\\   //|  __\n"
			"                  `-'  `-'`-'-'" << std::endl;
	file.close();
	std::cout << BLUE << "Shrubbery has been planted" << RESET << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	(void)src;
	return (*this);
}
