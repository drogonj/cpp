
#pragma once

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

class PmergeMe {
private:
    PmergeMe(const PmergeMe & src);
    PmergeMe & operator=(const PmergeMe & src);

    void vecSort(std::vector<int> & vec, int left, int right);
    void vecMerge(std::vector<int> & vec, int left, int middle, int right);
    void vecInsertion(std::vector<int> & vec, int left, int right);

    void lstSort(std::list<int> & lst, std::list<int>::iterator left, std::list<int>::iterator right);
    void lstMerge(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right);
    void lstInsertion(std::list<int> & lst, std::list<int>::iterator left, std::list<int>::iterator right);

public:
    PmergeMe(void);
    ~PmergeMe(void);

    void sort(std::vector<int> & vec);
    void sort(std::list<int> & lst);
};