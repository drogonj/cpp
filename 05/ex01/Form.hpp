
#include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	_name;
		const int			_requiredGradeToSign;
		const int			_requiredGradeToExec;
		bool				_isSigned;
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
        //Functions
        setGradeToSign(int grade);
        setGradeToExec(int grade);

	public:
		Form( void )
		Form( std::string name, int requiredGradeToSign, int requiredGradeToExec );
		~Form( void );
        //Functions
        const std::string&  getName( void );
        int                 getRequiredGradeToSign( void );
        int                 getRequiredGradeToExec( void );
        bool                getIsSigned( void );
        void                beSigned( const Bureaucrat & src);
        //Operators overload
        Form & operator=(Form const & src);
        friend std::ostream & operator<<(std::ostream & out, const Form & src);
};