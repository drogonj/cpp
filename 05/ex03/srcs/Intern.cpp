
#include "../includes/Intern.hpp"

const char *Intern::forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        ""
};

const Intern::FormCreator Intern::creators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyCreationForm,
        &Intern::createPresidentialPardonForm
};

Intern::Intern(void)
{
    std::cout << GREEN << "Intern constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern & src)
{
    (void)src;
    std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
}

Intern::~Intern(void)
{
    std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

AForm * Intern::createShrubberyCreationForm(const std::string & target)
{
    return (new(ShrubberyCreationForm)(target));
}

AForm * Intern::createRobotomyCreationForm(const std::string & target)
{
    return (new(RobotomyRequestForm)(target));
}

AForm * Intern::createPresidentialPardonForm(const std::string & target)
{
    return (new(PresidentialPardonForm)(target));
}

AForm * Intern::makeForm(const std::string & formName, const std::string & target) const
{
    AForm       *f;
    const int   tabLength = (sizeof(this->forms) / sizeof(this->forms[0])) - 1;
    int         i = 0;

    for ( ; formName != this->forms[i] && i < tabLength; i++) {};
    if (tabLength == i)
        throw formDoesNotExist();
    f = Intern::creators[i](target);
    if (!f)
        throw allocationError();
    std::cout << BLUE << "Intern creates \"" << formName << "\"" << RESET << std::endl;
    return (f);
}

Intern & Intern::operator=(const Intern & src)
{
    (void)src;
    return (*this);
}
