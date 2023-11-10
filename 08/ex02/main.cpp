
#include "MutantStack.hpp"
#include <iostream>
#include <list>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

int main(void) {
    MutantStack<int>            s;

    s.push(21);
    s.push(42);
    s.push(84);
    s.push(-128);
    s.push(42);
    s.push(47);

    MutantStack<int>::iterator  it = s.begin();
    MutantStack<int>::iterator  start = s.begin();
    MutantStack<int>::iterator  end = s.end();

    std::cout << BLUE << "Displaying MutantStack:"  << std::endl << GREEN << '[';
    for ( ; it != end - 1; it++) {
        std::cout << *it << ", ";
    }
    std::cout << *it << ']' << RESET << std::endl;

    std::cout << BLUE << "Displaying MutantStack in the reverse way:"  << std::endl << GREEN << '[';
    for ( ; it != start; it--) {
        std::cout << *it << ", ";
    }
    std::cout << *it << ']' << RESET << std::endl;
    return (0);
}

/* main from the subject */
//int main()
//{
//    MutantStack<int> mstack;
//    mstack.push(5);
//    mstack.push(17);
//    std::cout << mstack.top() << std::endl;
//    mstack.pop();
//    std::cout << mstack.size() << std::endl;
//    mstack.push(3);
//    mstack.push(5);
//    mstack.push(737);
//    mstack.push(0);
//    MutantStack<int>::iterator it = mstack.begin();
//    MutantStack<int>::iterator ite = mstack.end();
//    ++it;
//    --it;
//    while (it != ite)
//    {
//        std::cout << *it << std::endl;
//        ++it;
//    }
//    std::stack<int> s(mstack);
//    return 0;
//}

/* same tests with std::list */
//int main()
//{
//    std::list<int> mstack;
//    mstack.push_back(5);
//    mstack.push_back(17);
//    std::cout << mstack.back() << std::endl;
//    mstack.pop_back();
//    std::cout << mstack.size() << std::endl;
//    mstack.push_back(3);
//    mstack.push_back(5);
//    mstack.push_back(737);
//    mstack.push_back(0);
//    std::list<int>::iterator it = mstack.begin();
//    std::list<int>::iterator ite = mstack.end();
//    ++it;
//    --it;
//    while (it != ite)
//    {
//        std::cout << *it << std::endl;
//        ++it;
//    }
//    return 0;
//}
