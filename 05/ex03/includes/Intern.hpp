
#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        typedef AForm* (*FormCreator)(const std::string & target);

        //Variables
        static const FormCreator creators[];
        const static char * forms[];

        //Functions
        static AForm * createShrubberyCreationForm(const std::string & target);
        static AForm * createRobotomyCreationForm(const std::string & target);
        static AForm * createPresidentialPardonForm(const std::string & target);

    public:
        Intern(void);
        Intern(const Intern & src);
        ~Intern(void);

        //Functions
        AForm * makeForm(const std::string & formName, const std::string & target) const;

        //Operators overloads
        Intern & operator=(const Intern & src);

        //Exceptions
        class formDoesNotExist : public std::exception
        {
            const char *what(void) const throw()
            {
                return ("Form does not exist");
            }
        };
        class allocationError : public std::exception
        {
            const char *what(void) const throw()
            {
                return ("Error during form's allocation");
            }
        };
};
