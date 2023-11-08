
#include "easyfind.hpp"

int main(void)
{
    {
        // Testing vector
        std::cout << BLUE << "Testing int vector:" << RESET << std::endl;

        std::vector<int> vec;
        vec.push_back(3);
        vec.push_back(7);
        vec.push_back(2);
        vec.push_back(8);

        std::cout << BLUE << '[';
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
            std::cout << *it;
            it == vec.end() - 1 ? std::cout << ']' << std::endl : std::cout << ", ";
        }
        std::cout << "Searching '2':" << RESET << std::endl;
        std::cout << GREEN << easyfind< std::vector<int> >(vec, 2) << RESET << std::endl;
    }

    {
        //Testing list
        std::cout << BLUE << "Testing int list:" << RESET << std::endl;

        int tab[] = {42, 43, 44, 45, 46};
        std::list<int> lst(tab, tab + (sizeof(tab) / sizeof(tab[0])));

        std::cout << BLUE << '[';
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
            std::cout << *it;
            std::distance(it, lst.end()) == 1 ? std::cout << ']' << std::endl : std::cout << ", ";
        }
        std::cout << "Searching '45':" << RESET << std::endl;

        std::cout << GREEN << easyfind< std::list<int> >(lst, 45) << RESET << std::endl;
    }

    {
        //Testing no occurences
        std::cout << BLUE << "Testing int list with no occurence:" << RESET << std::endl;

        int tab[] = {42, 43, 44, 45, 46};
        std::list<int> lst(tab, tab + (sizeof(tab) / sizeof(tab[0])));

        std::cout << BLUE << '[';
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
            std::cout << *it;
            std::distance(it, lst.end()) == 1 ? std::cout << ']' << std::endl : std::cout << ", ";
        }
        std::cout << "Searching '128':" << RESET << std::endl;

        std::cout << GREEN << easyfind< std::list<int> >(lst, 128) << RESET << std::endl;
    }
}