
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "Span.hpp"

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

/* Basic tests */
int main(void) {
    Span s(10);
    s.addNumber(-10);
    s.addNumber(0);
    s.addNumber(8);
    int args[] =  {83, 10, 96, 47, 42, -16};
    s.addNumbers(args, 6);

    std::cout << BLUE << "Span: "; s.displayV(); std::cout << RESET;
    std::cout << GREEN << "s.longestSpan(): " << s.longestSpan() << RESET << std::endl;
    std::cout << GREEN << "s.shortestSpan(): " << s.shortestSpan() << RESET << std::endl;
}

/* Test with 10 000 numbers randomly generated */
//int main(void) {
//    std::srand(std::time(0));
//    Span sp = Span(10000);
//    for (int i = 0; i < 10000; i++)
//        sp.addNumber(std::rand());
//    sp.displayV();
//    std::cout << GREEN << sp.shortestSpan() << RESET << std::endl;
//    std::cout << GREEN << sp.longestSpan() << RESET << std::endl;
//}

/* Advanced tests (class's copy, exceptions, better addNumbers) */
//int main(void) {
//    Span s(5);
//    s.addNumber(8);
//    try {
//        s.longestSpan();
//    } catch (std::exception &e) {
//        std::cout << YELLOW << e.what() << RESET << std::endl;
//    }
//    int args[] = {-16, 42, 18, 2};
//    s.addNumbers(args, 4);
//
//    Span s2 = s;
//    std::cout << BLUE << "Span: "; s.displayV(); std::cout << RESET;
//    std::cout << GREEN << "s.longestSpan(): " << s.longestSpan() << RESET << std::endl;
//    std::cout << GREEN << "s.shortestSpan(): " << s.shortestSpan() << RESET << std::endl;
//
//    try {
//        s2.addNumber(528);
//    } catch (std::exception &e) {
//        std::cout << YELLOW << e.what() << RESET << std::endl;
//    }
//
//    std::list<int>  lst;
//    lst.insert(lst.begin(), args, args + (sizeof(args) / sizeof(args[0])));
//    Span s3(4);
//    s3.addNumbers(lst.begin(), lst.end());
//    std::cout << BLUE << "Span: "; s3.displayV(); std::cout << RESET;
//}
