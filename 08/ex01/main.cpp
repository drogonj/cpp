
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

int main(void)
{
    Span s(5);
    s.addNumber(-10);
    s.addNumber(0);
    s.addNumber(8);

    std::cout << GREEN << "s.longestSpan(): " << s.longestSpan() << RESET << std::endl;
    std::cout << GREEN << "s.shortestSpan(): " << s.shortestSpan() << RESET << std::endl;

//     Test with 10 000 numbers randomly generated :

//    std::srand(std::time(0));
//    Span sp = Span(10000);
//    for (int i = 0; i < 10000; i++)
//        sp.addNumber(std::rand());
//    sp.displayV();
//    std::cout << GREEN << sp.shortestSpan() << RESET << std::endl;
//    std::cout << GREEN << sp.longestSpan() << RESET << std::endl;
}