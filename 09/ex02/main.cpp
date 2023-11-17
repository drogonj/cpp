
#include "PmergeMe.hpp"

static bool isArgsValid(char **args) {
    for (size_t arg = 0; args[arg]; arg++) {
        for (size_t i = 0; args[arg][i]; i++) {
            if (args[arg][i] < '0' || args[arg][i] > '9')
                return (false);
        }
    }
    return (true);
}

template<typename T>
bool isSorted(T & lst) {
    if (lst.size() <= 1)
        return true;
    typename T::iterator it = lst.begin();
    typename T::iterator prev = it;

    for (++it; it != lst.end(); ++it, ++prev) {
        if (*prev > *it) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << MAGENTA << "usage: \"./RPN 9 4 3 7 2\"" << RESET << std::endl;
        return (0);
    } else if (!isArgsValid(&argv[1])) {
        std::cout << YELLOW << "error: invalid character" << RESET << std::endl;
        return (-1);
    }
    argv = &argv[1];

    // Creating containers
    std::cout << BLUE << "Non-sorted integer sequence: " << GREEN;
    std::vector<int> vec;
    for (size_t arg = 0; argv[arg]; arg++) {
        std::cout << argv[arg] << " ";
        vec.push_back(atoi(argv[arg]));
    }
    std::cout << RESET << std::endl;
    std::list<int> lst;
    for (size_t arg = 0; argv[arg]; arg++) {
        lst.push_back(atoi(argv[arg]));
    }

    // Sorting vector
    PmergeMe sortVec;
    std::clock_t vecStart = std::clock();
    sortVec.sort(vec);
    std::clock_t vecEnd = std::clock();

    // Sorting list
    PmergeMe sortLst;
    std::clock_t lstStart = std::clock();
    sortLst.sort(lst);
    std::clock_t lstEnd = std::clock();

    // Showing sorted vector
    std::cout << BLUE << "Sorted vector: " << GREEN;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << RESET << std::endl;

    // Showing sorted list
    std::cout << BLUE << "Sorted list: " << GREEN;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << RESET << std::endl;

    // Showing that containers are sorted
    std::cout << BLUE << "Vector is sorted: " << GREEN << (isSorted(vec) ? "yes" : "no") << RESET << std::endl;
    std::cout << BLUE << "List is sorted: " << GREEN << (isSorted(lst) ? "yes" : "no") << RESET << std::endl;

    // Showing time to sort
    std::cout << MAGENTA << "Time to sort vector: " << GREEN << 1000.0 * (vecEnd - vecStart) / CLOCKS_PER_SEC << "ms" << RESET << std::endl;
    std::cout << MAGENTA << "Time to sort list: " << GREEN << 1000.0 * (lstEnd - lstStart) / CLOCKS_PER_SEC << "ms" << RESET << std::endl;

    return (0);
}