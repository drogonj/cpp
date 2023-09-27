
#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

class	Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;
		// Exceptions
        class	GradeTooLowException : public std::exception
        {
            const char *what(void) const throw()
            {
                return ("Grade number can't be over 150");
            }
        };
        class	GradeTooHighException : public std::exception
        {
            const char *what(void) const throw()
            {
                return ("Grade number can't be below 1");
            }
        };

	public:
        Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
        Bureaucrat( const Bureaucrat & src );
		~Bureaucrat( void );
		// Functions
		std::string	getName( void ) const;
		int			getGrade( void ) const;
        void		incrementGrade( void );
        void		decrementGrade( void );
        void		setGrade( int grade );
		void		signForm( AForm & src );
		void		executeForm( AForm const & form);
		// Operators overload
		Bureaucrat & operator=(Bureaucrat const & src);
		friend std::ostream & operator<<(std::ostream & out, const Bureaucrat & src);
};
